#pragma GCC optimize ("O2")
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 100005
#define ll long long

using namespace std;

int a[N];
int tag[256];
int sor[N][256];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i <= 255; i++)
    {
        for (int t = 0; t < 8; t++)
            if ((i >> t) & 1) tag[i]++;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        for (int t = 0; t <= 255; t++)
        {
            sor[i][t] = sor[i - 1][t];
            if ((a[i] | t) == t) sor[i][t]++;
        }
    }
    while (q--)
    {
        int l, r, x = 0;
        scanf("%d%d%d", &l, &r, &x);
        // ll ans = sor[r][x] - sor[l - 1][x];
        ll ans = 0;
        for (int t = 0; t <= 255; t++)
        {
            if ((x | t) > x) continue;
            ll tmp = sor[r][t] - sor[l - 1][t];
            if ((tag[x] - tag[t]) & 1) { ans -= tmp; printf("%d CUT %lld\n", t, tmp); }
            else { ans += tmp; printf("%d ADD %lld\n", t, tmp); }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
