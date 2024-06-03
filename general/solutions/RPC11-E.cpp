#include <bits/stdc++.h>
using namespace std;

#define pa pair<int, int>
//#define ff first
//#define ss second 
//#define long int

int sum(vector<int>& vec, int range) {
	int actual_sum = 0;
	for (int i = 0; i < range; i++) {
		actual_sum += vec[i];
	}
	return actual_sum;
}

void backtrack(vector<vector<int>>& result, vector<int>& current, int index, int sum, int target, int spaces) {
    if (index > spaces || sum > target) return;
    if (index == spaces) {
        if (sum == target) {
            result.push_back(current);
        }
        return;
    }

    for (int i = 0; i <= target - sum; i++) {
        current[index] = i;
        backtrack(result, current, index + 1, sum + i, target, spaces);
    }
}

vector<vector<int>> combinations(int target, int spaces) {
    vector<vector<int>> result;
    vector<int> current(spaces, 0);
    backtrack(result, current, 0, 0, target, spaces);
    return result;
}

void solve()
{
	int n, target, max_sum = 0;
	cin >> n >> target;
	vector<vector<int>> pool(n, vector<int>(12));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 12; j++) {
			cin >> pool[i][j];
		}
	}
	vector<int> comb;
	vector<vector<int>> dim = combinations(target, n);
	for (int i = 0; i < dim.size(); i++) {
		int actual = 0;
		for (int j = 0; j < n; j++) {
			actual += sum(pool[j], dim[i][j]);
			if (actual > max_sum) max_sum = actual;
		}
	}
	cout << max_sum << '\n';
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t=1;
	while(t--) {
		solve();
	}
}
