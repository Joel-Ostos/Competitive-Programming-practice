#include <bits/stdc++.h>
using namespace std;


#define int long long
#define pb push_back
#define pii pair<int, int> 
#define vi vector<int> 
#define vpi vector<pair<int, int>> 
#define vvi vector<vector<int>>
#define ff first
#define ss second

int binary_s(int n, vi& que, vpi& seg) 
{
	int l = 0, r = que.size();
	l--; r++;
	while (r-l>1) {
		int mid = l + (r - l) / 2;

		unordered_map<int, int> sums;
		for (int i = 0; i < n; i++) sums[i] = 0;
		for (int i = 0; i < mid; i++) sums[que[i]] = 1;
		for (int i = 1; i < n; i++) sums[i] += sums[i-1];
		bool find = 0;	

		for (int i = 0; i < seg.size(); i++) {
			int ones;
			int a = seg[i].ff, b = seg[i].ss;

			if (a == 0) ones = sums[b];
			else ones = sums[b] - sums[a-1];

			if (ones > (b - a + 1) / 2) {
				r = mid;
				find = 1;
				break;
			} 
		}
		if (!find) l = mid;
	}
	return r;
}

void solve()
{
	int n, m; cin >> n >> m;
	vpi seg(m);
	for (int i = 0; i < m; i++) {
		int a,b; cin >> a >> b;
		seg[i] = {a-1, b-1};
	}
	int q; cin >> q;
	vi que(q);
	for (int i = 0; i < q; i++) {
		int a; cin >> a;
		a--;
		que[i] = a;
	}
	int res = binary_s(n, que, seg) ;
	if (res == que.size()+1) {
		cout << "-1\n";
		return;
	}
	cout << res << '\n';
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
