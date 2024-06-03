#include "bits/stdc++.h"
using namespace std;

void solve()
{
  int n = 0;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int tmp = 0;
    cin >> tmp;
    nums.push_back(tmp);
  }
  if (n == 1) {
    cout << "1" << '\n';
    return;
  }
  sort(nums.begin(), nums.end());
  int median = n % 2 == 0 ? floor(n/2)-1 : floor(n/2);
  int target = nums[median]; 
  int steps = 0;
  for (int i = median; i < n; i++) {
    if (nums[i] != target) break;
      steps++;
  }
  cout << steps << '\n';
  return;
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
