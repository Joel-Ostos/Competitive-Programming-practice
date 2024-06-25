/*
  Author: Joel Ostos
  Date: 2024-06-04 
  Problem: https://codeforces.com/contest/1980/problem/F1 
*/

#include <bits/stdc++.h>
using namespace std;

#define __FILENAME__ strrchr("/" __FILE__, '/') + 1 

#define int long long
#define pb push_back
#define pii pair<int, int> 
#define vi vector<int> 
#define vb vector<bool> 
#define vpi vector<pair<int, int>> 
#define vvi vector<vector<int>>
#define um unordered_map
#define ff first
#define ss second
#define all(container) container.begin(), container.end()

#define fori(n, jump) for (int i = 0; i < n; i+=jump)
#define fore(beg, n, jump) for (int i = beg; i < n; i+=jump)
#define foreq(beg, n, jump) for (int i = beg; i <= n; i+=jump)
#define fora(container) for (auto it : container)

//Customize functions
typedef struct tripla tripla;
struct tripla {
  int ff;
  int ss;
  int tt;
};

struct sort_pred {
    bool operator()(const tripla &left, const tripla &right) {
        return left.ss < right.ss;
    }
};

void solve()
{
	int n, mi, k; cin >> n >> mi >> k;
	map<int, int> m;
	vector<tripla> v;
	fori (k,1) {
		int a, b; cin >> a >> b;
		v.pb({a, b, i+1});
		if (m[b] == 0) {
			m[b] = a;
			continue;
		}
		if (m[b] != 0 and a > m[b]) {
			m[b] = a;
		}
	}
	sort(all(v), sort_pred());
	map<int, int> ans;
	int w_l = m[1]+1;
	int r = 0,e = 1, o = 0;
	for (auto it : m) {
	  if(it.ss > r){
	    o += (it.ff-e) * (n-r);
	    r = it.ss;
	    e = it.ff;
	  }
	}
	o += (mi+1-e)*(n-r);
	cout << o << '\n';

	w_l = 1;
	fori(k,1) {
	  if (m[v[i].ss] == v[i].ff and v[i].ff >= w_l) {
	    ans[v[i].tt] = 1;
	    w_l = m[v[i].ss]+1;
	  }
	}

	fori (k,1) cout << ans[i+1] << ' ';

	cout << '\n';
}

int32_t main()
{
#ifndef ONLINE_JUDGE
  string str = "";
  str = __FILENAME__;
  string input = ""; input.pb(str[0]);
  input += "_input.txt";
  string output = ""; output.pb(str[0]);
  output += "_out.txt";
  freopen(input.c_str(), "r", stdin);
  freopen(output.c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while(t--) solve();
}
