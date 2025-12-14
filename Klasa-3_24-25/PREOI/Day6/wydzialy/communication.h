/*
    communication.h - biblioteka do różnorakich zadań komunikacyjnych
    Autor: Kajetan Ramsza
    Ostatnia zmiana: 27.01.2025
*/
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <optional>
#include <random>
#include <tuple>
#include <variant>
#include <vector>

#ifndef __NOPASSWORD
extern const std::string_view PASSWORD;
#endif

extern const size_t PIPE_BUFFER_SIZE;
extern const int MESSAGE_LIMIT;

enum class messageType : int8_t { DATA, WAITING, ANSWER, EXIT, ACKNOWLEDGED };

constexpr std::string_view messageTypeName(messageType type) {
    switch (type) {
        case messageType::DATA:
            return "DATA";
        case messageType::WAITING:
            return "WAITING";
        case messageType::ANSWER:
            return "ANSWER";
        case messageType::EXIT:
            return "EXIT";
        case messageType::ACKNOWLEDGED:
            return "ACKNOWLEDGED";
    }
    return "INVALID_MESSAGE_TYPE";
}

enum childId : int8_t { CHILD_A = 0, CHILD_B = 1 };

constexpr childId STARTING_CHILD = CHILD_A;
constexpr childId otherChild(childId id) {
    if (id == CHILD_A) return CHILD_B;
    return CHILD_A;
}

extern const std::string_view CHILD_A_NAME;
extern const std::string_view CHILD_B_NAME;

std::string_view childName(childId id) {
    if (id == CHILD_A) return CHILD_A_NAME;
    return CHILD_B_NAME;
}

namespace ExitType {
constexpr std::string_view ERROR = "ERROR";
constexpr std::string_view ANSWER = "ANSWER";
}  // namespace ExitType

namespace ErrorType {
constexpr std::string_view COMMUNICATION_ERROR = "COMMUNICATION_ERROR";
constexpr std::string_view MESSAGE_LIMIT = "MESSAGE_LIMIT";
constexpr std::string_view BOTH_SENT = "BOTH_SENT";
constexpr std::string_view BOTH_WAIT = "BOTH_WAIT";
constexpr std::string_view MESSAGE_SENT_BUT_CHILD_EXITED = "MESSAGE_SENT_BUT_CHILD_EXITED";
constexpr std::string_view WAITING_FOR_MESSAGE_BUT_CHILD_EXITED = "WAITING_FOR_MESSAGE_BUT_CHILD_EXITED";
constexpr std::string_view BOTH_CHILDREN_EXITED_BUT_NO_ANSWER = "BOTH_CHILDREN_EXITED_BUT_NO_ANSWER";
constexpr std::string_view INVALID_MESSAGE_TYPE = "INVALID_MESSAGE_TYPE";
constexpr std::string_view CHILD_INVALID_EXIT = "CHILD_INVALID_EXIT";
constexpr std::string_view CHILD_SIGNALED = "CHILD_SIGNALED";
constexpr std::string_view BOTH_CHILDREN_ANSWERED_WITH_DIFFERENT_VALUES =
    "BOTH_CHILDREN_ANSWERED_WITH_DIFFERENT_VALUES";

const std::map<std::string_view, std::string_view> message = {
    {COMMUNICATION_ERROR, "Robisz coś bardzo bardzo dziwnego?"},
    {MESSAGE_LIMIT, "Limit przesyłanych wiadomości został przekroczony"},
    {BOTH_SENT, "Oba programy wysłały na raz wiadomość (musisz 'sparować' send i receive w obu programach)"},
    {BOTH_WAIT, "Oba programy oczekują na raz wiadomości (musisz 'sparować' send i receive w obu programach)"},
    {MESSAGE_SENT_BUT_CHILD_EXITED, "Wiadomość wysłana, ale drugi proces się już zakończył"},
    {WAITING_FOR_MESSAGE_BUT_CHILD_EXITED, "Oczekiwanie wiadomości, ale drugi proces się już zakończył"},
    {BOTH_CHILDREN_EXITED_BUT_NO_ANSWER, "Oba programy się zakończył, ale żaden nie wywołał funkcji answer"},
    {INVALID_MESSAGE_TYPE, "Robisz coś bardzo bardzo dziwnego?"},
    {CHILD_INVALID_EXIT,
     "Program (dziecka) zakończył się w nieoczekiwany sposób - wywołujesz na przykład komendę exit? (powyżej wskazane "
     "z jakim kodem został zakończony program)"},
    {CHILD_SIGNALED,
     "Program (dziecka) zakończył się sygnałem - runtime error. Powyżej wskazane które dziecko oraz kod błędu "
     "(analogicznie do błędu na sio 'Runtime error - signal X')"},
    {BOTH_CHILDREN_ANSWERED_WITH_DIFFERENT_VALUES, "Oba programy wywołały answer, ale z różnymi odpowiedziami"}};
}  // namespace ErrorType

