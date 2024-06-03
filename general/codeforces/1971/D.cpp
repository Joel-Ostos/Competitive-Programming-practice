#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
	string str; cin >> str;
	int n = str.size();
	int cuts = 0;
	bool taken = 0;
	for (int i = 0; i < n;) {
		if (str[i]=='0') {
			while (str[i]=='0') {
				i++;
			}
			if (!taken) {
				while (str[i]=='1') {
					i++;
				}
				taken=1;
			}
			cuts++;
		}
		if (str[i]=='1') {
			while (str[i]=='1') {
				i++;
			}
			cuts++;
		}
	}
	cout << cuts << '\n';
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
