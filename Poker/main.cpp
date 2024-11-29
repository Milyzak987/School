#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

struct Card {
    int value, suite;
};

const int MAXN = 1e6;

vector<Card> deck;

Card hands[10][2];
Card table[5];

Card best[10][5];
Card combined[7];

bool compCards(Card a, Card b) {
    if (a.value == b.value && a.suite == b.suite) return true;
    return false;
}

void comb(int player) {
    string bitmask(5, 1);
    bitmask.resize(7, 0);

    int j = 0;
    do {
        Card cur[5];
        for (int i = 0; i < 7; ++i) {
            if (bitmask[i]) {
                cur[j] = combined[i];
                j++;
            }
        }
        j = 0;
        // do something here if(cur > best) best = cur
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}

void earaseCard(Card c) {
    for (int i = 0; i < deck.size(); i++) {
        if (compCards(c, deck[i])) {
            deck.erase(deck.begin() + i);
        }
    }
}

void genDeck() {
    for (int i = 0; i < 52; ++i) {
        Card d;
        d.suite = (i % 4) + 1;
        d.value = (i % 13) + 2;
        deck.push_back(d);
    }
}

Card convertHand(string v, char s) {
    string values[14] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char suites[4] = {'T', 'K', 'I', 'P'};
    Card c;
    for (int i = 0; i < 14; i++) {
        if (v == values[i]) {
            c.value = i + 2;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (s == suites[i]) {
            c.suite = i + 1;
        }
    }
    earaseCard(c);
    return c;
}

Card randCard() {
    random_device random_device;
    mt19937 engine{random_device()};
    uniform_int_distribution<int> dist(0, deck.size() - 1);
    Card random_element = deck[dist(engine)];
    earaseCard(random_element);
    return random_element;
}

int main() {
    genDeck();
    string v1, v2;
    char s1, s2;
    cout << "Podaj swoje karty: ";
    cin >> v1 >> s1 >> v2 >> s2;
    hands[0][0] = convertHand(v1, s1);
    hands[0][1] = convertHand(v2, s2);

    int tableCards = 0;
    cout << "\nPodaj ile jest kart na stole:";
    cin >> tableCards;
    for (int i = 0; i < tableCards; i++) {
        string v;
        char s;
        cin >> v >> s;
        table[i] = convertHand(v, s);
    }

    int players = 0;
    cout << "\nPodaj ile jest graczy:";
    cin >> players;

    for (int i = 0; i < MAXN; i++) {
        for (int ii = tableCards; ii < 5; ii++) {
            table[ii] = randCard();
        }
        for (int ii = 1; ii < players; ii++) {
            hands[ii][0] = randCard();
            hands[ii][1] = randCard();
        }

        for (int ii = 0; ii < players; ii++) {
            for (int iii = 0; iii < 5; iii++) {
                best[ii][iii] = table[iii];
            }
            for (int iii = 0; iii < 5; iii++) {
                combined[iii] = table[iii];
            }
            combined[5] = hands[ii][0];
            combined[6] = hands[ii][1];
            comb(ii);
        }

        for (int ii = 1; ii < players; ii++) {
            // if(best[0] < best[ii]) return false
        }
    }

    // cout << hands[0][0].value << " " << hands[0][0].suite << " - " << hands[0][1].value << " " << hands[0][1].suite << "\n";
    // for (auto x : deck) {
    //     cout << x.suite << " " << x.value << "\n";
    // }

    // for (int i = 0; i < players; i++) {
    //     cout << hands[i][0].value << " " << hands[i][0].suite << " - " << hands[i][1].value << " " << hands[i][1].suite << "\n";
    // }
    // for(int i = 0; i < 5; i++){
    //     cout << table[i].value << " " << table[i].suite << " - ";
    // }
}