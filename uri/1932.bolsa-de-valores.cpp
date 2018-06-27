#include <bits/stdc++.h>
using namespace std;

int p[200001], c, n, dp[200001][2];

int max_profit(int i, bool act) {
  // Base case: if I have actions, sell it. Otherwise, do nothing.
  if (i == n)
    return p[n] * act;

  if (dp[i][act] == -1) {
    if (act) {
      // I have the action. Is it better to sell it or keep it?
      dp[i][act] = max(max_profit(i+1, false) + p[i], max_profit(i+1, true));
    } else {
      // I don't have actions. Is it better to buy this one or keep looking?
      dp[i][act] = max(max_profit(i+1, true) - (p[i]+c), max_profit(i+1, false));
    }
  }

  return dp[i][act];
}

int main() {
  cin >> n >> c;

  memset(dp, -1, sizeof(dp));

  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  cout << max_profit(1, false) << endl;

  return 0;
}
