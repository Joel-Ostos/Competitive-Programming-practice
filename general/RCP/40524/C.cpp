#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	if (n==1) {
		cout << "1\n";
		return;
	}
	int max = 0; int cont = 0;
	for (int i = 1; i < n; i++) {
		if (v[i] > v[i-1]) {
			cont++;
			if (cont > max) {
				max = cont;
			}
		} else {
			cont = 0;
		}
	}
	cout << max+1 << '\n';
}

int32_t main() 
{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin); 
//#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//int t; cin >> t;
	//while (t--) 
	solve();
}
