/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: From a vertex u (source), Find the length of the shortest cycle includes that u vertex. 
 * Time: O(\log N) for querry and point update
 * Status: 
 */

const int maxN  = 210;
 
int n;
int visit[maxN], d[maxN];
vector <int> g[maxN];
 
int bfs(int s) {
    fill_n(d, n + 1, 0);
    fill_n(visit, n + 1, false);

    queue <int> q;
    q.push(s);
    visit[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            
            // If get back to source, return cycle length and end BFS
            if (v == s) return d[u] + 1;
            
            if (!visit[v]) {
                d[v] = d[u] + 1;
                visit[v] = true;
                q.push(v);
            }
        }
    }
    return 0;
}
 
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int h; 
            cin >> h;
            if (h) g[i].push_back(j);
        }
 
    for (int i = 1; i <= n; ++i) {
        int ans = bfs(i);
        if (ans) cout << ans << '\n';
        else cout << "NO WAY\n";
    }
} 