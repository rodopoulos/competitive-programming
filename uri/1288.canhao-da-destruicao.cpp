#include <bits/stdc++.h>
using namespace std;

int dp[51][100],
    d[51], w[51];

int max_damage(int n, int k) {
  if (n == 0 || k == 0)
    return 0;

  if (w[n] > k)
    return max_damage(n-1, k);

  if (!dp[n][k]) {
    dp[n][k] = max(
      d[n] + max_damage(n-1, k - w[n]), // use the bullet
      max_damage(n-1, k) // leave the bullet
    );
  }

  return dp[n][k];
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k, r, D;
    cin >> n;

    for (int i = 1; i <= n; i++) {
      cin >> d[i] >> w[i];
    }

    cin >> k >> r;

    D = max_damage(n, k);

    if (D < r) {
      cout << "Falha na missao" << endl;
    } else {
      cout << "Missao completada com sucesso" << endl;
    }
    memset(dp,0,sizeof(dp));
  }

  return 0;
}
