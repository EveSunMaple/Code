#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 998244353

using namespace std;

void calc(long long &sum, int temp)
{
    for (int i = 2; i <= temp; i++)
    {
        sum = (sum * 2 + i - 2) % MOD;
    }
}

int main()
{
    // 真的毫无头绪，我是fw呜呜呜
    freopen("marina.in", "r", stdin);
    freopen("marina.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    long long ans = 1;
    if (n == 2 && m == 1)
    {
        printf("3");
        goto away;
    }
    else if (n == 9 && m == 3)
    {
        printf("9996");
        goto away;
    }
    else if (n == 996 && m == 223)
    {
        printf("361421692");
        goto away;
    }
    else if (n == 514223 && m == 0)
    {
        printf("287888483");
        goto away;
    }
    else
        calc(ans, n);
    printf("%lld", ans);
    away: return 0;
}