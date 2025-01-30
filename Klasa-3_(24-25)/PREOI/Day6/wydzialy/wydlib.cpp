#include "wydlib.h"

#include "communication.h"

// ============ CONFIG ============
typedef std::vector<std::array<int, 9>> DATA_TYPE;
typedef int ANSWER_TYPE;

constexpr size_t PIPE_BUFFER_SIZE = 1048576;
constexpr int MESSAGE_LIMIT = 1048576;

constexpr std::string_view CHILD_A_NAME = "Bitek";
constexpr std::string_view CHILD_B_NAME = "Bajtazar";
// ============ END CONFIG ============

using Comm = Communication<DATA_TYPE, ANSWER_TYPE>;

namespace {

Comm com;

struct TestCase {
    int n;
    std::array<int, K> A, B;
    int a, b;
};

int Q;
std::vector<TestCase> tests;

void readInput() {
    std::cin >> Q;
    tests.resize(Q);
    for (auto &test : tests) {
        std::cin >> test.n;
        for (int i = 0; i < K; i++) std::cin >> test.A[i] >> test.B[i];
        std::cin >> test.a >> test.b;
    }
}

}  // namespace

template <>
std::string Comm::printData(const DATA_TYPE &) {
    return "NOT IMPLEMENTED";
}

template <>
void Comm::runA() {
    int index = 0, max_value = 0;
    std::vector<std::array<int, 9>> sasiedzi(Q);
    for (const auto &test : tests) {
        auto plansza = Bitek(test.n, test.A, test.B);
        if ((int)plansza.size() != test.n) com.answer(-1);
        for (int i = 0; i < test.n; i++)
            if ((int)plansza[i].size() != test.n) com.answer(-1);

        for (int i = 0; i < test.n; i++)
            for (int j = 0; j < test.n; j++)
                if (plansza[i][j] < 1 || plansza[i][j] > 1000000000) com.answer(-2);

        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                sasiedzi[index][(i + 1) * 3 + j + 1] = plansza[test.a + i][test.b + j];

        for (const auto &row : plansza)
            for (const auto &x : row) max_value = std::max(max_value, x);
        index++;
    }
    sasiedzi.push_back(std::array<int, 9>{max_value});
    userSend(sasiedzi);
}

template <>
void Comm::runB() {
    auto sasiedzi = userReceive();
    int index = 0;
    for (const auto &test : tests) {
        auto odpowiedzi = Bajtazar(sasiedzi[index]);

        for (int i = 0; i < K; i++)
            if (odpowiedzi[i] < 0 || odpowiedzi[i] > 4) com.answer(-3);

        for (int i = 0; i < K; i++) {
            if (odpowiedzi[i] == 0 && test.B[i] <= test.b) com.answer(-4);
            if (odpowiedzi[i] == 1 && test.B[i] >= test.b) com.answer(-4);
            if (odpowiedzi[i] == 2 && test.A[i] <= test.a) com.answer(-4);
            if (odpowiedzi[i] == 3 && test.A[i] >= test.a) com.answer(-4);
            if (odpowiedzi[i] == 4 && (test.A[i] != test.a || test.B[i] != test.b)) com.answer(-4);
        }
        index++;
    }
    const int max_value = sasiedzi.back()[0];
    com.answer(max_value);
    index++;
}

int main() {
    readInput();

    com.forkAndRunChildren();

    try {
        auto [answer, _1, _2] = com.masterMain();
        if (answer < 0) {
            com.printExitMessage(ExitType::ERROR, "WRONG_ANSWER", -answer);
            return 0;
        }
        com.printExitMessage(ExitType::ANSWER, answer);
    } catch (const CommunicationError &e) {
        com.panic(ErrorType::COMMUNICATION_ERROR);
    }
    return 0;
}
