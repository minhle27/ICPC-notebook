/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Trace back the shortest path
 * Status: 
 */

vector<int> trace_path(vector<int> &trace, int S, int u) {
    if (u != S && trace[u] == -1) return vector<int>(0); 

    vector<int> path;
    while (u != -1) { 
        path.push_back(u);
        u = trace[u];
    }
    reverse(path.begin(), path.end()); 
    
    return path;
}