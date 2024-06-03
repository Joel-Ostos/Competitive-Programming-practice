#include "bits/stdc++.h"
#include <string> 
using namespace std;

void solve()
{
  string num;
  cin >> num;
  string opt = "0";
  int target = 9;
  for (int i = 1; target > 0; i++) {
    if (opt[opt.size()-1]-'0' <= target) {
      opt[opt.size()-1] = i +'0';
    }
    if (opt[opt.size()-1]-'0' == target) {
      i = 0;
      opt.push_back(i+'0');
      target--;
    }
    int result = 0;
    for (int j = 0; j < opt.size(); j++) {
      result += opt[j] - '0';
    }
    if (result == stoi(num)) {
      sort(opt.begin(), opt.end());
      cout << stoi(opt) << '\n';return; 
    }
    if (result > stoi(num)) goto last;
  }
  last:
  cout << -1 << '\n';
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
