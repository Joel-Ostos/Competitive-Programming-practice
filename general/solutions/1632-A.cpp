#include <bits/stdc++.h>
using namespace std;

#define pa pair<int, int>
#define ff first
#define ss second 
#define int long long

void solve()
{
	int n;cin >> n;
	string a; cin >> a;
	int b=0,c=0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '0') b++;
		else if (a[i] == '1') c++;
	}
	if (a.size() > 4) {cout << "NO\n" ; return;}
	else if(a.size() == 2 && (b==1||c==1)) {
		cout << "YES\n" ; return;
	} else if (a.size() == 1) {
		cout << "YES\n" ; return;
	}
	cout << "NO\n";
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
