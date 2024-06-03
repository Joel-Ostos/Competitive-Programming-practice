#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second 
#define dst(a, b) (sqrt(((a).ff - (b).ff) * ((a).ff - (b).ff) + \
                        ((a).ss - (b).ss) * ((a).ss - (b).ss)))

double MIN_D =  DBL_MAX;

void min_c(vector<pair<int,int>> v, double cost)
{
  if (cost >= MIN_D) return;
  if (v.size() == 2) {
    cost += dst(v[0], v[1]);
    if (cost < MIN_D) MIN_D = cost; 
    return;
  }
  for (int i = 1; i < v.size(); i++) {
    vector<pair<int,int>> nv = v;
    nv.erase(nv.begin()+i);
    nv.erase(nv.begin());
    min_c(nv, cost + dst(v[0], v[i]));
  }
}

void solve(int t)
{
  vector<pair<int,int>> vec(2*t);
  for (int i = 0; i < 2*t; i++) {
    string name;
    pair<int,int> p;
    cin >> name >> p.ff >> p.ss;
    vec[i] = p;
  }
  min_c(vec, 0);
}
 
int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin); 
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, cont = 1; cin >> t;
  while (t!=0) {
    solve(t);
    printf("Case %d: %.2f\n", cont, MIN_D);
    MIN_D = DBL_MAX;
    cont++;
    cin >> t;
  }
}
