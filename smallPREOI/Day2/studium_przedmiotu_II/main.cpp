#include <vector>
#include <algorithm>

#include "stu2lib.h"
using namespace std;

vector<int> vec;

void inicjuj(vector<int> arr) {
    vec = arr;
}

void zamien(int a, int b) {
    swap(vec[a - 1], vec[b - 1]);
}

int odpowiedz(int a, int b) {
    vector<bool> stats(200007, false);
    for (int i = a - 1; i < b; i++) {
        stats[vec[i]] = true;
    }
    for (int i = 0; i < b - a + 2; i++){
        if(!stats[i]) return i;
    }
}