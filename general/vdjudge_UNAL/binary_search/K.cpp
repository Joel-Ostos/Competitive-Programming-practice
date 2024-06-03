#include <bits/stdc++.h>
using namespace std;

void recursion(string str, set<string>& st,int index, string actual, int n) 
{
	if (actual.size()==n) {
		st.insert(actual);
		return;
	}
	for (int i = 0; i < str.size(); i++) {
		string tmp = actual;
		string an = str;
		tmp.push_back(an[i]);
		an.erase(an.begin()+i);
		recursion(an, st, i, tmp, n);
	}
}

void solve()
{
	string str; cin >> str;
	set<string> st;
	recursion(str, st, -1, "",str.size());
	cout << st.size() <<'\n';
	for (auto a: st) cout << a << '\n';
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
