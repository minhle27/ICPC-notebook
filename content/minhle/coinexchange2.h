/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Coin exchange, DP, Returns minimum number of coins we can exchange k using set of coins
 * Time:  
 * Status: 
 */

// value[x] is the ans for exchanging x
value[0] = 0;
for (int x = 1; x <= n; x++){
    value[x] = INF;
    for (auto c : coins){
        if (x - c >= 0 && value[x - c] + 1 < value[x]){
            value[x] = value[x - c] + 1;
            first[x] = c; // used to trace back answer
        }
    }
}

// trace back
while(n > 0){
    cout << first[n] << endl;
    n -= first[n];
}