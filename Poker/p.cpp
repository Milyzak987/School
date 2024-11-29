#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Card {
    int value, suite;
};

void collectNumbers(const vector<int>& hand);
void organizeCards();
bool straight();
bool flush(const vector<int>& suits);
int ofaKind();
bool pairs();
int handRank(const vector<int>& hand, const vector<int>& suits);
int playPoker(const vector<int>& hand1, const vector<int>& hand2);
int compareRank(int, int);
int compareHands(int, int, int, int);
int cardNumArray[5] = {}, handHigh = 0, totalHigh = 0;

int win(Card h1[], Card h2[]) {
    vector<int> hand1(10), hand2(10);

    for (int i = 0; i < 5; i++) {
        hand1[i * 2 - 1] = h1[i].value;
        hand1[i * 2] = h1[i].suite;
    }
    for (int i = 0; i < 5; i++) {
        hand2[i * 2 - 1] = h2[i].value;
        hand2[i * 2] = h2[i].suite;
    }

    return playPoker(hand1, hand2);
}

void collectNumbers(const vector<int>& hand) {
    for (int i = 0; i < 5; ++i) {
        cardNumArray[i] = hand[i * 2];  // Extract ranks
    }
    organizeCards();
    totalHigh = *max_element(cardNumArray, cardNumArray + 5);
}

void organizeCards() {
    sort(cardNumArray, cardNumArray + 5);
}

bool straight() {
    for (int i = 0; i < 4; ++i) {
        if (cardNumArray[i] + 1 != cardNumArray[i + 1]) {
            return cardNumArray[0] == 2 && cardNumArray[4] == 14 && cardNumArray[3] == 5;  // Special case: 2, 3, 4, 5, A
        }
    }
    return true;
}

bool flush(const vector<int>& suits) {
    return all_of(suits.begin(), suits.end(), [&](int s) { return s == suits[0]; });
}

int ofaKind() {
    int count[15] = {};
    for (int num : cardNumArray) count[num]++;
    for (int i = 14; i >= 2; --i) {
        if (count[i] == 4) {
            handHigh = i;
            return 7;
        }  // Four of a Kind
        if (count[i] == 3) {
            handHigh = i;
            return 3;
        }  // Three of a Kind
    }
    return 0;
}

bool pairs() {
    int count[15] = {};
    for (int num : cardNumArray) count[num]++;
    int pairCount = 0;
    for (int i = 14; i >= 2; --i) {
        if (count[i] == 2) {
            handHigh = max(handHigh, i);
            pairCount++;
        }
    }
    return pairCount > 0;
}

int handRank(const vector<int>& hand, const vector<int>& suits) {
    bool flushTrue = flush(suits);
    if (straight()) return flushTrue ? (cardNumArray[0] == 10 ? 9 : 8) : 4;  // Straight, Straight Flush, Royal Flush
    if (flushTrue) return 5;                                                 // Flush
    int kind = ofaKind();
    if (kind == 7) return 7;                 // Four of a Kind
    if (kind == 3) return pairs() ? 6 : 3;   // Full House or Three of a Kind
    return pairs() ? (pairs() ? 2 : 1) : 0;  // Two Pair or One Pair
}

int playPoker(const vector<int>& hand1, const vector<int>& hand2) {
    vector<int> suits1(5), suits2(5);
    for (int i = 0; i < 5; ++i) {
        suits1[i] = hand1[i * 2 + 1];
        suits2[i] = hand2[i * 2 + 1];
    }

    collectNumbers(hand1);
    int rank1 = handRank(hand1, suits1);
    int handHigh1 = handHigh, totalHigh1 = totalHigh;

    collectNumbers(hand2);
    int rank2 = handRank(hand2, suits2);
    int handHigh2 = handHigh, totalHigh2 = totalHigh;

    int winner = compareRank(rank1, rank2);
    if (winner == 3) return compareHands(handHigh1, totalHigh1, handHigh2, totalHigh2);
    return winner;
}

int compareRank(int rank1, int rank2) {
    return rank1 > rank2 ? 1 : rank2 > rank1 ? 2
                                             : 3;
}

int compareHands(int handHigh1, int totalHigh1, int handHigh2, int totalHigh2) {
    if (handHigh1 > handHigh2) return 1;
    if (handHigh2 > handHigh1) return 2;
    return totalHigh1 > totalHigh2 ? 1 : 2;
}
