#include <iostream>
#include <vector>
using namespace std;

void solve() 
{
	int n, m, k; cin >> n >> m >> k;
	vector<vector<char>> v(m, vector<char>(n, '_'));
	char lt = 'a';
	while (k--) {
		int w, h, x, y; cin >> w >> h >> x >> y;
		for (int i = y; i < y+h and i < m; i++) {
			for (int j = x; j < x+w and j < n; j++) {
				v[i][j] = lt;
			}
		}
		lt++;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] ;
		}
		cout << '\n';
	}
}

int main() 
{
	solve();
}
