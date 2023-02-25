/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Cycle Check
 * Time:  
 * Status: 
 */

void cycleCheck(int u) { // check edge properties
    dfs_num[u] = EXPLORED; // color u as EXPLORED
    for (auto &[v, w] : AL[u]) { // C++17 style, w ignored
        printf("Edge (%d, %d) is a ", u, v);
        if (dfs_num[v] == UNVISITED) { // EXPLORED->UNVISITED
            printf("Tree Edge\n");
            dfs_parent[v] = u; // a tree edge u->v
            cycleCheck(v);
        }
        else if (dfs_num[v] == EXPLORED) { // EXPLORED->EXPLORED
            if (v == dfs_parent[u]) // differentiate them
                printf("Bidirectional Edge\n"); // a trivial cycle
            else
                printf("Back Edge (Cycle)\n"); // a non trivial cycle
        }
        else if (dfs_num[v] == VISITED) // EXPLORED->VISITED
            printf("Forward/Cross Edge\n"); // rare application
    }
    dfs_num[u] = VISITED; // color u as VISITED/DONE
}

// inside int main()
dfs_num.assign(V, UNVISITED);
dfs_parent.assign(V, -1);
for (int u = 0; u < V; ++u)
    if (dfs_num[u] == UNVISITED)
        cycleCheck(u);