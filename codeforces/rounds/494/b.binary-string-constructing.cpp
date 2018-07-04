#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, x;

  cin >> a >> b >> x;

  if (x%2 == 0) {
    if (a > b) {
      for (int i = 0; i < x/2; i++)
        cout << "01";
      for (int i = 0; i < b - x/2; i++)
        cout << '1';
      for (int i = 0; i < a - x/2; i++)
        cout << '0';

    } else {
      for (int i = 0; i < x/2; i++)
        cout << "10";
      for (int i = 0; i < a - x/2; i++)
        cout << '0';
      for (int i = 0; i < b - x/2; i++)
        cout << '1';
    }

  } else {
    if (a > b) {
      for (int i = 0; i < x/2; i++)
        cout << "01";
      for (int i = 0; i < a - x/2; i++)
        cout << '0';
      for (int i = 0; i < b - x/2; i++)
        cout << '1';

    } else {
      for (int i = 0; i < x/2; i++)
        cout << "10";
      for (int i = 0; i < b - x/2; i++)
        cout << '1';
      for (int i = 0; i < a - x/2; i++)
        cout << '0';
    }
  }

  cout << endl;

  return 0;
}
