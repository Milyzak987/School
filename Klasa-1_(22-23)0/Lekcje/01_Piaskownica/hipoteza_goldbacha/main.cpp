#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 1000001;
const int MAX_PRIMES = 80000;

vector<bool> isPrime(MAXN, true);
vector<int> primes(MAX_PRIMES);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    int primeCount = 0;
    
    for (int i = 2; i * i <= MAXN; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                isPrime[j] = false;
            }
            primes[primeCount++] = i;
        }
    }
    
    for (int i = 2; i <= MAXN && primeCount < MAX_PRIMES; ++i) {
        if (isPrime[i]) {
            primes[primeCount++] = i;
        }
    }
}

pair<int, int> findPrimesForSum(int a) {
    pair<int, int> result;
    int minDifference = a;
    
    for (int i = 0; i < primes.size(); ++i) {
        int prime1 = primes[i];
        int prime2 = a - prime1;
        
        if (prime2 >= 2 && isPrime[prime2] && abs(prime1 - prime2) < minDifference) {
            minDifference = abs(prime1 - prime2);
            result.first = prime1;
            result.second = prime2;
        }
    }
    
    return result;
}

int main() {
    sieve();
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        
        pair<int, int> primes = findPrimesForSum(a);
        cout << primes.first << " " << primes.second << endl;
    }
    
    return 0;
}