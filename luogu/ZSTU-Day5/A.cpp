#pragma GCC optimize ("O2")
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 100005

using namespace std;

int a[N];
int dp[1000];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    while (q--)
    {
        int l, r, x, ans = 0;
        scanf("%d%d%d", &l, &r, &x);
        memset(dp, 0, sizeof(dp));
        vector<int> fix;
        for (int i = l; i <= r; i++)
        {
            if ((a[i] | x) > x) continue;
            fix.push_back(a[i]);
        }
        for (unsigned int i = 0; i < fix.size() - 1; i++)
        {
            for (unsigned int j = 0; j < i; j++) dp[fix[j] | fix[i]]++;
            for (int t = 1; t <= 255; t++)
                if ((t | fix[i + 1]) == x) ans += dp[t];
        }
        printf("%d\n", ans);
    }
    return 0;
}
