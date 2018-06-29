#include <bits/stdc++.h>
using namespace std;

#define A true
#define W false

int n, c[10002];

int max_points(int l, int r, int turn) {
  if (l == r)
    return 0;

  if (turn == A)
    return max(
      max_points(l+1, r, W) + c[l],
      max_points(l, r-1, W) + c[r]
    );
  else // turn == W
    return min(
      max_points(l+1, r, A),
      max_points(l, r-1, A)
    );
}



int main() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  cout << max_points(1, n, A) << endl;

  return 0;
}