class CommunicationError : public std::exception {};

template <typename DATA_TYPE, typename ANSWER_TYPE>
class Communication {
   public:
    void printExitMessage(const std::string_view &exitType, auto... messages) {
#ifndef __NOPASSWORD
        std::cout << PASSWORD << " ";
#endif
        std::cout << exitType;
        ((std::cout << ' ' << messages), ...) << std::endl;
    }

    void panic(const std::string_view &msg) {
        printExitMessage(ExitType::ERROR, msg);
        exit(1);
    }

    Communication() { createPipes(); }

   private:
    /* Będą trzy procesy: dwoje dzieci (child) i proces główny (master).
       Dzieci będą połączone pipe'ami z masterem`.*/
    int pipeToMaster[2][2], pipeFromMaster[2][2];

    void createPipes() {
        for (int child = 0; child < 2; child++) {
            int pipereturn = 0;
            pipereturn |= pipe(pipeToMaster[child]);
            pipereturn |= pipe(pipeFromMaster[child]);
            if (pipereturn != 0) panic("PIPE_FAILED");
        }
    }

    bool readAll(int fd, void *buf, size_t size);
    bool writeAll(int fd, const void *buf, size_t size);

    // Wait for child to exit and exit with error if it did
    // returns true - if child has exited
    bool master_checkChildStatus(childId id);

    void send(const void *arr, size_t size, childId child_id, bool toMaster);
    void receive(void *arr, size_t size, childId child_id, bool fromMaster);

    template <typename T>
    struct is_supported_type : std::conjunction<std::is_trivially_copyable<T>, std::negation<std::is_pointer<T>>> {};

    template <typename T>
    struct is_vector_of_supported_types : std::false_type {};

    template <typename T>
    struct is_vector_of_supported_types<std::vector<T>>
        : std::conditional_t<is_supported_type<T>::value, std::true_type, is_vector_of_supported_types<T>> {};

    template <typename T>
    std::enable_if_t<is_supported_type<T>::value, void> send(childId id, const T &x, bool toMaster) {
        send(&x, sizeof(x), id, toMaster);
    }

    template <typename T>
    std::enable_if_t<is_vector_of_supported_types<T>::value, void> send(childId id, const T &x, bool toMaster) {
        send(id, x.size(), toMaster);
        for (auto j : x) send(id, j, toMaster);
    }

    template <typename T>
    std::enable_if_t<is_supported_type<T>::value, T> receive(childId id, bool fromMaster) {
        T result;
        receive(&result, sizeof(result), id, fromMaster);
        return result;
    }

    template <typename T>
    std::enable_if_t<is_vector_of_supported_types<T>::value, T> receive(childId id, bool fromMaster) {
        auto s = receive<size_t>(id, fromMaster);
        T result(s);
        for (size_t i = 0; i < s; i++) result[i] = receive<typename T::value_type>(id, fromMaster);
        return result;
    }

   public:
    std::string printData(const DATA_TYPE &data);

