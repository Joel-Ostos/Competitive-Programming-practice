#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll bs(ll t,vector<ll>& vec) 
{
			ll l=0,r=vec.size()-1;
		  while (l<=r) {
					 ll mid = l+(r-l)/2;
					 if ((mid==0 && vec[mid]==t) || (t > vec[mid-1] && vec[mid]==t)) return mid; 
					 if (vec[mid]>t||vec[mid]==t) {
								r=mid-1;
					 } else {
								l=mid+1;
					 }
		  }
		  return -1;
}

void solve()
{
		  ll n, q; cin >> n >> q;
		  vector<ll> vec(n);
		  for (ll i = 0; i < n; i++) cin >> vec[i];
		  for (ll i = 0; i < q; i++) {
					 ll t; cin >> t;
					 cout << bs(t, vec) <<'\n';
		  }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
		  freopen("input.txt", "r", stdin); 
#endif
		  ios::sync_with_stdio(false);
		  cin.tie(nullptr);
		  solve();
}
