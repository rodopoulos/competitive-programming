/* Problem A - Round #320 - Div. 2
 * http://codeforces.com/contest/579/problem/A
 *
 * SOLUTION OVERVIEW
 * Convert x to a base-2 number. Count the number the
 * number of bits equal to 1.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int ones = 0;
  while (n) {
    if (n & 1)
      ones ++;
    n = n >> 1;
  }

  cout << ones << endl;

  return 0;
}
