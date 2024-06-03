#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
		  int n, k, x, c=1; cin >> n >> k >> x;
		  vector<int> v(n), diff;

		  for (int i = 0; i < n; i++) cin >> v[i]; 
		  sort(v.begin(), v.end());

		  for (int i = 1; i < n; i++) if (v[i]-v[i-1] > x) diff.push_back(v[i]-v[i-1]); 
		  c+=diff.size();
		  sort(diff.begin(), diff.end());
		  for (auto a : diff) {
					 if (a%x==0) {
								if ((k-((a/x)-1))>=0) {
										  c--; 
										  k-=(a/x)-1;
								}
					 } else  {
								if ((k-floor(a/x))>=0) {
										  c--; 
										  k-=floor(a/x);
								}
					 }
		  }
		  if (c<1) c=1;
		  cout << c <<'\n';
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	int t; cin >> t;
//	while(t--) 
	solve();
}
