/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Longest range that has sum divisible by k, DP
 * Time: 
 * Status: 
 */

int sub(int a, int b){
    int res = (a - b) % k;
    if (res >= 0) return res;
    return res + k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    memset(f, INF, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i < n; i++){
        for (int t = 0; t < k; t++){
            f[i][t] = min(f[i - 1][t], 1 + f[i - 1][sub(t, a[i])]);
        }
    }

    cout << max(n - f[n - 1][sum % k], 0) << endl;

    return 0;
}