    // ================================ MASTER ================================
   private:
    std::array<pid_t, 2> childPids;
    enum class childStatus : int8_t { RUNNING, MESSAGE_SENT, WAITING_FOR_MESSAGE, EXIT_WO_ANSWER, EXIT_WITH_ANSWER };
    constexpr std::string_view childStatusName(childStatus type) {
        switch (type) {
            case childStatus::RUNNING:
                return "RUNNING";
            case childStatus::MESSAGE_SENT:
                return "MESSAGE_SENT";
            case childStatus::WAITING_FOR_MESSAGE:
                return "WAITING";
            case childStatus::EXIT_WO_ANSWER:
                return "EXIT_WO_ANSWER";
            case childStatus::EXIT_WITH_ANSWER:
                return "EXIT_WITH_ANSWER";
        }
        return "INVALID_CHILD_STATUS";
    }

    void master_killChildren() {
        kill(childPids[0], SIGKILL);
        kill(childPids[1], SIGKILL);
    }

    void master_exitGracefully(const std::string_view &exitType, std::string_view errorType, auto... messages) {
        printExitMessage(exitType, errorType, messages..., "\n" + (std::string)ErrorType::message.at(errorType));
        master_killChildren();
        exit(0);
    }

    void master_configurePipes();

   public:
    void forkAndRunChildren();
    std::tuple<ANSWER_TYPE, int, size_t> masterMain();

    // ================================ CHILD ================================
   private:
    childId currentId;

    void closeUnusedPipes(childId id);

    void waitForAcknowledgment();

    void runA();
    void runB();

    void childMain(childId id);

   public:
    void userSend(DATA_TYPE data);
    DATA_TYPE userReceive();

    void answer(ANSWER_TYPE x);
};

template <typename D, typename A>
bool Communication<D, A>::readAll(int fd, void *buf, size_t size) {
    size_t bytes = 0;
    while (bytes < size) {
        long long ret = read(fd, (char *)buf + bytes, size - bytes);
        if (ret == 0)
            return false;
        else if (ret < 0)
            throw CommunicationError();
        bytes += ret;
    }
    return true;
}

template <typename D, typename A>
bool Communication<D, A>::writeAll(int fd, const void *buf, size_t size) {
    size_t bytes = 0;
    while (bytes < size) {
        long long ret = write(fd, (char *)buf + bytes, size - bytes);
        if (ret == 0)
            return false;
        else if (ret < 0)
            throw CommunicationError();
        bytes += ret;
    }
    return true;
}

template <typename D, typename A>
void Communication<D, A>::send(const void *arr, size_t size, childId child_id, bool toMaster) {
    size_t sent = 0;
    if (toMaster) {
        if (!writeAll(pipeToMaster[child_id][1], (char *)arr + sent, size)) throw CommunicationError();
    } else if (!writeAll(pipeFromMaster[child_id][1], (char *)arr + sent, size)) {
        if (!master_checkChildStatus(child_id)) throw CommunicationError();
    }
}

template <typename D, typename A>
void Communication<D, A>::receive(void *arr, size_t size, childId child_id, bool fromMaster) {
    size_t received = 0;
    if (fromMaster) {
        if (!readAll(pipeFromMaster[child_id][0], (char *)arr + received, size)) throw CommunicationError();
    } else if (!readAll(pipeToMaster[child_id][0], (char *)arr + received, size)) {
        if (!master_checkChildStatus(child_id)) throw CommunicationError();
    }
}

template <typename D, typename A>
void Communication<D, A>::master_configurePipes() {
    for (int child = 0; child < 2; child++) {
        fcntl(pipeToMaster[child][0], F_SETPIPE_SZ, PIPE_BUFFER_SIZE);
        fcntl(pipeFromMaster[child][1], F_SETPIPE_SZ, PIPE_BUFFER_SIZE);

        close(pipeToMaster[child][1]);
        close(pipeFromMaster[child][0]);
    }
}

template <typename D, typename A>
bool Communication<D, A>::master_checkChildStatus(childId id) {
    int status;
    int ret = waitpid(childPids[id], &status, 0);
    if (ret > 0) {
        if (WIFEXITED(status))
            master_exitGracefully(ExitType::ERROR, ErrorType::CHILD_INVALID_EXIT, childName(id), status / 256);
        else if (WIFSIGNALED(status))
            master_exitGracefully(ExitType::ERROR, ErrorType::CHILD_SIGNALED, childName(id), WTERMSIG(status));
        return true;
    }
    return false;
}

