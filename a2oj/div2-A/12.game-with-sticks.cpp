#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;

  cin >> n >> m;

  int M = min(n,m);

  if (M % 2 == 0) {
    cout << "Malvika" << "\n";
  } else {
    cout << "Akshat" << "\n";
  }

  return 0;
}
