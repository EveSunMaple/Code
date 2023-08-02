#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

long long n;
int p[20] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
long long maxn = -1, ans = -1;

void get(long long sum, long long crd, long long has, long long cnt)
{
    if (has > maxn || (has == maxn && sum < ans))
        ans = sum, maxn = has;
    long long now = sum;
    long long temp = 0;
    for (long long j = 1; j <= cnt; j++)
    {
        if (n / now < p[crd]) break;
        temp = has * (j + 1);
        now = now * p[crd];
        if (now <= n) get(now, crd + 1, temp, j);
    }
}

int main()
{
    scanf("%lld", &n);
    ans = 0;
    maxn = 0;
    get(1, 1, 1, 30);
    printf("%lld", ans);
}