/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Dijkstra
 * Time: O(M\log N) 
 * Status: 
 */

vector<vector<pi>> graph;
vi dist(MAX, INF);
int path[MAX];

struct option
{
    bool operator() (const pi &a, const pi &b) const
    {
        return a.S > b.S;
    } 
};

void Dijkstra(int s){
    priority_queue<pi, vector<pi>, option> pq;
    pq.push(MP(s, 0)); // (vertex, current sp)
    dist[s] = 0;

    while(!pq.empty()){
        pi top = pq.top();
        pq.pop();
        int u = top.F;
        int w = top.S; // current sp
        if (dist[u] != w){
            continue;
        }

        for (int i = 0; i < graph[u].size(); i++){
            pi nb = graph[u][i];
            if (w + nb.S < dist[nb.F]){
                dist[nb.F] = w + nb.S;
                pq.push(pi(nb.F, dist[nb.F]));
                path[nb.F] = u;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, t;
    cin >> n;
    s = 0, t = 4;
    graph = vector<vector<pi>>(MAX + 5, vector<pi>());  
    int d = 0;

    // adjacency matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> d;
            if (d > 0){
                graph[i].push_back(pi(j, d));
            }
        }
    }

    Dijkstra(s);
    int ans = dist[t];
    cout << ans << endl;

    return 0;
}