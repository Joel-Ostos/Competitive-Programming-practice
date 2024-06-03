#include <bits/stdc++.h>
using namespace std;

#define pa pair<int, int>
#define ff first
#define ss second 
//string_view takes a slice of a string but doesnt copies it
//substr copies a slice of a string
void solve()
{
	int n; cin >> n;
	string str; cin >> str;
	for (int i=1;i<=n;i++) {
		if (n%i==0) {
			int cum = 1;
			for (int j=0;j<i;j++) {
				for (int k=j+i;k<n;k+=i) {
					if (str[j] != str[k]) {
						cum--;
					}
				}
			}
			if (cum>=0) {
				cout << i << '\n';
				return;
			}
			cum = 1;
			for (int j=n-i;j<n;j++) {
				for (int k=j-i;k>=0;k-=i) {
					if (str[j] != str[k]) {
						cum--;
					}
				}
			}
			if (cum>=0) {
				cout << i << '\n';
				return;
			}
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
	while(t--) {
		solve();
	}
}
