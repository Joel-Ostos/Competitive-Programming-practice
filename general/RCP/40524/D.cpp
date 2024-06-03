#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

bool isvowel(char a) 
{
	string v = "aeiou";
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == a) {
			return 1;
		}
	}
	return false;
}

void solve() 
{
	string a,b; cin >> a >> b;
	string s1; string s2;
	s1.pb(a[0]); 
	s2.pb(b[b.size()-1]);
	bool st = 0;
	char vowel = 'a';
	for (int i = 1; i < a.size(); i++) {
		if (!isvowel(a[i])) {
			s1.pb(a[i]);
			continue;
		} 
		vowel = a[i];
		st = 1;
		break;
	}
	for (int i = b.size()-2; i >= 0; i--) {
		if (!isvowel(b[i])) {
			s2.insert(s2.begin(), b[i]);
			continue;
		} 
		vowel = b[i];
		st = 1;
		break;
	}
	if (st) s1 += vowel;
	else s1 += 'o';
	s1 += s2;
	cout << s1 << '\n';
}

int32_t main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
