#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
const ll mod = 1000000007;

ll powmod(ll a, ll b) {
	ll res = 1;
	a %= mod;
	assert(b >= 0);
	for (; b; b >>= 1) {
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
// head

const int N = 101000;
int _, n, val[N];
int cnt[40];
VI num;
int main() {
	freopen("andsum.in", "r", stdin);
	freopen("andsum.out", "w", stdout);
	scanf("%d", &n);
	rep(i, 1, n + 1) scanf("%d", val + i), num.pb(val[i]);
	ll ans = 0;
	sort(all(num));
	rep(j, 0, 30) cnt[j] = 0;
	for (auto x : num) {
		rep(j, 0, 30) if (x & (1 << j))
			ans = (ans + (ll)x * cnt[j] % mod * (1 << j)) % mod;
		rep(j, 0, 30) if (x & (1 << j))
			cnt[j]++;
	}
	printf("%lld\n", ans);
}
