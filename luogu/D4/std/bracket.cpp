#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define ull unsigned long long
#define fi first
#define se second
#define mk make_pair
#define PLL pair<LL, LL>
#define PLI pair<LL, int>
#define PII pair<int, int>
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(), (x).end()
#define fio ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

const int N = 1e7 + 7;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double PI = acos(-1);

template<class T, class S> inline void add(T &a, S b) {
	a += b;
	if (a >= mod)
		a -= mod;
}

template<class T, class S> inline void sub(T &a, S b) {
	a -= b;
	if (a < 0)
		a += mod;
}

template<class T, class S> inline bool chkmax(T &a, S b) {
	return a < b ? a = b, true : false;
}

template<class T, class S> inline bool chkmin(T &a, S b) {
	return a > b ? a = b, true : false;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
int stk[N], top;
int match[N], a[N], b[N], up[N];
int ans[N];
char s[N];

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);

	top = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') {
			up[i] = stk[top];
			stk[++top] = i;
		} else if (top) {
			match[i] = stk[top];
			match[stk[top]] = i;
			top--;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!match[i] || s[i] == '(')
			continue;
		b[i] = b[match[i] - 1] + 1;
	}

	for (int i = n; i >= 1; i--) {
		if (!match[i] || s[i] == ')')
			continue;
		a[i] = a[match[i] + 1] + 1;
	}

	for (int i = 1; i <= n; i++) {
		if (!match[i] || s[i] == ')')
			continue;
		ans[i] = 1LL * a[i] * b[match[i]] % mod;
		if (up[i])
			add(ans[i], ans[up[i]]);
		ans[match[i]] = ans[i];
	}

	LL ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += 1LL * ans[i] * i % mod;
	}

	printf("%lld\n", ret);

	return 0;
}
