/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Binary Lifting, find kth ancestor of a node in a tree
 * Time: 
 * Status: 
 */

int par[N], up[N][17];
void preprocess() {
    for (int u = 1; u <= n; ++u) up[u][0] = par[u];
    for (int j = 1; j < 17; ++j)
        for (int u = 1; u <= n; ++u)
            up[u][j] = up[up[u][j - 1]][j - 1];
}

int ancestor_k(int u, int k) {
    for (int j = 0; (1 << j) <= k; ++j)
        if (k >> j & 1) u = up[u][j];
    return u;
}