template <typename D, typename A>
void Communication<D, A>::forkAndRunChildren() {
    constexpr std::array<childId, 2> children = {{CHILD_A, CHILD_B}};

    for (auto child : children) {
        pid_t pid = fork();
        if (pid < 0) {
            panic("FORK_FAILED");
        }
        if (pid == 0) {
            childMain(child);
            exit(0);
        }
        childPids[child] = pid;
    }
}

template <typename DATA_TYPE, typename ANSWER_TYPE>
std::tuple<ANSWER_TYPE, int, size_t> Communication<DATA_TYPE, ANSWER_TYPE>::masterMain() {
    assert(childPids[0] != 0 && childPids[1] != 0 && "before masterMain run forkAndRunChildren");

    using std::cin;
    master_configurePipes();

    childId running_child = STARTING_CHILD;
    int messages = 0;
    size_t max_message_size = 0;
    std::optional<ANSWER_TYPE> optional_answer;

    std::array<childStatus, 2> status{childStatus::RUNNING};

    for (; messages <= MESSAGE_LIMIT;) {
        auto type = receive<messageType>(running_child, false);

#ifdef __DEBUG_COMMUNICATION
        std::cerr << messages << ". ";
        std::cerr << childName(CHILD_A) << "(" << std::setw(12) << childStatusName(status[CHILD_A]) << ") ";
        std::cerr << childName(CHILD_B) << "(" << std::setw(12) << childStatusName(status[CHILD_B]) << ") ";
        std::cerr << "-- " << childName(running_child) << " sent message type " << messageTypeName(type) << std::endl;
#endif

        switch (type) {
            case messageType::DATA:
                if (status[otherChild(running_child)] == childStatus::MESSAGE_SENT)
                    master_exitGracefully(ExitType::ERROR, ErrorType::BOTH_SENT);
                if (status[otherChild(running_child)] == childStatus::EXIT_WO_ANSWER)
                    master_exitGracefully(ExitType::ERROR, ErrorType::MESSAGE_SENT_BUT_CHILD_EXITED);

                if (status[otherChild(running_child)] != childStatus::WAITING_FOR_MESSAGE)
                    status[running_child] = childStatus::MESSAGE_SENT;

                messages++;

                {
                    auto data = receive<DATA_TYPE>(running_child, false);
#ifdef __DEBUG_COMMUNICATION
                    std::cerr << "DATA SENT: " << printData(data) << std::endl;
#endif
                    if constexpr (is_vector_of_supported_types<DATA_TYPE>::value) {
                        max_message_size = std::max(max_message_size, data.size());
                    }
                    send(otherChild(running_child), messageType::DATA, false);
                    send(otherChild(running_child), data, false);
                }

                status[otherChild(running_child)] = childStatus::RUNNING;
                break;
            case messageType::WAITING:
                if (status[otherChild(running_child)] == childStatus::WAITING_FOR_MESSAGE)
                    master_exitGracefully(ExitType::ERROR, ErrorType::BOTH_WAIT);
                if (status[otherChild(running_child)] == childStatus::EXIT_WO_ANSWER)
                    master_exitGracefully(ExitType::ERROR, ErrorType::WAITING_FOR_MESSAGE_BUT_CHILD_EXITED);

                if (status[otherChild(running_child)] != childStatus::MESSAGE_SENT)
                    status[running_child] = childStatus::WAITING_FOR_MESSAGE;
                send(otherChild(running_child), messageType::WAITING, false);
                status[otherChild(running_child)] = childStatus::RUNNING;
                break;
            case messageType::ANSWER:
                optional_answer = receive<ANSWER_TYPE>(running_child, false);
                send(running_child, messageType::ACKNOWLEDGED, false);
                status[running_child] = childStatus::EXIT_WITH_ANSWER;
                break;
            case messageType::EXIT:
                if (status[otherChild(running_child)] == childStatus::MESSAGE_SENT)
                    master_exitGracefully(ExitType::ERROR, ErrorType::MESSAGE_SENT_BUT_CHILD_EXITED);
                if (status[otherChild(running_child)] == childStatus::WAITING_FOR_MESSAGE)
                    master_exitGracefully(ExitType::ERROR, ErrorType::WAITING_FOR_MESSAGE_BUT_CHILD_EXITED);
                send(running_child, messageType::ACKNOWLEDGED, false);
                status[running_child] = childStatus::EXIT_WO_ANSWER;
                break;
            default:
                master_exitGracefully(ExitType::ERROR, ErrorType::INVALID_MESSAGE_TYPE);
        }

        if (std::any_of(status.begin(), status.end(),
                        [](const childStatus &x) { return x == childStatus::EXIT_WITH_ANSWER; }) ||
            std::all_of(status.begin(), status.end(),
                        [](const childStatus &x) { return x == childStatus::EXIT_WO_ANSWER; })) {
            break;
        }

        if (status[otherChild(running_child)] != childStatus::EXIT_WO_ANSWER) running_child = otherChild(running_child);
    }

    if (messages > MESSAGE_LIMIT) {
        master_exitGracefully(ExitType::ERROR, ErrorType::MESSAGE_LIMIT);
    }
    if (!optional_answer.has_value()) {
        master_exitGracefully(ExitType::ERROR, ErrorType::BOTH_CHILDREN_EXITED_BUT_NO_ANSWER);
    }

    auto answer = optional_answer.value();

    // check if the other child also answered - if so, check if answer is the same
    if (status[otherChild(running_child)] == childStatus::RUNNING) {
        auto type = receive<messageType>(otherChild(running_child), false);
        if (type == messageType::ANSWER) {
            auto other_answer = receive<ANSWER_TYPE>(otherChild(running_child), false);
            if (!(answer == other_answer))
                master_exitGracefully(ExitType::ERROR, ErrorType::BOTH_CHILDREN_ANSWERED_WITH_DIFFERENT_VALUES);
        }
    }

    master_killChildren();
    return {answer, messages, max_message_size};
}

