/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Lowest Common Ancestor, Binary Lifting
 * Time: O(MlogN) 
 * Status: 
 */

// init up
void dfs(int u) {
    for (int v : g[u]) {
        if (v == up[u][0]) continue;
        h[v] = h[u] + 1;
        
        up[v][0] = u;
        for (int j = 1; j < 20; ++j)
            up[v][j] = up[up[v][j - 1]][j - 1];

        dfs(v);
    }
}

int h[N], up[N][20];
int lca(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
    
        // find ancestor u' of u in which h(u') = h(v)
        int k = h[u] - h[v];
        for (int j = 0; (1 << j) <= k; ++j)
            if (k >> j & 1) // if jth bit of k is 1
                u = up[u][j];
    }
    if (u == v) return u;
    
    // Find LCA(u,v)
    int k = __lg(h[u]);
    for (int j = k; j >= 0; --j)
        if (up[u][j] != up[v][j]) // if 2^jth ancestors of u and v are different
            u = up[u][j], v = up[v][j];
    return up[u][0];
}