#include <bits/stdc++.h>
using namespace std;

#define int long long

int ev(vector<int>& v, int k, int h) 
{
	int damage=0;
	for (int i = 0; i < v.size(); i++) {
		if (i==v.size()-1) {
			damage+=k;
			break;
		}
		if (v[i] + (k-1) >= v[i+1]) {
			damage+=v[i+1]-v[i];
		} else {
			damage+=k;
		}
	}
	return damage;
}

void solve()
{
	int n, h; cin >> n >> h;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int l = 0, r = LLONG_MAX;
	while (l<=r) {
		int mid = l+(r-l)/2;
		if (ev(v,mid,h)>=h && ev(v,mid-1,h)<h) {
			cout << mid <<'\n';
			return;
		}
		if (ev(v,mid,h)>=h) {
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
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
