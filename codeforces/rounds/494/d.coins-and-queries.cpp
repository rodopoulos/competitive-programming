/* SOLUTION OVERVIEW
  We can solve this with a DP. But the table for holding the answers for each
  query would be equal to the maximum number input for a query, i.e., 10^9. This
  is huge, we'll overflow the stack.

  We have to note 2 things:

    1. There are only 30 numbers between 0 and 10e9 that are powers of 2;
    2. We order these 30 powers of 2. Note that the bigger values are divided by
       the smaller ones. Thus, we can greedly try to get coins to obtain our
       query value, getting them in decreasing order;

  Hence, we iterate through array sqr, in decreasing order, subtracting from B
  the smallest number of coins we can use for that coin value.
  For that, check which is smaller: the total number of coins of that value or
  B divided by the current coin value (which will give the biggest possible
  number of coins of that value that we can use).

  At the end, if B is 0, return the number of coins. Otherwise, we couldn't
  gather coins in a way to obtain such value, thus, return -1.
 */
#include <bits/stdc++.h>
#define BIGN 1000000
typedef long long ll;

using namespace std;

int sqr[32];
ll a[200001];

int pw2(int x) {
  int r = 1;
  while (x) {
    r = r << 1;
    x--;
  }
  return r;
}

int min_coins(int val) {
  int coins = 0;
  for (int i = 30; i >= 0; i--) {
    if (!val)
      break;

    if (!sqr[i] || pw2(i) > val)
      continue;

    int c = min((int)(val/pw2(i)), sqr[i]);
    coins += c;
    val -= c * pw2(i);

    // This will work, but it increases the cost of each query with a O(n) factor
    // for (int j = sqr[i]; j != 0; j--) {
    //   if (pow(2, i) <= val) {
    //     val -= pow(2,i);
    //     coins++;
    //   } else
    //     break;
    // }
  }

  return val==0 ? coins : -1;
}

int main() {
  int n, q, b;

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sqr[(int)log2(a[i])]++;
  }

  for (int j = 1; j <= q; j++) {
    cin >> b;
    cout << min_coins(b) << endl;
  }

  return 0;
}
