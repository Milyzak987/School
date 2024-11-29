#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "poker.h"

using namespace std;

struct Card {
    int value, suite;
};

bool taken[52];
Card deck[52];
Card hands[10][2];
Card table[5];
Card combined[7];
Card best[5];

bool compCards(Card a, Card b) {
    if (a.value == b.value && a.suite == b.suite) return true;
    return false;
}

void comb() {
    string bitmask(5, 1);
    bitmask.resize(7, 0);

    int j = 0;
    do {
        for (int i = 0; i < 7; ++i) {
            if (bitmask[i]) {
                best[j] = combined[i];
                j++;
            }
        }
        j = 0;
        // do something here
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}

void genDeck() {
    for (int i = 0; i < 52; ++i) {
        deck[i].suite = (i % 4) + 1;
        deck[i].value = (i % 13) + 2;
        if (compCards(hands[0][0], deck[i]) || compCards(hands[0][1], deck[i])) taken[i] = true;
    }
}

void convertHand(string v1, string v2, char s1, char s2) {
    string values[14] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char suites[4] = {'T', 'K', 'I', 'P'};
    for (int i = 0; i < 14; i++) {
        if (v1 == values[i]) {
            hands[0][0].value = i + 2;
        }
    }
    for (int i = 0; i < 14; i++) {
        if (v2 == values[i]) {
            hands[0][1].value = i + 2;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (s1 == suites[i]) {
            hands[0][0].suite = i + 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (s2 == suites[i]) {
            hands[0][1].suite = i + 1;
        }
    }
}

int main() {
    string v1, v2;
    char s1, s2;
    cin >> v1 >> s1 >> v2 >> s2;
    convertHand(v1, v2, s1, s2);
    // cout << hands[0][0].value << " " << hands[0][0].suite << " - " << hands[0][1].value << " " << hands[0][1].suite << "\n";
    genDeck();
    // for (int i = 0 ; i < 52 ;  i++){
    //     cout << deck[i].suite << " " << deck[i].value << " " << taken[i] << "\n";
    // }
}