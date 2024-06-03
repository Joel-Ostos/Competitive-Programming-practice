#include <bits/stdc++.h>
using namespace std;

#define long long long

void solve()
{
	long n, k; cin >> n >> k;
	vector<long> vec(n);
	for (long i = 0; i < n; i++) {
		cin >> vec[i];
	}
	long l = ceil(((double)k)/2), r = k-l, dest = 0;
	for (long i = 0; i < vec.size(); i++) {
		if (vec[i] <= l) {
			dest++;
			l-=vec[i];
			vec[i] = -1;
		} 
		if (vec[i] > l && l > 0) {
			vec[i] -= l;
			break;
		}
	}
	for (long i = vec.size()-1; i >= 0; i--) {
		if (vec[i] <= r && vec[i] > 0) {
			dest++;
			r-=vec[i];
			vec[i]=-1;
		} 
		if (vec[i] > r) break;
	}
	cout << dest << '\n';
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--)
		solve();
}
