/* Problem D - Round #490 - Div. 3
 * http://codeforces.com/contest/999/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[400005];

int main() {
  int n, m;
  vector<int> c[100000];
  cin >> n >> m;

  unsigned int C = n/m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c[a[i] % m].push_back(i);
  }

  int ans = 0;
  vector<int> fr;
  for (int k = 0; k < 2; k++) {
    for (int i = 0; i <= m-1; i++) {
      while (c[i].size() > C) {
        int e = c[i].back();
        c[i].pop_back();
        fr.push_back(e);
      }
      while (c[i].size() < C) {
        int e = fr.back();
        fr.pop_back();
        c[i].push_back(e);
        int inc = (i - a[e]) % m;
        a[e] += inc;
        ans += inc;
      }
    }
  }

  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;

  return 0;
}
