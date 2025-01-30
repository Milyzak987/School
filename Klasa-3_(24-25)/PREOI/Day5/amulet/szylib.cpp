#include "szylib.h"

#include "communication.h"

// ============ CONFIG ============
typedef std::vector<std::vector<int>> DATA_TYPE;
typedef int ANSWER_TYPE;

constexpr size_t PIPE_BUFFER_SIZE = 1048576;
constexpr int MESSAGE_LIMIT = 1048576;

constexpr std::string_view CHILD_A_NAME = "Encoder";
constexpr std::string_view CHILD_B_NAME = "Decoder";
// ============ END CONFIG ============

using Comm = Communication<DATA_TYPE, ANSWER_TYPE>;

namespace {

Comm com;

int q;
std::vector<std::pair<int, int>> blocked;
std::vector<std::string> to_encode;

int blocked_row, blocked_column;
std::string S;
int NumCall;

int oznacz_answerCode = 0;

std::vector<std::vector<int>> ciphered_matrix;
std::vector<int> CountList[20];

void readInput() {
  std::cin >> q;
  blocked.resize(q);
  to_encode.resize(q);
  for (int i = 0; i < q; i++) {
    int sz;
    std::cin >> blocked[i].first >> blocked[i].second >> sz >> to_encode[i];
  }
}

std::vector<std::vector<int>> CallInteractor(std::vector<std::vector<int>> T,
                                             int X, int Y, int casenum) {
  (void)casenum;
  for (int i = 0; i < X; i++) {
    T[X][i] = rand() % 2;
    T[i][Y] = rand() % 2;
  }
  return T;
}

void oznacz_answer(int x) {
  if (oznacz_answerCode == 0)
    oznacz_answerCode = x;
}
} // namespace

std::string printData(const DATA_TYPE &data) {
  std::stringstream s;
  for (const auto &x : data) {
    for (const auto &y : x) {
      s << ' ' << y;
    }
    s << '\n';
  }
  return s.str();
}

void Oznacz(int a, int b, int c) {
  // std::cerr<<a<<' '<<b<<' '<<blocked_row<<' '<<blocked_column<<'\n';
  if (a < 0 || a > 7 || a == blocked_row)
    oznacz_answer(-1);
  if (b < 0 || b > 7 || b == blocked_column)
    oznacz_answer(-1);
  if (c < 0 || c > 1)
    oznacz_answer(-2);
  if (ciphered_matrix[a][b] != 2)
    oznacz_answer(-3);
  ciphered_matrix[a][b] = c;
  NumCall += 1;
}

template <> void Comm::runA() {
  // uruchamiam encode
  for (int queryNo = 0; queryNo < q; queryNo++) {
    NumCall = 0;
    oznacz_answerCode = 0;
    blocked_row = blocked[queryNo].first;
    blocked_column = blocked[queryNo].second;
    S = to_encode[queryNo];

    ciphered_matrix.resize(8);
    for (int i = 0; i < 8; i++) {
      ciphered_matrix[i].resize(8);
      for (int j = 0; j < 8; j++)
        ciphered_matrix[i][j] = 2;
    }

    Zaszyfruj(blocked_row, blocked_column, (int)S.size(), S);

    // std::cerr<<oznacz_answerCode<<'\n';
    if (oznacz_answerCode != 0)
      answer(oznacz_answerCode);

    if (NumCall != 49)
      answer(-4);

    std::vector<std::vector<int>> changed_matrix =
        CallInteractor(ciphered_matrix, blocked_row, blocked_column, queryNo);

    userSend(ciphered_matrix);
  }
}

template <> void Comm::runB() {
  int CurrentMaxL = 43;
  for (int queryNo = 0; queryNo < q; queryNo++) {
    S = to_encode[queryNo];

    DATA_TYPE changed_matrix = com.userReceive();
    std::string ans =
        Odszyfruj((int)S.size(), (std::vector<std::vector<int>>)changed_matrix);
    if ((int)ans.size() > 43)
      answer(-5);
    for (int i = 0; i < (int)ans.size(); i++) {
      if (ans[i] != 'A' && ans[i] != 'B')
        answer(-6);
    }

    if (ans != S) {
      CurrentMaxL = std::min(CurrentMaxL, (int)S.size() - 1);
    }
  }

  answer(CurrentMaxL);
}

int main() {
  srand(13420);

  // Init
  for (int i = 0; i < 32768; i++) {
    int Popcnt = 0;
    for (int j = 0; j < 15; j++) {
      if ((i & (1 << j)) != 0)
        Popcnt += 1;
    }
    CountList[Popcnt].push_back(i);
  }
  readInput();

  com.forkAndRunChildren();

  try {
    auto [answer, _, message_length] = com.masterMain();
    if (answer < 0) {
      com.printExitMessage(ExitType::ERROR, "ANSWER_ERROR_CODE", -answer,
                           "\nKody błędów opisane są w treści");
      return 0;
    }
    com.printExitMessage(ExitType::ANSWER, answer);
  } catch (const CommunicationError &e) {
    com.panic(ErrorType::COMMUNICATION_ERROR);
  }
  return 0;
}
