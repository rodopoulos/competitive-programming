/* Problem D - Round #490 - Div. 3
 * http://codeforces.com/contest/999/problem/D
 */
#include <bits/stdc++.h>
using namespace std;

int a[400005], c[400005];

int main() {
  int n, m;
  cin >> n >> m;

  int C = m/n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c[a[i] % m]++;
  }


  return 0;
}
