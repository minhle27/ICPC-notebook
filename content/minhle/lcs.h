/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Longest common substring, DP
 * Time: O(N^{2}) 
 * Status: 
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t, ans = "";
    cin >> s >> t;
    int m = s.length(), n = t.length(), init = max(m, n);

    for (int i = 0; i <= init; i++){
        dp[i][0] = 0; dp[0][i] = 0;
    }

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans += s[i - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string res = "";
    while (m != 0 && n != 0){
        if (s[m - 1] == t[n - 1]){
            res += s[m - 1]; m--; n--;
        }
        else if (dp[m][n] == dp[m - 1][n]){
            m--;
        }
        else{
            n--;
        }
    }

    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}