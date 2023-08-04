#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

#define ll long long

using namespace std;

const ll N = 2e5 + 10, MAXN = 2e18 + 10;
ll n, a[N], cnt, nxt[N], last, k, x, y, idx, ans;

int main()
{
    scanf("%lld%lld", &n, &k);

    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1 && a[i - 1] != 1) last = i;
        if (a[i] != 1 && a[i - 1] == 1) nxt[last] = i;
        if (a[i] == 1 && i == n) nxt[last] = n + 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1 && a[i - 1] == 1) nxt[i] = nxt[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        cnt = 0, x = 1, y = 0, idx = i;
        while (x < MAXN && cnt < 20 && idx <= n)
        {
            if (a[idx] == 1)
            {
                if (x % k == 0 && ((x / k) > y && (x / k) <= y + (nxt[idx] - idx))) ans++;
                y += nxt[idx] - idx;
                idx = nxt[idx];
            }
            else
            {
                x *= a[idx], y += a[idx];
                if (x / k == y) ans++;
                idx++, cnt++;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}