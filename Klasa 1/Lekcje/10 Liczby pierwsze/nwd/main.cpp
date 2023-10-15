#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;

    int g = 0;
    std::cin >> g;

    for (int i = 1; i < n; i++) {
        int x;
        std::cin >> x;
        g = gcd(g, x);
    }

    std::cout << g << std::endl;

    return 0;
}