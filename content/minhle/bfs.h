/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: BFS
 * Time: O(V + E)
 * Status: 
 */

int V, E;
bool visited[MAX];
int path[MAX];
vi graph[MAX]; // adjacency List, an array of vectors 

void BFS(int s){
    // initialize visited array and path array
    for (int i = 0; i < V; i++){
        visited[i] = false;
        path[i] = -1;
    }
    queue<int> q;
    visited[s] = true; // start BFS from s
    q.push(s);

    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++){ // traverse through Vertex that are adjacent to u
            int v = graph[u][i];
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
                path[v] = u;
            }
        }
    }
}

void printPath(int s, int f){
    int b[MAX]; // save the vertex that we have been to
    int m = 0;
    if (f == s){
        cout << s;
        return;
    }
    if (path[f] == -1){
        cout << "No path" << endl;
        return;
    }

    while(true){
        b[m++] = f;
        f = path[f]; // trace back to previous vertex
        if (f == s){ // found 
            b[m++] = s;
            break;
        }
    }
    for (int i = m - 1; i >= 0; i--){ // print path
        cout << b[i] << " ";
    }
}

void printPathRecursion(int s, int f){
    if (s == f){ // base case 1
        cout << f << " ";
    }
    else{
        if (path[f] == -1){ // base case 2
            cout << "No path" << endl;
        }
        else{ // recursive case
            printPathRecursion(s, path[f]);
            cout << f << " ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int u, v;

    // read graph input (Edge List)
    cin >> V >> E;
    for (int i = 0; i < E; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int s = 0; // start point
    int f = 6; // desired destination
    BFS(s);
    printPathRecursion(s, f);

    return 0;
}