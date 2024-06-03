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
 
string infixToPostfix(string& s) {
    stack<char> st;
    string result;
 
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        if (isdigit(c)){
	    result += c;
            result += ' ';
	}
 
        else if (c == '(') st.push('(');
 
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
		result += ' ';
                st.pop();
            }
            st.pop(); // Pop '('
        }
 
        else {
            while (!st.empty() && prec(s[i]) < prec(st.top()) ||
                   !st.empty() && prec(s[i]) == prec(st.top())) {
                result += st.top();
		result += ' ';
                st.pop();
            }
            st.push(c);
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
	int l; cin >> l;
	string str; cin >> str;
	string tmp = str;
	for (int i = 1; i < str.size(); i++) {
		string exp;
		if (str[i-1] == ')' and str[i] == '(') {
			exp+="*";
			str.insert(i, exp);
		}
		else if (str[i-1] == '(' and str[i] == ')') {
			exp+="1";
			str.insert(i, exp);
		}
		else if (str[i-1] == ')' and str[i] == ')') {
			exp+="+1";
			str.insert(i, exp);
		}
	}
	cout <<  eval(infixToPostfix(str)) << '\n';
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
