#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define pii pair<int, int> 
#define vi vector<int> 
#define vb vector<bool> 
#define vpi vector<pair<int, int>> 
#define vvi vector<vector<int>>
#define um unordered_map
#define pq priority_queue
#define ff first
#define ss second

#define fori(n, jump) for (int i = 0; i < n; i+=jump)
#define fore(beg, n, jump) for (int i = beg; i < n; i+=jump)
#define foreq(beg, n, jump) for (int i = beg; i <= n; i+=jump)
#define fora(container) for (auto it : container)

void solve()
{
	int n; cin >> n;
	queue<int> v_column;
	um<int, int> m;
	pq<int, vector<int>, greater<>> ops;
	vb check(n+1,0);

	fori (n, 1) {
		int curr; cin >> curr;
		if (i == n - 1 && curr != n + 1) {
		  cout << "Error" << '\n';
		  return;
		}
		v_column.push(curr);
		m[curr] += 1;
		check[curr] = 1;
	}
	foreq(1, n+1, 1) {
	  if (!check[i]) ops.push(i);
	}
	if (ops.size()==0) {
	  cout << "Error" << '\n';
	  return;
	}

	while (!v_column.empty()) {
	  int actual = v_column.front(); v_column.pop();
	  cout << ops.top() << '\n';
	  ops.pop();
	  m[actual]--;
	  if (m[actual] == 0) {
	    m.erase(actual);
	    ops.push(actual);
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
	int t = 1;
	while(t--) solve();
}
