/* Problem A - Round #363 - Div. 1
 * https://codeforces.com/contest/698/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

#define R 0
#define C 1
#define G 2
#define GC 3

int a[101], dp[101][3], n;

int min_days(int i, int c) {
  if (i == n)
    return 0;

  if (dp[i][c] == -1) {
    if (a[i] == R || a[i] == c)
      dp[i][c] = min_days(i+1, R) + 1;
    else if (c == G && (a[i] == C || a[i] == GC))
      dp[i][c] = min(min_days(i+1, C), min_days(i+1, R) + 1);
    else if (c == C && (a[i] == G || a[i] == GC))
      dp[i][c] = min(min_days(i+1, G), min_days(i+1, R) + 1);
    else if (c == R && a[i] == G)
      dp[i][c] = min(min_days(i+1, G), min_days(i+1, R) + 1);
    else if (c == R && a[i] == C)
      dp[i][c] = min(min_days(i+1, C), min_days(i+1, R) + 1);
    else if (a[i] == GC)
      dp[i][c] = min(min(min_days(i+1, G), min_days(i+1, C)), min_days(i+1, R) + 1);
  }

  return dp[i][c];
}

int main() {

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  memset(dp, -1, sizeof dp);
  cout << min_days(0, R) << endl;

  return 0;
}
