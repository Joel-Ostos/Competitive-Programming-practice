/*
  Author: Joel Ostos
  Date: 2024-06-06 
  Problem: https://codeforces.com/contest/1538/problem/D 
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

typedef struct tripla tripla;
struct tripla {
  int ff;
  int ss;
  int tt;
};

struct sort_pred {
    bool operator() (const tripla &left, const tripla &right) {
        return left.ss < right.ss;
    }
};


void solve()
{
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
