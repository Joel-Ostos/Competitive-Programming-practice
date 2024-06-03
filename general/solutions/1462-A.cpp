#include "bits/stdc++.h"
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int> vec;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }
  int result[n];
  int beg = 0;
  int end = n-1;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      result[i] = vec[beg];
      beg++;
    } else {
      result[i] = vec[end];
      end--;
    }
  }
  for (auto num : result) {
    cout << num << ' ';
  }
  cout << '\n';
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
