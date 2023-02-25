/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Check bipartite, A graph is bipartite if it is possible to color its nodes using two colors in such a
way that no adjacent nodes have the same color. It turns out that a graph is bipartite
exactly when it does not have a cycle with an odd number of edges
 * Time: 
 * Status: 
 */

// BFS implementation
int n, l;
int color[maxN];
vector <int> g[maxN];

bool checkBipartiteGraph() {
    fill_n(color, n + 1, -1);

    queue <int> q;
    q.push(0);
    color[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (color[v] == color[u]) return false;
            if (color[v] == -1) {
                color[v] = !color[u];
                q.push(v);
            }
        }
    }
    return true;
}

int main() {
    while (cin >> n){
        if (!n) return 0;

        cin >> l;
        while (l--) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (!checkBipartiteGraph()) cout << "NOT ";
        cout << "BICOLORABLE.\n";

        for (int i = 0; i < n; ++i) g[i].clear();
    }
}

// Same idea for DFS implementation
