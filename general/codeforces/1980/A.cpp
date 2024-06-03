/*
  Author: Joel Ostos
  Date: 2024-06-03 
  Problem: https://codeforces.com/contest/1980/problem/A 
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

void solve()
{
	int n, m; cin >> n >> m;
	string a; cin >> a;
	vector<char> str; 
	for (int i = 0; i < n; i++) {
		str.pb(a[i]);
	}
	int ex_a = 0, ex_b = 0, ex_c = 0, ex_d=0, ex_e=0, ex_f=0, ex_g = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'A') ex_a++;
		if (str[i] == 'B') ex_b++;
		if (str[i] == 'C') ex_c++;
		if (str[i] == 'D') ex_d++;
		if (str[i] == 'E') ex_e++;
		if (str[i] == 'F') ex_f++;
		if (str[i] == 'G') ex_g++;
	}
	int cont = 0;
	if (ex_a < m) cont += m - ex_a;
	if (ex_b < m) cont += m - ex_b;
	if (ex_c < m) cont += m - ex_c;
	if (ex_d < m) cont += m - ex_d;
	if (ex_e < m) cont += m - ex_e;
	if (ex_f < m) cont += m - ex_f;
	if (ex_g < m) cont += m - ex_g;
	cout << cont << '\n';
	return;
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
