#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long ll;
const int maxn = 1000005;
int n;
int a[maxn], sum[maxn], buc[maxn], son[maxn][2];
int top, now[maxn];
ll qpow(ll x, ll y) {
	ll ans = 1, base = x;
	while(y) {
		if(y & 1) {
			ans = ans * base % mod;
		}
		base = base * base % mod;
		y >>= 1;
	}
	return ans;
}
ll calc(int x) {
	ll ans = 1;
	sum[x] = 1;
	if(son[x][0] != 0) {
		ans = ans * calc(son[x][0]) % mod;
		sum[x] += sum[son[x][0]];
	}
	if(son[x][1] != 0) {
		ans = ans * calc(son[x][1]) % mod;
		sum[x] += sum[son[x][1]];
	}
	return ans * qpow(sum[x], mod - 2) % mod;
}
ll solve() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i <= n; ++i) {
		buc[i] = -1;
		son[i][0] = son[i][1] = 0;
	}
	now[++top] = -1;
	for(int i = n; i >= 1; --i) {
		int pos = a[i];
		if(pos >= i) {
			return 0;
		}
		if(buc[pos] == -1) {
			son[pos][1] = i;
			buc[pos] = i;
		} else {
			son[buc[pos]][0] = i;
			buc[pos] = i;
		}
		if(now[top] == i) {
			--top;
		} else if(pos < now[top]) {
			return 0;
		}
		if(now[top] != pos) {
			now[++top] = pos;
		}
	}
	ll ans = calc(0);
	for(int i = 1; i <= n + 1; ++i) {
		ans = ans * i % mod;
	}
	return ans;
}
int main() {
	freopen("white.in", "r", stdin);
	freopen("white.out", "w", stdout);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--) {
		cout << solve() << endl;
	}
	return 0;
}

