#include <bits/stdc++.h>
using namespace std;

int a[26], dp[1000005], n;

/* The problem with this approach is that in a stack-limited environment, this
 * will overflow the stack for large enough inputs. For instance, if we use
 * x = 1000000 and the block set is only {1}, then we will have 1000000 frames
 * for this function and will overflow the stack. We need a bottom-up approach.
 */
int min_blocks__top_down_dp(int x) {
  if (x == 0)
    return 0;

  if(!dp[x]) {
    int m = 100 ;
    for (int i = 1; i <= n; i++) {
      if (a[i] <= x){
        m = min(m, min_blocks__top_down_dp(x-a[i]) + 1);
      }
    }
    dp[x] = m;
  }

  return dp[x];
}



int main() {
  int t;
  cin >> t;

  while (t--) {
    int m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    cout << min_blocks(m) << endl;

    memset(dp,0,sizeof(dp));
  }

  return 0;
}
