#include <bits/stdc++.h>
using namespace std;

#define pa pair<int, int>
#define ff first
#define ss second 

void solve()
{
  int a, b, c, lvl=0, c_av = 0, leafs = 0;
  cin >> a >> b >> c;
  if (!a && !b && c == 1) {cout << "0\n"; return;
  } else if (!a && !b) {cout << "-1\n"; return;
  } if ((a || b) && !c) {cout << "-1\n"; return;}
  if (!a) {
    if (c == 1) cout << b << "\n";
    else cout << "-1\n";
    return;
  }
  while (a > 0) {
    a-=pow(2,lvl);
    lvl++;
  }
  c_av = abs(a); b -= c_av;
  if (a < 0) leafs = (2*pow(2, lvl-1) + a);
  else leafs = pow(2, lvl);
  if (b>0) b%leafs == 0 ? lvl+=ceil(b/leafs): lvl+=ceil(b/leafs)+1;
  if (leafs == c) {cout << lvl << "\n"; return;} 
  cout << "-1\n";
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
