#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 100005
#define mod 1000000007

using namespace std;

int fa[N * 2];

int getfa(int a)
{
    return fa[a] == a ? a : fa[a] = getfa(fa[a]);
}

int main()
{
    int n, q, tot = 0;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n * 2; i++) fa[i] = i;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
    }
    for (int i = 1; i <= q; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (w == 0)
        {
            fa[getfa(u)] = getfa(v);
            fa[getfa(u + n)] = getfa(v + n);
        }
        else
        {
            fa[getfa(u)] = getfa(v + n);
            fa[getfa(u + n)] = getfa(v);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (getfa(i) == getfa(i + n))
        {
            printf("0");
            return 0;
        }
        if (getfa(i) == i) tot++;
    }
    long long ans = 1ll;
    for (int i = 1; i <= tot - 1; i++)
    {
        ans <<= 1;
        ans %= mod;
    }
    printf("%lld", ans);
    return 0;
}