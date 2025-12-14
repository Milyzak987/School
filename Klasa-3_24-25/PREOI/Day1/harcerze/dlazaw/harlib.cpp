#include "harlib.h"

#include "communication.h"

#include <queue>

namespace {

int n, m, a, b, s;
std::vector<int>U, V;
void readInput() {
    std::cin >> n >> m >> a >> b >> s;
    U.resize(m);
    V.resize(m);
    for(int i = 0; i < m; ++i) {
        std::cin >> U[i] >> V[i];
    }
}

}  // namespace

std::string printData(const DATA_TYPE &data) {
    std::stringstream s;
    for (const auto &x : data) s << ' ' << x;
    return s.str();
}


template <>
void Child::run<CHILD_A>() {
    // uruchamiam encode
    DATA_TYPE edge_colors = Pomaluj(n, m, a, b, U, V);

    if((int) edge_colors.size() != m) {
        answer(1);
    }

    for(auto i : edge_colors) {
        if(i < 0 || i >= a) {
            answer(2);
        }
    }

    userSend(edge_colors);
}

template <>
void Child::run<CHILD_B>() {
    DATA_TYPE edge_colors = userReceive<DATA_TYPE>();

    std::vector<std::vector<int>> neighbour(n), color(n);

    for(int i = 0; i < m; ++i) {
        neighbour[U[i]].push_back(V[i]);
        neighbour[V[i]].push_back(U[i]);
        color[U[i]].push_back(edge_colors[i]);
        color[V[i]].push_back(edge_colors[i]);
    }

    std::vector<int>dist(n, -1);
    dist[0] = b;
    std::queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int p = q.front(); q.pop();
        for(int i = 0; i < (int)neighbour[p].size(); ++i) {
            if(dist[ neighbour[p][i] ] == -1) {
                dist[ neighbour[p][i] ] = dist[p] + 1;
                q.push(neighbour[p][i]);
            }
        }
    }

    int steps = dist[s];
    int current = s;
    int previous = -1;

    while(current != 0) {

        --steps;
        if(steps < 0) {
            answer(3);
        }

        std::vector<int> cnt(a);

        for(int i = 0; i < (int)neighbour[current].size(); ++i) {
            if(neighbour[current][i] != previous) {
                ++cnt[color[current][i]];
            }
        }

        int next = Rusz(cnt);

        if(next == -1) {
            if(previous == -1) {
                answer(4);
            }

            std::swap(current, previous);
            continue;
        }

        if(next < -1 || next >= a) {
            answer(5);
        }

        if(cnt[next] == 0) {
            answer(6);
        }

        for(int i = 0; i < (int)neighbour[current].size(); ++i) {
            if(color[current][i] == next && neighbour[current][i] != previous) {
                previous = current;
                current = neighbour[current][i];
                break;
            }
        }

    }

    answer(0);
}

int main() {
    readInput();

    createPipes();
    forkAndRunChildren();

    try {
        auto [answer, _, message_length] = Master::masterMain();
        if(answer) {
            printExitMessage(ExitType::ERROR, "WRONG ANSWER: ", answer);
            return 0;
        }
        printExitMessage(ExitType::ANSWER, 1);
    } catch (const CommunicationError &e) {
        panic(ErrorType::COMMUNICATION_ERROR);
    }
    return 0;
}
