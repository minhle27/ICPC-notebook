/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Kruskal Algorithm
 * Time: if the graph is densed, use Prim for better performance
 * Status: 
 */

struct DSU{
    vector<int> parent, sz;

    DSU(int n) : parent(n), sz(n) {};
    
    void init(int n){
        for (int i = 1; i <= n; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find_set(int v) {
        return v == parent[v] ? v : parent[v] = find_set(parent[v]);
    }

    bool join_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b){
            return false;
        }
        if (sz[a] < sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, mst_cost = 0, num_taken = 0;
    cin >> V >> E;
    vector<iii> EL(E);
    DSU g(V + 5); g.init(V);

    for (int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        EL[i] = {w, u, v};
    }
    
    sort(EL.begin(), EL.end()); // sort by w

    for (auto &[w, u, v] : EL){
        if (!g.join_sets(u, v)) continue;
        mst_cost += w;
        g.join_sets(u, v);
        ++num_taken;
        if (num_taken == V - 1) break;
    }

    cout << mst_cost << endl;
    return 0;
}