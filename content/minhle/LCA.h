/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Lowest Common Ancestor, Euler Tour + RMQ
 * Time: O(M\log N) 
 * Status: 
 */

int L[2*MAX_N], E[2*MAX_N], H[MAX_N], idx;

// init L, E, H
void dfs(int cur, int depth) {
    H[cur] = idx;
    E[idx] = cur;
    L[idx++] = depth;
    for (auto &nxt : children[cur]) {
        dfs(nxt, depth+1);
        E[idx] = cur; // backtrack to cur
        L[idx++] = depth;
    }
}

void buildRMQ() {
    idx = 0; memset(H, -1, sizeof H);
    dfs(0, 0); // root is at index 0
}

// the solution is given by LCA(u, v) = E[RMQ(H[u], H[v])] where RMQ(i, j) is executed on the L array.