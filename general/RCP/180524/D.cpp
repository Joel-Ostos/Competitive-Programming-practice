#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define pb push_back
#define pii pair<int, int> 
#define vi vector<int> 
#define vvi vector<vector<int>>
#define ff first
#define ss second
//#define int int16_t

int prec(char c) {
    if (c == '*') return 2;
    else if (c == '+') return 1;
    return -1;
}
 
string infixToPostfix(vector<string>& s) {
    stack<char> st;
    string result;
    for (int i = 0; i < s.size(); i++) {
	    if (s[i].size()>1) {
		    string a = s[i]; stoi(a);
		    result += a[0];
		    result += a[1];
		    result += " ";
	    } else if (s[i].size() == 1) {
		    char c = s[i][0];
		    bool pass = 0;
		    if (isdigit(c)) {
			    result += c;
			    result += " ";
		    }
		    else {
		            while (!st.empty() && prec(c) < prec(st.top()) || !st.empty() && prec(c) == prec(st.top())) {
		        	    result += st.top();
		        	    result += ' ';
		        	    st.pop();
		            }
		            st.push(c);
		    }
	    }
    }
 
    while (!st.empty()) {
        result += st.top();
        result += ' ';
        st.pop();
    }
    return result;
}

int eval(string exp)
{
    stack<int> st;

    for (int i = 0; exp[i]; ++i) {
         
        if (exp[i] == ' ')
            continue;
 
        else if (isdigit(exp[i])) {
            int num = 0;
 
            while (isdigit(exp[i])) {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;
 
            st.push(num);
        }
 
        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
 
            switch (exp[i]) {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            }
        }
    }
    return st.top();
}

void solve()
{
	int n; cin >> n;
	int k; cin >> k;
	vector<string> vec((n*2)-1);
	for (int i = 0; i < (n*2)-1; i++) {
		string tmp; cin >> tmp;
		vec[i]=tmp;
	}

	string st = infixToPostfix(vec);

	if (eval(st)%2==0) {
		cout <<  "even" << '\n';
	} else cout <<  "odd" << '\n';

	for (int i = 0; i < k; i++) {
		int f; cin >> f;
		string s; cin >> s;
		vec[(f-1)*2] = s;
		int res = eval(infixToPostfix(vec));
		if (res%2==0) {
			cout <<  "even" << '\n';
			continue;
		}
		cout <<  "odd" << '\n';
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
