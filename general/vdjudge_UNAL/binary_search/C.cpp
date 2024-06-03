#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ev(ll guess, ll n, ll sum, ll sum_c, ll c) 
{
	if (guess > c || sum > 4e18/(2*guess) || guess > 4e18/guess || n > 4e18 / (guess * guess)) {
		return -1;
	}
	return sum_c + (2*(guess*sum)) + n * (guess*guess);
}

void solve()
{
	ll n,c; cin >> n >> c;
	ll sum=0, sum_c=0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		sum+=tmp;
		sum_c+=tmp*tmp;
	}
	ll l=0,r=c;
	while (l<=r) {
		ll mid = l+r>>1;
		ll result = ev(2*mid, n, sum, sum_c, c);
		if (result == c) {
			cout << mid << '\n';
			return;
		} 
		if (result > c || result < 0  || mid > 4e18/mid) {
			r=mid-1;
		} else {
			l=mid+1;
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}
