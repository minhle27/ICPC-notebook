/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Dynamic LCA (find LCA(u,v) with different roots)
 * Time: 
 * Status: 
 */

const int N = 1e5 + 9;
int n;
vector<int> g[N];

int h[N], up[N][17];
void dfs(int u) {
    for (int v : g[u]) {
        if (v == up[u][0]) continue;
        h[v] = h[u] + 1;

        up[v][0] = u;
        for (int j = 1; j < 17; ++j)
            up[v][j] = up[up[v][j - 1]][j - 1];

        dfs(v);
    }
}

int lca(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);

        int k = h[u] - h[v];
        for (int j = 0; (1 << j) <= k; ++j)
            if (k >> j & 1)
                u = up[u][j];
    }
    if (u == v) return u;

    int k = __lg(h[u]);
    for (int j = k; j >= 0; --j)
        if (up[u][j] != up[v][j])
            u = up[u][j], v = up[v][j];
    return up[u][0];
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    while (cin >> n, n) {
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // use 1 as fixed root
        dfs(1);

        char c;
        int m, root(1), u, v; cin >> m; while (m--) {
            cin >> c;

            // fing LCA(u,v) with this root
            if (c == '!') cin >> root;
            else {
                cin >> u >> v;
                // ans is one of these
                int uv = lca(u, v);
                int ur = lca(u, root);
                int vr = lca(v, root);
                cout << (uv ^ ur ^ vr) << '\n';
            }
        }
    }
}