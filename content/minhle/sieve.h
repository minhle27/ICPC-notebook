/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Sieve of Eratosthenes
 * Time: O(N\log N)
 * Status: 
 */

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

