#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define pb push_back
#define pii pair<int, int> 
#define vi vector<int> 
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define int int16_t

void solve()
{
	int n, k; cin >> n >> k;
	vector<string> vec((n*2)-1);
	vector<int> pos;
	int n_o = 0;
	for (int i = 0; i < (n*2); i++) {
		string tmp; cin >> tmp;
		vec[i] = tmp;
		pos.pb(i);
	}
	int t = 0;
	for (int i = 0; i < (n*2); i++) {
		if (t<pos.size() and i == pos[t]-1) {
			int val = stoi(v[i]);
			if (val%2) {
				n_o += stoi(v[i+2]);
			}
			i++;
			while (v[i]=='*') {
				i+=2;
			}
			t++;
		}
		if ((v[i]!="+" or v[i]!="-")) {
			int val = stoi(v[i]);
			if (val%2) {
				n_o++;
			}
		}
	}
	if (n_o%2==1) {
		cout << "odd" << '\n';
	} else {
		cout << "even" << '\n';
	}
	for (int i = 0; i < k; i++) {
		int t; cin >> t;
		string tmp; cin >> tmp;
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
