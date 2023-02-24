/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Flood Fill 
 * Time: 
 * Status: 
 */

int m, n; // row, col
bool visited[MAX][MAX];
string maze[MAX];

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

struct Cell {
    int r, c;
};

bool isValid(int r, int c){
    return r >= 0 && r < m && c >= 0 && c < n;
}

bool BFS(Cell s, Cell f){
    queue<Cell> q;
    visited[s.r][s.c] = true;
    q.push(s);

    while(!q.empty()){
        Cell u = q.front();
        q.pop();

        if (u.r == f.r && u.c == f.c){
            return true;
        }

        for (int i = 0; i < 4; i++){ // traverse through nodes that are adjacent to the current node
            int r = u.r + dr[i];
            int c = u.c + dc[i];

            if (isValid(r, c) && maze[r][c] == '.' && !visited[r][c]){
                visited[r][c] = true;
                q.push((Cell) {r, c});
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--){
        cin >> m >> n;

        for (int i = 0; i < m; i++){
            cin >> maze[i]; // read the maze
        }

        vector<Cell> entrance; // store Cells that are entrance
        
        // init visited array and check for entrance at the same time
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                visited[i][j] = false;
                if (maze[i][j] == '.' && (i == 0 || j == 0 || i == m - 1 || j == n - 1)){
                    entrance.push_back((Cell) {i, j});
                }
            }
        }

        if (entrance.size() != 2){
            cout << "invalid" << endl;
        }
        else{
            Cell s = entrance[0];
            Cell f = entrance[1];
            cout << (BFS(s, f) ? "valid" : "invalid") << endl;
        }
    }

    return 0;
}