/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Kruskal Algorithm
 * Time: if the graph is densed, use Prim for better performance
 * Status: 
 */

struct DSU {
    vector<int> lab;

    DSU(int n) : lab(n+1, -1) {}

    int getRoot(int u) {
        if (lab[u] < 0) return u;
        return lab[u] = getRoot(lab[u]);
    }

    bool merge(int u, int v) {
        u = getRoot(u); v = getRoot(v);
        if (u == v) return false;
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        return true;
    }

    bool same_component(int u, int v) {
        return getRoot(u) == getRoot(v);
    }

    int component_size(int u) {
        return -lab[getRoot(u)];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, mst_cost = 0, num_taken = 0;
    cin >> V >> E;
    vector<iii> EL(E);
    DSU g(V + 5); 

    for (int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        EL[i] = {w, u, v};
    }
    
    sort(EL.begin(), EL.end()); // sort by w

    for (auto &[w, u, v] : EL){
        if (g.same_component(u, v)) continue;
        mst_cost += w;
        g.merge(u, v);
        ++num_taken;
        if (num_taken == V - 1) break;
    }

    cout << mst_cost << endl;
    return 0;
}