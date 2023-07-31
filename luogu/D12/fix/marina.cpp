#include <iostream>
#include <cstring>
#include <cstdio>
#define N 2000005
#define mod 998244353

using namespace std;

long long val[N]; // 预处理阶乘

long long exgcd(long long m, long long n, long long &a, long long &b) // 回溯时改变a与b的原值
{
    if (n == 0)
        { a = 1; b = 0; return m; }               // n = 0计算结束，回溯开始
    long long d = exgcd(n, m % n, a, b);          // 工具人d存值
    long long c = a; a = b; b = c - b * (m / n);  // 工具人c
    return d;
}

long long C(int a, int b) 
{
    // 求在a中取b 
    // 得a * (a - 1) * (a - 2) * ... * (a - b + 1) / b * (b - 1) * (b - 2) * ... * 1
    if (a < b
     || a < 0
     || b < 0) return 0;
    long long temp = 0;
    long long temp_a = 0;
    long long temp_b = 0;
    long long d = exgcd(val[b], mod, temp_a, temp);
    temp_a = (temp_a % mod + mod) % mod; // 这是val[b]的逆元
    temp = 0;
    d = exgcd(val[a - b], mod, temp_b, temp);
    temp_b = (temp_b % mod + mod) % mod; // 这是val[a - b]的逆元
    return val[a] * temp_a % mod * temp_b % mod;
}

long long calc(int a, int b)
{
    return (C(a * 2, a) - C(a * 2, a - b - 1) + mod) % mod;
}

int main()
{
    freopen("marina.in", "r", stdin);
    freopen("marina.out", "w", stdout);
    val[0] = 1;
    int n = 0, m = 0; 
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * 2; i++) val[i] = val[i - 1] * i % mod;
    if (m == 0) printf("%lld", calc(n, 0));
    else printf("%lld", (C(n * 2, n - m) - C(n * 2, n - m - 1) + mod) % mod);
    return 0;
}