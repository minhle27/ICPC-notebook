/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Fenwick Tree, solve Range Sum Querry problem, 1-based index
 * Time: O(\log N) for both querry and update
 * Status: 
 */

int tree[N];

// get sum [1->k]
int sum(int k){
    int s = 0;
    while (k >= 1){
        s += tree[k];
        k -= (k & -k);
    }
    return s;
}

//update point
void update(int k, int x) {
    while (k <= n){
        tree[k] += x;
        k += (k & -k);
    }
}