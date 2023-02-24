/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Coin exchange, DP, Returns number of ways we can exchange k using set of coins
 * Time:  
 * Status: 
 */

count[0] = 1;
const int MOD = 1e9;
for (int x = 1; x <= n; x++){
    for (auto c : coins){
        if (x - c >= 0){
            count[x] += count[x - c];
            count[x] %= MOD;
        }
    }
}