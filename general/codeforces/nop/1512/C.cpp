/*
  Author: Joel Ostos
  Date: 2024-06-01 
  Problem: https://codeforces.com/contest/1512/problem/C 
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

#define fori(n, jump) for (int i = 0; i < n; i+=jump)
#define fore(beg, n, jump) for (int i = beg; i < n; i+=jump)
#define foreq(beg, n, jump) for (int i = beg; i <= n; i+=jump)
#define fora(container) for (auto it : container)

void solve()
{
  int a, b; cin >> a >> b;
  string str; cin >> str;
  int i_a = a, i_b = b;
  fori(str.size(), 1) {
    if (str[i] == '0') a--;
    if (str[i] == '1') b--;
  }
  int n = str.size();
  if (n==1) {
    if (str[0] == '0' and i_a <= 0) {
      cout << "-1\n";
      return;
    } else if (str[0] == '1' and i_b <=0){
      cout << "-1\n";
      return;
    }
    if (str[0] == '?') {
      if (a>0) {
	str[0] = '0';
      } else {
	str[0] = '1';
      }
    }
    cout << str << '\n';
    return;
  }
  int i = 0, j = str.size()-1;
  while (i<j) {
    if (str[i] != '?' and str[j] == '?') {
      char tmp = str[i];
      switch (tmp) {
	case '0': {
		    if (a>=1) {
		      str[j] = tmp;
		      a--;
		    }
		  } break;
	case '1': {
		  if (b>=1) {
		    str[j] = tmp;
		    b--;
		  }
	       } break;
      }
    }

    if (str[i] == '?' and str[j] != '?') {
      char tmp = str[j];
      switch (tmp) {
	case '0': {
		    if (a>=1) {
		      str[i] = tmp;
		      a--;
		    }
		  } break;
	case '1': {
		  if (b>=1) {
		    str[i] = tmp;
		    b--;
		  }
	       } break;
      }
    }
    i++;
    j--;
  }

  i = 0, j = str.size()-1;

  //cout << str << '\n';
  //cout << i_a << " <- aes - bes -> " << b << '\n';
  while (i<j) {
    if (str[i] == '?' and str[j] == '?') {
      if (a>=2) {
	str[i] = str[j] = '0';
	a-=2;
	i++;
	j--;
	continue;
      }
      if (b>=2) {
	//cout << "pasa"<< '\n';
	//cout << "index -> " << i  << " " << j << '\n';
	str[i] = str[j] ='1';
	b-=2;
      }
    }
    i++;
    j--;
  }

  string comp = "";
  j = str.size()-1;
  fori(str.size(), 1) {
    comp += str[j];
    j--;
  }

  if (str.size()%2) {
    int mid = (str.size()-1)/2;
    if (str[mid] == '?' and (a > 0 or b > 0)) {
      if (a>0) {
	str[mid] = '0';
	comp[mid] = '0';
      }
      if (b>0) {
	str[mid] = '1';
	comp[mid] = '1';
      }
    }
  }

  fori(str.size(), 1) if (str[i] == '?') {cout << "-1\n"; return;}
  if (comp == str) {
    int num_a = 0;
    int num_b = 0;
    fori(n, 1) {
      if (str[i] == '0') num_a++;
      if (str[i] == '1') num_b++;
    }
    if (num_a != i_a or num_b != i_b) {
      cout << "-1\n";
      return;
    }
    cout << str << '\n';
    return;
  }
  cout << "-1\n";
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
