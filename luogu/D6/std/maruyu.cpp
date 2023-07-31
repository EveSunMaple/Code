#include <cstdio>

using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

int T;
ll n, k;

ll pow(ll a, ll b)
{
	a %= mod; ll ans = 1;
	for(; b; b >>= 1)
	{
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
	}
	return ans;
}

int main()
{
	freopen("maruyu.in", "r", stdin);
	freopen("maruyu.out", "w", stdout); 
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld", &n, &k);
		printf("%d\n", pow(2LL, k) * (pow(pow(2ll, n) - 1, k) - pow(pow(2LL, n) - 2, k) + mod) % mod);
	}
	return 0;
}
