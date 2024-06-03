#include <bits/stdc++.h>
using namespace std;

#define pa pair<int, int>
#define ff first
#define ss second 
//string_view takes a slice of a string but doesnt copies it
//substr copies a slice of a string
void solve()
{
	string str; cin >> str;
	if (str.size()%2 == 0 && str[0] != ')' && str[str.size()-1] != '(') {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
	return;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
