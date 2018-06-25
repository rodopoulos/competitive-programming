/** SOLUTION OVERVIEW
 * This is exactly the knapsack problem.
 */
#include <bits/stdc++.h>
using namespace std;

int dp[20*30][30],
    min[51], piz[51];

int max_pizzas(int m, int p) {
  if (m == 0 || p == 0)
    return 0;

  if (piz[m] > p)
    return max_pizzas(m-1, p);

  if (!dp[m][p]) {
    dp[m][p] = max(
      min[n] + max_pizzas(m-1, p - piz[n]), // use the bullet
      max_pizzas(n-1, p) // leave the bullet
    );
  }

  return dp[m][p];
}

int main() {
  int n;
  cin >> n;

  while (n) {
    int P, M;
    cin >> P;
    memset(dp,0,sizeof(dp));

    for (int i = 1; i <= n; i++) {
      cin >> min[i] >> piz[i];
    }

    cin >> k >> r;

    M = max_pizzas(n, P);

    cout << M << " min." << endl;
    cin >> n;
  }

  return 0;
}
