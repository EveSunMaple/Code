#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define ll long long
#define mod 1000000007

using namespace std;

ll pow(ll a, ll b)
{
	a %= mod; 
    ll ans = 1;
	for(; b; b >>= 1)
	{
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
	}
	return ans;
}

int main()
{
    fastio;
    freopen("maruyu.in", "r", stdin);
    freopen("maruyu.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll n, k;
        scanf("%lld%lld", &n, &k);

        // 首先明确题目，我们不需要取完所有的K种物品
        // 那么我们枚举i(1~k)假设有i种物品没有被取
        // 一共就是C(i, k) * 2 ^ i种情况
        // 开始考虑其他取走的物品
        // 因为题目有两个条件，我们先考虑不受影响的1~n - 1
        // 每一条船可以取也可以不取，一共是2 ^ (n - 1)种情况
        // 那么如果都是1或者都是0是会影响的，我们暂时去掉-2
        // 考虑前后两个，都有01两种情况，一共四种使用乘法公式
        // 最后我们要把之前去掉的情况补回来，有下面四种情况
        // - 0 111111111111...111
        // - 0 111111111111...110
        // - 1 000000000000...001
        // - 1 000000000000...000
        // 那么最后我们还要计算所有剩下的情况，一共是^(k - i)
        // 此时结果是：i : [1~K] C(i, k) * (2 ^ i) * ((2 ^ (n - 1)) * 4 + 4) ^ (k - i)
        // 我们可以用二项式定理化简：
        // - 二项式定理：(a + b) ^ k = i : [0~k] C(i, k) * a ^ i * b ^ (k - i)
        // 我们把(2 ^ (n - 1)) * 4 + 4)当做r
        // 此时式子为                          i : [1~K] C(i, k) * 2 ^ i * r ^ (k - i)
        // 显然我们发现这个式子和 (2 + r) ^ k = i : [0~k] C(i, k) * 2 ^ i * r ^ (k - i)很像
        // 但是我们的i是从1开始的，二项式定理的i是从0开始
        // 所以我们最后要剪去多余的0
        // 最后化简的式子为: (2 + r) ^ k - r ^ k
        // 整理得 ans = 2 ^ k * ((2 ^ n - 1) ^ k - (2 ^ n - 2) ^ k)

        printf("%d\n", pow(2LL, k) * (pow(pow(2ll, n) - 1, k) - pow(pow(2LL, n) - 2, k) + mod) % mod);
    }
    return 0;
}