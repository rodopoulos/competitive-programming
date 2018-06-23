/**
 * Round #377 - Div.2 - B
 * http://codeforces.com/problemset/problem/732/B
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[501], b[501];

int main() {
  int n, k, w = 0;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }

  if (n == 1) {
    cout << 0 << endl;
    cout << a[0] << endl;
    return 0;
  }


  for (int i = 1; i < n; i++) {
    int d = k - b[i-1] - a[i];
    d = (d > 0) ? d : 0;
    b[i] += d;
    w += b[i] - a[i];
  }

  cout << w << endl;
  for (int i = 0; i < n; i++) {
    cout << b[i] << ' ';
  }
  cout << endl;

  return 0;
}
