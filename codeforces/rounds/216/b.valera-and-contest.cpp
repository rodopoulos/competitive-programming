/* Problem B - Round #216 - Div. 2
 * https://codeforces.com/contest/369/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, l, r, sk, sa;
  cin >> n >> k >> l >> r >> sa >> sk;

  if (k * r == sk) {
    for (int i = 0; i < k; i++)
      cout << r << ' ';

    for (int i = 0; i < n-k; i++)
      cout << (sa-sk)/(n-k) << ' ';
    cout << endl;

  } else if (k*r > sk) {
    for (int i = 0; i < k-1; i++) {
      cout << r << ' ';
    }
    cout << sk - k*r << ' ';

  }

  return 0;
}
