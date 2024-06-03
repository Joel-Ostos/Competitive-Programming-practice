#include <bits/stdc++.h>
using namespace std;

#define pa pair<int, int>
#define ff first
#define ss second 
#define int long long

void solve()
{
	int n;
	cin >> n;
	vector<int> all(n), odds, even;
	for (int i = 0; i < n; i++) {
		cin >> all[i];
		if (all[i] % 2) {
			odds.push_back(all[i]);
		} else {
			even.push_back(all[i]);
		}
	}
	sort(odds.begin(), odds.end(), greater<int>()); 
	sort(even.begin(), even.end(), greater<int>());
	int turn=1, i_even=0, i_odds=0, al_score=0, b_score=0;
	int numbers=0;
	while(numbers<n) {
			  if (turn==1) {
						 turn = 2;
						 numbers++;
						 if (i_even < even.size() && i_odds < odds.size()) {
									if (even[i_even] >= odds[i_odds]) {
											  al_score+=even[i_even];
											  i_even++;
									} else {
											  i_odds++;
									}
						 } else if (i_even < even.size() && i_odds >= odds.size()) {
											  al_score+=even[i_even];
											  i_even++;
						 } else if (i_even >= even.size() && i_odds < odds.size()) {
											  i_odds++;
						 }
						 if (numbers>=n) {
									break;
						 }
			  }
			  if (turn==2) {
						 turn = 1;
						 numbers++;
						 if (i_even < even.size() && i_odds < odds.size()) {
									if (even[i_even] <= odds[i_odds]) {
											  b_score += odds[i_odds];
											  i_odds++;
									} else {
											  i_even++;
									}
						 } else if (i_even < even.size() && i_odds >= odds.size()) {
									i_even++;
						 } else if (i_even >= even.size() && i_odds < odds.size()) {
									b_score += odds[i_odds];
									i_odds++;
						 }

			  }
	}
	if (al_score > b_score) {
			  cout << "Alice\n";
			  return;
	} else if (al_score < b_score) {
			  cout << "Bob\n";
			  return;
	} else if (al_score == b_score){
			  cout << "Tie\n";
	}
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
