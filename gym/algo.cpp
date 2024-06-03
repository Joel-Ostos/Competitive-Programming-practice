#ifndef _ALGO_H_
#define _ALGO_H_

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#define pb push_back
using namespace std;

// Prime Factorization

template<class T>
vector<T> prime_factorization(T n)
{
	vector<T> vec;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			vec.pb(i);
			n/=i;
		}
	}
	if (n>1) vec.pb(n);
	return vec;
}

template<class T>
vector<T> sieve (T n) {
	vector<T> prime;
	bool is_composite[n+1];
	fill(is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.pb(i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
	return prime;
}

#endif
