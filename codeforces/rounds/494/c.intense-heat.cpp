#include <bits/stdc++.h>
using namespace std;

int a[5002], s[5002];

double avg(int l, int r) {
  if (l == 0)
    return ((double)s[r])/((double)(r-l+1));
  else
    return ((double)(s[r] - s[l-1]))/((double)(r-l+1));
}

int main() {
  int n, k;

  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++)
    s[i] = a[0];
  for (int i = 1; i < n; i++)
    s[i] = a[i] + s[i-1];

  int i = k;
  double m = -1;
  while (i <= n) {
    for (int j = 0; j <= n-i; j++) {
      double a = avg(j, j+i-1);
      if (a > m) {
        m = a;
      }
    }
    i++;
  }

  printf("%.15f\n", m);

  return 0;
}
