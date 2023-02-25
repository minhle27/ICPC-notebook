/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Max 1-D range sum, DP
 * Time: O(N^{2}) 
 * Status: 
 */

int n = 9, a[] = {4, -5, 4, -3, 4, 4, -4, 4, -5};
int sum = 0, ans = 0;
for (int i = 0; i < n; i++){
    sum += a[i];
    ans = max(ans, sum);
    if (sum < 0) sum = 0;
}