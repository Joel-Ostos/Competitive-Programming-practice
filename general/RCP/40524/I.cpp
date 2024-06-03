#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define ff first
#define ss second
#define psi pair<string, int>

int R = 0;

void solve(string l, int t, int cn, int aes, int bes, int ces) 
{

	if (cn==t) {
		R++;
		return;
	}
	if (aes < 0 || bes < 0 || ces < 0) return;
	if (aes == 0 && bes == 0 && ces == 0) return;
	if (l.size() == 0) {
		if (aes>0) solve("A", t, cn+1, aes-1, bes, ces); 
		if (bes>0) solve("B", t, cn+1, aes, bes-1, ces);
		if (ces>0) solve("C", t, cn+1, aes, bes, ces-1);
	}
	if (l[0] != 'A') {
		if (bes>0) {
			solve("B", t, cn+1, aes, bes-1, ces);
		} 
		if (ces>0) {
			solve("C", t, cn+1, aes, bes, ces-1);
		} 
	} else if (l[0] != 'B') {
		if (aes>0) {
			solve("A", t, cn+1, aes-1, bes, ces);
		} 
		if (ces>0) {
			solve("C", t, cn+1, aes, bes, ces-1);
		} 
	} else if (l[0] != 'C') {
		if (aes>0) {
			solve("A", t, cn+1, aes-1, bes, ces);
		} 
		if (bes>0) {
			solve("B", t, cn+1, aes, bes, ces-1);
		} 
	}
}

int32_t main() 
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int aes, bes, ces; cin >> aes >> bes >> ces;
	int t = aes+bes+ces;
	solve("", t, 0, aes, bes, ces);
	cout << R <<'\n';
}
