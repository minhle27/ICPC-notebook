/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Bellman-Frod
 * Time: O(MN)
 * Status: 
 */


const long long INF = 2000000000000000000LL;
struct Edge {
    int u, v;
    long long w;
};

void bellmanFord(int n, int S, vector<Edge> &e, vector<long long> &D, vector<int> &trace) {
    D.resize(n, INF);
    trace.resize(n, -1);

    D[S] = 0;
    for(int T = 1; T < n; T++) {
        for (auto E : e) {
            int u = E.u;
            int v = E.v;
            long long w = E.w;
            if (D[u] != INF && D[v] > D[u] + w) {
                D[v] = D[u] + w;
                trace[v] = u;
            }
        }
    }
}