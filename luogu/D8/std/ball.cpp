//{{{
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << x << endl;

typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;
const LL INFLL = LL(INF) * LL(INF);
template<class T> inline int size(const T &c) {
	return c.size();
}
int rint() {
	int x;
	if (scanf("%d", &x) != 1)
		return -1;
	return x;
}
LL rLL() {
	LL x;
	if (scanf("%lld", &x) != 1)
		return -1;
	return x;
}
//}}}

const int MOD = 500009;
const int MAXN = 2250000;

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	vector<int> ndivisors(MAXN + 1, 1);
	int p = 2;
	for (p = 2; p * p * p <= MAXN; ++p)
		if (ndivisors[p] == 1) {
			int pk = p;
			for (int k = 1;; ++k) {
				int mm = 0;
				for (int q = pk; q <= MAXN; q += pk) {
					++mm;
					if (mm == p)
						mm = 0;
					else
						ndivisors[q] *= k + 1;
				}
				LL pk2 = LL(pk) * p;
				if (pk2 > MAXN)
					break;
				pk = int(pk2);
			}
		}
	for (; p * p <= MAXN; ++p)
		if (ndivisors[p] == 1) {
			int pk = p;
			for (int k = 1; k <= 2; ++k) {
				int mm = 0;
				for (int q = pk; q <= MAXN; q += pk) {
					++mm;
					if (mm == p)
						mm = 0;
					else
						ndivisors[q] *= k + 1;
				}
				pk *= p;
			}
		}
	for (; p <= MAXN; ++p)
		if (ndivisors[p] == 1) {
			for (int q = p; q <= MAXN; q += p) {
				ndivisors[q] *= 2;
			}
		}
	vector<unsigned> cnt(MAXN + 1, 0);
	vector<unsigned> res(MAXN + 1, 0);
	res[0] = 1;
	for (int n = 1; n <= MAXN; ++n) {
		int d = ndivisors[n];
		++cnt[d];
		res[n] = res[n - 1] * (cnt[d] % 1024u) % unsigned(MOD);
		if (cnt[d] >= 1024u) {
			unsigned a = res[n - 1] * (cnt[d] >> 10) % unsigned(MOD);
			res[n] = (res[n] + (a << 10)) % unsigned(MOD);
		}
		if (res[n] == 0)
			break;
	}
	int ntc = rint();
	REP(tc, ntc) {
		int n = rint();
		int r = n <= MAXN ? res[n] : 0;
		printf("%d\n", r);
	}
}

