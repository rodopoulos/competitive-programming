/* Problem B - Round #324 - Div. 2
 * https://codeforces.com/problemset/problem/584/B
 */
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

#define MOD 1000000007

ll spow(ll b, ll e) {
  if (e == 0)
    return 1;
  if (e % 2) { // e is odd
    return (b * spow(b*b % MOD, e/2)) % MOD;
  }
  // e is even
  return spow(b*b % MOD, e/2);
}

int main() {
  ll n;
  cin >> n;

  // TODO: wtf do i need this +MOD?
  cout << (spow(3,3*n) - spow(7,n) + MOD) % MOD << endl;

  return 0;
}
