#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define int long long
#define pb push_back

void solve()
{
	int n; cin >> n;
	int k; cin >> k;
	vector<string> vec((n*2)-1);
	vector<int> pos;
	for (int i = 0; i < (n*2)-1; i++) {
		string tmp; cin >> tmp;
		if (tmp == "*") pos.pb(i);
		vec[i]=tmp;
	}
	for (int i = 0; i < pos.size(); i++) {
		int a = stoi(vec[pos[i]-1]);
		int b = stoi(vec[pos[i]+1]);
		if ((a%2==0 and b%2==0) || (a%2==0 and b%2==1) || (a%2==1 and b%2==0)) {
			vec[pos[i]] = "*";
			vec[pos[i]-1] = "0";
			vec[pos[i]+1] = "0";
			continue;
		} 
		vec[pos[i]] = "*";
		vec[pos[i]+1] = "1";
		vec[pos[i]-1] = "1";
	}
	
	int n_p , n_o = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (i+3 < vec.size() and vec[i+3]=='*') {
			if (stoi(vec[i+2])%2==0 and stoi(vec[i+2])%2==0) {
			}
			vec[i+2] = vec[i+4] = ;
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i]=='0') n_p++;
		else if (vec[i]=='1') n_o++;
	}
	cout << n_o <<  " " << n_p << '\n';
	if (!(n_o%2)) {
		cout << "even\n";
	} else {
		cout << "odd\n";
	}
	for (auto a: vec) cout << a << " ";
	cout << '\n';
	cout << "--------\n";

	for (int j = 0; j < k; j++) {
		int t; cin >> t;
		string tmp; cin >> tmp;
		if (stoi(vec[(t-1)*2])%2==0 and stoi(tmp)%2==1) {
			vec[(t-1)*2] = to_string(stoi(tmp)%2);
			n_o++;
			n_p--;
		} else if (stoi(vec[(t-1)*2])%2==1 and stoi(tmp)%2==0){
			vec[(t-1)*2] = to_string(stoi(tmp)%2);
			n_o--;
			n_p++;
		}
		cout << n_o <<  " " << n_p << '\n';
		for (auto a: vec) cout << a << " ";
		cout << '\n';
		if (!(n_o%2)) {
			cout << "even\n";
			continue;
		}
		cout << "odd\n";
	}
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
