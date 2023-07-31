#include <cstdio>
using namespace std;
const int maxn = 2001000;
const long long md = 998244353;
long long fac[maxn], inv[maxn];
long long powd(long long x, int y)
{
	long long ret = 1;
	x %= md;
	while (y)
	{
		if (y & 1) ret = ret * x % md;
		x = x * x % md;
		y >>= 1;
	}
	return ret;
}
long long C(int x, int y)
{
	if (x < y) 			return 0;
	if (y < 0 || x < 0) return 0;
	return fac[x] * inv[y] % md * inv[x - y] % md;
}
long long excatalan(int x, int y)
{
	return (C(x * 2, x) - C(x * 2, x - y - 1) + md) % md;
}
int main()
{
	freopen("marina.in", "r", stdin);
	freopen("marina.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	fac[0] = 1;
	for (int i = 1; i <= n * 2; i++) fac[i] = fac[i - 1] * i % md;
	inv[n * 2] = powd(fac[n * 2], md - 2);
	for (int i = n * 2; i >= 1; i--) inv[i - 1] = inv[i] * i % md;
	if (m == 0) printf("%lld\n", excatalan(n, 0));
	else printf("%lld\n", (excatalan(n, m) - excatalan(n, m + 1) + md) % md);
	return 0;
}
