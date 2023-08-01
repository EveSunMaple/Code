#include <iostream>
#include <cstring>
#include <cstdio>
#define N 2005

using namespace std;

int dp[N][N];
int ans[N];
int a[N];
int b[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
    for (int x = 0; x < a[1]; x++) dp[1][x] = b[1];
    dp[1][a[1]] = 0;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= n; j++) dp[i][j] = 0x7fffffff;
    int sumA = a[1];
    for (int k = 2; k <= n; k++)
    {
        sumA += a[k];
        ans[k] = 0x7fffffff;
        for (int x = 0; x <= sumA; x++)
        {
            if (x < a[k]) dp[k][x] = dp[k - 1][x] + b[k];
            else dp[k][x] = min(dp[k - 1][x] + b[k], dp[k - 1][x - a[k]]);
            ans[k] = min(ans[k], max(x, dp[k][x]));
        }
    }
    printf("%d", ans[n]);
    return 0;
}