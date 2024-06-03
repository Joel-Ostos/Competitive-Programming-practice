#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

struct comp {
    bool operator() (const pair<int, string>& p1, const pair<int, string>& p2) const {
		if (p1.first == p2.first) {
			return p1.second < p2.second;
		}
		return p1.first  > p2.first;
    }
};

void solve() 
{
	int n, k; cin >> n >> k;
	set<pair<int, string>, comp> q;
	unordered_map<string, int> p;
	for (int i = 0; i < n; i++) {
		string name; cin >> name;
		int tmp; cin >> tmp;
		pair<int, string> em;
		em.first = tmp; em.second = name;
		q.insert(q.begin(), em);
		p[em.second] = em.first;
	}
	for (int i = 0; i < k; i++) {
		int act; cin >> act;
		if (act == 1) {
			string name; cin >> name;
			int tmp; cin >> tmp;
			pair<int, string> nas;
			nas.first = p[name];
			nas.second = name;
			auto i = q.find(nas);
			if (i!=q.end()) {
				pair<int, string> na;
				na.first = (*i).first+tmp; na.second = (*i).second;
				p[name] = na.first;
				q.erase(i);
				q.insert(na);
			}
		} else {
			auto fired = q.begin();
			cout << (*fired).second << " " << (*fired).first << '\n';
			q.erase(fired);
		}
	}
}

int32_t main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
