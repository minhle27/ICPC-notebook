/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: DFS
 * Time: O(V + E) 
 * Status: 
 */

vector<int> adj[N];
bool visited[N];

void dfs(int s){
    if (visited[s]) return;
    visited[s] = true;
    // process node s
    for (auto u : adj[s]){
        dfs(u);
    }
}