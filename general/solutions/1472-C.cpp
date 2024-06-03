#include <bits/stdc++.h>
using namespace std;

#define pa pair<int, int>
#define ff first
#define ss second 
#define long int

int SCORE = 0;
vector<int> visited;

void recursion(vector<int>& vec, int index, int score) 
{
	if (index >= vec.size() || visited[index] == 1)  return; 
	score += vec[index];
	int prev = index;
	index += vec[index];
	visited[prev] = 1;
	if (score > SCORE) SCORE = score;
	recursion(vec, index, score);
}

void solve()
{
	int n; cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		visited.push_back(-1);
	}
	for (int i = 0; i < n; i++) {
		recursion(vec, i, 0);
	}
	cout << SCORE << '\n';
	for (int i = 0; i < n; i++) {
		visited[i] = -1;
	}
	SCORE=0;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--)
		solve();
}
