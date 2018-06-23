#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007

// TODO: write about this way of pow
ll pow(ll b, ll e) {
  if (e == 0)
    return 1;
  if (e % 2) { // e is odd
    return (b * pow(b*b % MOD, e/2)) % MOD;
  }
  // e is even
  return pow(b*b % MOD, e/2);
}

ll shitpow(ll b, ll e) {
  if (e == 0) return 1;

  ll ans = 1;
  while (e) {
    ans *= b % MOD;
    e--;
  }
  return ans;
}

int main() {
  ull x, k;

  cin >> x >> k;

  if (x == 0) {
    cout << 0 << endl;
    return 0;
  } else {

  }


  return 0;
}
