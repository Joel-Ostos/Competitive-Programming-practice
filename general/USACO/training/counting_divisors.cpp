#include <bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<int, int> m;

void solve() 
{
	int n; cin >> n;
	int sum=1, r=1;
	int tmp = n;
	if (m.find(n)!=m.end()) {
		cout << m[n] << '\n';
		return;
	}
	for (int i = 2; i*i <= n; i++) {
		while (n%i==0) {
			sum++;
			n /= i;
		}
		r*=sum;
		sum = 1;
	}
	if (n>1) r*=2;
	m[tmp]=r;
	cout << r << '\n';
}

int32_t main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) solve();
}
