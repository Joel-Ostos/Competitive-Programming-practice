#include <bits/stdc++.h>
using namespace std;
#define int long long

int binary_exp(int base, int exp) {
  int res = 1;
  int actual = base;
  while (exp>0) {
    if (exp & 1) res*=actual;
    actual *= actual;
    exp >>= 1;
  }
  return res;
}

int32_t main()
{
  cout << binary_exp(2,30) << " " << pow(2,30) << '\n';
}
