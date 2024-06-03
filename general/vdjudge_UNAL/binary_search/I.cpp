#include <bits/stdc++.h>
using namespace std;

#define ll long long

int solve()
{
	int a,b,c,n;
	cin >> a >> b >> c >> n;
	if (c>a || c>b) return -1;
	int res = n-(a+b-c);
	if (res<=0) return -1;
	return res;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << solve() <<'\n';
}
