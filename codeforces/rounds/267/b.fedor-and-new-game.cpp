/* Problem B - Round #267 - Div. 2
 * https://codeforces.com/contest/467/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

unsigned long long p[10002];

int main() {
  int n, m, k, ans = 0;
  unsigned long long f;
  cin >> n >> m >> k;

  for (int i = 1; i <= m; i++) {
    cin >> p[i];
  }
  cin >> f;

  for (int i = 1; i <= m; i++) {
    p[i] ^= f;
    if (__builtin_popcountll(p[i]) <= k)
      ans++;
  }

  cout << ans << endl;

  return 0;
}
