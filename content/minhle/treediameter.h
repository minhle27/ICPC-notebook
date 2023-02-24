/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: The diameter of a tree is the maximum length of a path between two nodes.
 * Time: O(N) for both algorithm
 * Status: 
 */

// First Algorithm
A general way to approach tree problems is to first root the tree
arbitrarily and then solve the problem separately for each subtree
An important observation is that every path in a rooted tree has a highest point:
the highest node that belongs to the path. Thus, we can calculate for each node x the
length of the longest path whose highest point is x. One of those paths corresponds
to the diameter of the tree. 
toLeaf(x): the maximum length of a path from x to any leaf
maxLength(x): the maximum length of a path whose highest point is x
First, to calculate toLeaf(x), we go through the children of x,
choose a child c with the maximum toLeaf(c), and add one to this value. Then,
to calculate maxLength(x), we choose two distinct children a and b such that the
sum toLeaf(a) + toLeaf(b) is maximum and add two to this sum. (The cases
where x has less than two children are easy special cases.)

// Second Algorithm
Another efficient way to calculate the diameter of a tree is based
on two depth-first searches. First, we choose an arbitrary node a in the tree and find
the farthest node b from a. Then, we find the farthest node c from b. The diameter
of the tree is the distance between b and c.

// Apply second Algo, Use LCA to find dist between 2 nodes
const int N = 2e5 + 8;
int n, k, root;
vector<vi> g(N), group(N >> 1);

int h[N], up[N][18];

void dfs(int u) {
    for (int v : g[u]) {
        h[v] = h[u] + 1;

        for (int j = 1; j < 18; ++j)
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

int dist(int u, int v) {
    int p = lca(u, v);
    return h[u] + h[v] - 2 * h[p];
}

int diameter(vector<int> &meeting) {
    int A = meeting[0], max_dist = 0, B = A, d;

    for (int x : meeting) {
        d = dist(A, x);
        if (max_dist < d) {
            max_dist = d;
            B = x;
        }
    }

    max_dist = 0;
    for (int x : meeting) {
        d = dist(B, x);
        max_dist = max(max_dist, d);
    }
    return max_dist;
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x >> up[i][0];
        group[x].emplace_back(i);
        g[up[i][0]].push_back(i);
        if (up[i][0] == 0) root = i;
    }

    dfs(root);

    for (int i = 1; i <= k; ++i)
        cout << diameter(group[i]) << '\n';
}