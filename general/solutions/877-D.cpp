#include "bits/stdc++.h"
using namespace std;

typedef struct tripla {
  int f;
  int s;
  int t;
} tripla;

void solve()
{
  int n,m,k;
  cin >> n >> m >> k;
  vector<string> map;
  tripla mat[n][m];
  int mx[4] = {1,-1,0,0};
  int my[4] = {0,0,1,-1};

  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    map.push_back(tmp);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      mat[i][j].f = -1;
      mat[i][j].s = -1;
      mat[i][j].t = -1;
    }
  }

  tripla A, B;
  cin >> A.f >> A.s;
  cin >> B.f >> B.s;

  A.f -= 1; A.s -= 1; A.t = 1;
  B.f -= 1; B.s -= 1; B.t = -1;

  mat[A.f][A.s].f = -2;
  mat[A.f][A.s].s = -2;
  if (A.f == B.f && A.s == B.s) {
    cout << 0 << '\n';
    return;
  }

  queue<tripla> Q;
  Q.push(A);
  while(!Q.empty()) {
    tripla actual = Q.front(); Q.pop();
    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= k; j++) {
	tripla nx;
	nx.f = actual.f + (my[i]*j);
	nx.s = actual.s + (mx[i]*j);
	nx.t = actual.t + 1;
	if (nx.f < 0 || nx.s < 0 ||
	    nx.f >= n || nx.s >= m ) continue;
	if (map[nx.f][nx.s] == '#') break;
	if (mat[nx.f][nx.s].f == -1) {
	  mat[nx.f][nx.s] = actual;
	  if (nx.f == B.f && nx.s == B.s) goto last ;
	  Q.push(nx);
	}
      }
    }
  }
 last:
  cout <<  mat[B.f][B.s].t << '\n';
  return;
}
  
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin); 
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
