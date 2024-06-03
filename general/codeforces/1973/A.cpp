#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
  int a, b, c; cin >> a >> b >> c;
  if((a+b+c)%2==1){
    cout << "-1\n";
    return;
  }
  cout << min((a+b+c)/2, a+b) << '\n';
}

int32_t main() 
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) solve();
}
