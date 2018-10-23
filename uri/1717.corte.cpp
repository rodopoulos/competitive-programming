#include <bits/stdc++.h>
using namespace std;

float x[204], y[204];
long long dp[10002];

float dis(int p1, int p2) {
  return sqrt(pow(x[p2] - x[p1], 2) + pow(y[p2] - y[p1], 2));
}

float min_decomp(int v) {
  if (v == 4)
    return 0;

  


  return 0;
}

int main() {
  int n;

  cin >> n;

  for (int i = 1; i <= 2*n; i++) {
    cin >> x[i] >> y[i];
  }

  cout << min_decomp(2*n) << endl;

  return 0;
}
