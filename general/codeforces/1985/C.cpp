/*
  Author: Joel Ostos
  Date: 2024-06-03 
  Problem: https://codeforces.com/contest/1980/problem/C 
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
#define um map
#define ff first
#define ss second
#define all(container) container.begin(), container.end()

#define fori(n, jump) for (int i = 0; i < n; i+=jump)
#define fore(beg, n, jump) for (int i = beg; i < n; i+=jump)
#define foreq(beg, n, jump) for (int i = beg; i <= n; i+=jump)
#define fora(container) for (auto it : container)


struct tripla {
  int ff; 
  int ss; 
  int tt; 
};
typedef  struct tripla tripla;

struct myComp {
    constexpr bool operator()( tripla const& a, tripla const& b)
    {
        return a.ff > b.ff;
    }
};

void solve()
{
	int l, c; cin >> l >> c;
	vector<int> att(c), cool(c);
	for (int i = 0; i < c; i++) cin >> att[i];
	for (int i = 0; i < c; i++) cin >> cool[i];
	pair<int, int> max = {-1,-1}, min = {LLONG_MAX,LLONG_MAX};
	for (int i = 0; i < c; i++) {
		if (cool[i] > max.ss) {
			max = {att[i], cool[i]};
		}
		if (cool[i] < min.ss) {
			min = {att[i], cool[i]};
		}
	}
	int t_damage = 0;
	for (int i = 0; i < c; i++) {
		t_damage += att[i];
	}
	if (l <= t_damage) {
		cout << "1\n";
		return;
	}
	int cont = 1;
	l -= t_damage;
	int min_d = -1;
	for (int i = min.ss; i <= max.ss; i++) {
		int act = 0;
		for (int j = 0; j < c; j++) {
			int co = ((int) (i / cool[j]));
			if (co == 0) break;
			act += att[i] * co;
		}
		int rem = (l / act) + 1;
		if (min_d > i*rem) {
			min_d = i*rem;
		}
	}
	cout << min_d << '\n';
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
