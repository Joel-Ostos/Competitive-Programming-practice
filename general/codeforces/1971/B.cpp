#include <bits/stdc++.h>
using namespace std;
#define int long long

void swapa(string& str, int i, int j) {
	char tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}

void solve() 
{
	string str; cin >> str;
	for (int i = 0; i < str.size(); i++) {
		for (int j = i; j < str.size(); j++) {
			if (str[i] != str[j]) {
				swapa(str, i, j);
				cout << "YES\n";
				cout << str << '\n';
				return;
			}
		}
	}
	cout << "NO" << '\n';
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
