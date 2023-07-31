#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 20005

using namespace std;

struct coin
{
    long long sum = 0;
    long long line = 0;
    long long hide = 0;
    coin(long long a, long long b, long long c)
    {
        sum = a;
        line = b;
        hide = c;
    }
    coin()
    {
        sum = 0;
        line = 0;
        hide = 0;
    }
};

coin dp[N][2];
int s[N], h[N]; // S -> $ | h -> honour
int all[N];
//int num[N];
int n, m;

int main()
{
    freopen("coin.in", "r", stdin);
    freopen("coin.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &s[i]);
    for(int i = 1; i <= m; i++)
    {
        long long c, y;
        scanf("%lld%lld", &c, &y);
        h[c] = y;
    }
    for(int i = 1; i <= n; i++)
        { all[i] = all[i - 1] + h[i];  /*num[i] = num[i - 1] + s[i];*/ }

    for(int i = 1; i <= n; i++)
    {
        //
        dp[i][0] = coin(max(dp[i - 1][0].sum, dp[i - 1][1].sum), 0, all[n - i]);
        //
        coin dp_up_0 = coin(dp[i - 1][0].sum + s[i], 1, all[n - i + 1] - all[1]);
        coin dp_up_1 = coin(dp[i - 1][1].sum + s[i], dp[i - 1][1].line + 1, all[n - i + dp[i - 1][1].line + 1] - all[dp[i - 1][1].line + 1]);
        if(h[dp_up_0.line]) { dp_up_0.sum += h[dp_up_0.line]; /*dp_up_0.hide -= h[dp_up_0.line];*/ }
        if(h[dp_up_1.line]) { dp_up_1.sum += h[dp_up_1.line]; /*dp_up_1.hide -= h[dp_up_1.line];*/ }
        //printf("%d:\n dp[i][0]:%d  %d  %d\n dp_up_0:%d  %d  %d\n dp_up_1:%d  %d  %d\n", i, dp[i][0].sum, dp[i][0].line, dp[i][0].hide, dp_up_0.sum, dp_up_0.line, dp_up_0.hide, dp_up_1.sum, dp_up_1.line, dp_up_1.hide);
        if(dp_up_0.sum + dp_up_0.hide >= dp_up_1.sum + dp_up_1.hide) dp[i][1] = dp_up_0;
        else dp[i][1] = dp_up_1;
    }

    printf("%lld", max(dp[n][0].sum, dp[n][1].sum));

    return 0;
}