template <typename D, typename A>
void Communication<D, A>::closeUnusedPipes(childId id) {
    close(pipeFromMaster[1 - id][0]);
    close(pipeFromMaster[1 - id][1]);
    close(pipeToMaster[1 - id][0]);
    close(pipeToMaster[1 - id][1]);
    close(pipeToMaster[id][0]);
    close(pipeFromMaster[id][1]);
}

template <typename DATA_TYPE, typename ANSWER_TYPE>
void Communication<DATA_TYPE, ANSWER_TYPE>::waitForAcknowledgment() {
    auto status = receive<messageType>(currentId, true);
    // allow WAITING and DATA status, because other process can expect data or send data
    if (status == messageType::DATA) receive<DATA_TYPE>(currentId, true);
    if (status == messageType::WAITING || status == messageType::DATA) status = receive<messageType>(currentId, true);
    assert(status == messageType::ACKNOWLEDGED);
    exit(0);
}

template <typename D, typename A>
void Communication<D, A>::childMain(childId id) {
    currentId = id;
    closeUnusedPipes(currentId);
    switch (currentId) {
        case CHILD_A:
            runA();
            break;
        case CHILD_B:
            runB();
            break;
    }
    send(currentId, messageType::EXIT, true);
    waitForAcknowledgment();
}

template <typename DATA_TYPE, typename ANSWER_TYPE>
void Communication<DATA_TYPE, ANSWER_TYPE>::userSend(DATA_TYPE data) {
    send(currentId, messageType::DATA, true);
    send(currentId, data, true);
    auto status = receive<messageType>(currentId, true);
    assert(status == messageType::WAITING);
}

template <typename DATA_TYPE, typename ANSWER_TYPE>
DATA_TYPE Communication<DATA_TYPE, ANSWER_TYPE>::userReceive() {
    send(currentId, messageType::WAITING, true);
    auto status = receive<messageType>(currentId, true);
    assert(status == messageType::DATA);
    auto data = receive<DATA_TYPE>(currentId, true);
    return data;
}

template <typename DATA_TYPE, typename ANSWER_TYPE>
void Communication<DATA_TYPE, ANSWER_TYPE>::answer(ANSWER_TYPE x) {
    send(currentId, messageType::ANSWER, true);
    send(currentId, x, true);
    waitForAcknowledgment();
}
