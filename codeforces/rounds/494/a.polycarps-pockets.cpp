#include <bits/stdc++.h>
using namespace std;

int v[105];

int main() {
  int n, c;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> c;
    v[c]++;
  }

  cout << *max_element(v, v+101) << endl;

  return 0;
}
