#include <bits/stdc++.h>
using namespace std;

int dp[21][31],
    mn[21], pz[21];

int max_pizzas(int n, int p) {
  if (n == 0 || p == 0)
    return 0;

  if (pz[n] > p)
    return max_pizzas(n-1, p);

  if (!dp[n][p]) {
    dp[n][p] = max(
      mn[n] + max_pizzas(n-1, p - pz[n]),
      max_pizzas(n-1, p)
    );
  }

  return dp[n][p];
}

int main() {
  int n;
  cin >> n;

  while (n) {
    memset(dp,0,sizeof(dp));
    int P, M;
    cin >> P;

    for (int i = 1; i <= n; i++) {
      cin >> mn[i] >> pz[i];
    }

    M = max_pizzas(n, P);
    cout << M << " min." << endl;

    cin >> n;
  }

  return 0;
}
