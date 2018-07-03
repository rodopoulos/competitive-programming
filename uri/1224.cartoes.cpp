#include <bits/stdc++.h>
using namespace std;

int N, c[10002];
long long dp[10002];

// Recursive solution without memoization
long long rmax_points(int i, int n) {
  if (n == 0)
    return 0;

  if (n % 2 == 0) {
    return max(
      rmax_points(i+1, n-1) + c[i],
      rmax_points(i, n-1) + c[i+n-1]
    );
  } else { // turn == W
    return min(
      rmax_points(i+1, n-1),
      rmax_points(i, n-1)
    );
  }
}


// Iteractive solution with tabulation
long long max_points(int n) {
  for (int k = 1; k <= n; k++) {
    for (int j = 1; j <= n-(k-1); j++) {
      if (k%2 == 0)
        dp[j] = max(dp[j+1] + c[j], dp[j] + c[j+k-1]);
      else
        dp[j] = min(dp[j+1], dp[j]);
    }
  }
  return dp[1];
}


int main() {
  while (scanf("%d", &N) == 1) {
    for (int i = 1; i <= N; i++) {
      cin >> c[i];
    }

    cout << max_points(N) << endl;
    memset(dp, 0, sizeof(dp));
  }

  return 0;
}
