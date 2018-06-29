#include <bits/stdc++.h>
using namespace std;

#define INVALID -1

int n, l, m, p,
    c[2001], v[2001],
    dp[2002][2002];


/* f(y, i) = "minimal production cost for a i years old machine, since y years
   have passed" */
int min_cost1(int year, int age) {
  if (year == n+1) { // end of period (base case)
    dp[year][age] = 0;
  }

  if (age == m) { // destiler is obsolete -> we are oblied to sell it
    dp[year][age] = min_cost1(year+1, 0) + (p-v[age]);
  }

  else if (age == 0){ // destiller is new -> always better to repair
    dp[year][age] = min_cost1(year+1, age+1) + c[age];
  }

  if (dp[year][age] == INVALID) {
    int
     sell = min_cost1(year+1, 0) + (p-v[age]),
     repair = min_cost1(year+1, age+1) + c[age];

    dp[year][age] = min(sell, repair);
  }

  for (int i = 1; i <= year; i++) cout << '.';
  cout << "min_cost(" << year << ", " << age << ") = " << dp[year][age] << endl;
  return dp[year][age];
}



// int min_cost2(int left, int age) {
//   if (left == 0) {
//     return 0;
//   }
//
//   else if (age == m) {
//     return min_cost2(left-1, 0) - v[age] + p;
//   }
//
//   else if (age == 0) {
//     return min_cost2(left-1, age+1) + c[age];
//   }
//
//   int
//    sell = min_cost2(left-1, 0) - v[age] + p,
//    repair = min_cost2(left-1, age+1) + c[age];
//
//   return min(sell, repair);
// }


int main() {
  while (scanf("%d%d%d%d", &n, &l, &m, &p) == 4) {
    memset(dp, INVALID, sizeof(dp));

    for (int i = 0; i < m; i++) {
      cin >> c[i];
    }

    for (int i = 1; i <= m; i++) {
      cin >> v[i];
    }

    cout << min_cost1(1, l) << endl;
  }

  return 0;
}
