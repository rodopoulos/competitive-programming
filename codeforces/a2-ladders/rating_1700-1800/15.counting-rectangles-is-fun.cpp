/* Problem B - Round #219 - Div. 1
 * http://codeforces.com/problemset/problem/372/B
 *
 * SOLUTION OVERVIEW
 * DP on this shit.
*/
#include <bits/stdc++.h>
using namespace std;

#define N 41

int dp[N][N][N][N];
int grid[N][N];

int goodrecs(int a, int b, int c, int d) {
  if (a == b && c == d) {
    return grid[a][c];
  }

  if (dp[a][b][c][d] == -1) {

  }

  return dp[a][b][c][d];
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  memset(dp,-1,sizeof(dp));

  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 0; i < m; j++) {
      grid[i][j+1] = (s[j] == '0') ? 1 : 0;
    }
  }

  for (int i = 1; i <= q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << goodrecs(a,b,c,d) << endl;
  }

  return 0;
}
