/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: SegTree, version range min queries
 * Time: O(\log N) for querry and point update
 * Status: 
 */

const int inf  = 1e9 + 7;
const int maxN = 1e5 + 7;

int n, q;
int a[maxN];
int st[4 * maxN]; 

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }

    int mid = l + r >> 1; // (l + r) / 2
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    
    st[id] = min(st[2 * id], st[2 * id + 1]);
}

void update(int id, int l, int r, int i, int val) {
    // i is outside [l, r], ignore id
    if (l > i || r < i) return;
    
    // No children
    if (l == r) {
        st[id] = val;
        return;
    }
    
    // Call recursion to solve for children of id
    int mid = l + r >> 1; // (l + r) / 2
    update(2 * id, l, mid, i, val);
    update(2 * id + 1, mid + 1, r, i, val);
    
    // Update min of [l, r] according to 2 of its children
    st[id] = min(st[2 * id], st[2 * id + 1]);
}

int get(int id, int l, int r, int u, int v) {
    // [u, v] is not intersecting with [l, r]
    if (l >  v || r <  u) return inf; 
    
    // [l, r] is completely inside [u, v] 
    if (l >= u && r <= v) return st[id];

    int mid = l + r >> 1; // (l + r) / 2
    int get1 = get(2 * id, l, mid, u, v);
    int get2 = get(2 * id + 1, mid + 1, r, u, v);
    
    return min(get1, get2);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);

    cin >> q;
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) update(1, 1, n, x, y); // Assign y for element at index x 
        else cout << get(1, 1, n, x, y) << '\n'; // RMQ(x, y)
    }
}