#include "bits/stdc++.h"
using namespace std;

void solve()
{
  int n;
  cin >> n;
  string str;
  cin >> str;
  for (int i = 1; i <= 4; i++) {
    if (str.substr(0, i) + str.substr(n-4+i, 4-i) == "2020")  {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}
  
int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin); 
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
