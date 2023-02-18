/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Range min querry problem using Sparse Table, DP
 * Time: Preprocess: O(N\log N), Querry: O(1)
 * Status: 
 */

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