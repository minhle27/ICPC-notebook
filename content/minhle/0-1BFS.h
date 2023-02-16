/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: VNOI
 * Description: 0-1 BFS, find shortest path in 0-1 weighted graph. App: find the minimum of edges that is needed to be reversed in direction to make the path 1->N possible
 * Time: better than Dijkstra
 * Status: 
 */

int n, m;
int d[maxN];
vector < pair <int, int> > g[maxN];

void bfs(int s) {
    fill_n(d, n + 1, inf);
    deque <int> q;
    q.push_back(s);
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        if (u == n) return;

        for (auto edge : g[u]) {
            int v = edge.second;
            int w = edge.first;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (w) q.push_back(v);
                else q.push_front(v);
            }
        }
    }
    d[n] = -1;
}