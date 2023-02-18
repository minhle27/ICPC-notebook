/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Sieve of Eratosthenes
 * Time: O(N\log N)
 * Status: 
 */

// find all prime number in range [1, N]
void sieve(int N) {
    bool isPrime[N+1];
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
            for(int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
}

// find all prime number in range [L, R]
vector<bool> isPrime(R - L + 1, true);  // x is prime <=> isPrime[x - l] == true

for (long long i = 2; i * i <= R; ++i) {
    for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
        isPrime[j - L] = false;
    }
}

if (1 >= L) {  // case number 1
    isPrime[1 - L] = false;
}

for (long long x = L; x <= R; ++x) {
    if (isPrime[x - L]) {
        // i is prime
    }
}

