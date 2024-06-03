#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ev(ll g, vector<ll>& vec, ll x) 
{
	for (ll i = 0; i < vec.size(); i++) {
		if (g-vec[i] >= 0) {
			x-= g-vec[i];
			if (x<0) return -1;
		}
	}
	return x;
}

void solve()
{
	ll n,x; cin >> n >> x;
	vector<ll> vec(n);
	for (ll i = 0; i < n; i++) {
		cin >> vec[i];
	}
	ll l=0, r=LLONG_MAX;
	while(l<=r) {
		ll mid = (l+r)>>1;
		ll re = ev(mid, vec, x);
		if (re < 0) {
			r=mid-1;
		} else {
			l=mid+1;
		}
	}
	cout << r <<'\n';
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}
