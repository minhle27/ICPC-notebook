/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Range min querry problem using Sparse Table, DP
 * Time: Preprocess: O(N\log N), Querry: O(1)
 * Status: 
 */

// M[i][j] is the index of the minimum value in the range starting at i and has a length of 2^j
void process2(int M[MAXN][LOGMAXN], int A[MAXN], int N)
{
  int i, j;

  for (i = 0; i < N; i++)
    M[i][0] = i;

  for (j = 1; 1 << j <= N; j++)
    for (i = 0; i + (1 << j) - 1 < N; i++)
      if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
        M[i][j] = M[i][j - 1];
      else
        M[i][j] = M[i + (1 << (j - 1))][j - 1];
}

// Find RMQ(i, j) by comparing two ranges of length 2^k that cover [i,j].
// One starts at i and the other ends at j