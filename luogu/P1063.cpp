#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

struct point
{
    int l = 0;
    int r = 0;
    int sum = 0;
}node[205], dp[205][205];

int ans = 0;

int main()
{
    int N; scanf("%d", &N);
    for(int i = 1; i < N; i++)
    {
        int t; scanf("%d", &t);
        node[i].l = t;
        node[i - 1].r = t;
        node[i + N].l = t;
        node[i + N - 1].r = t;
    }
    int n; scanf("%d", &n);
    node[N].l = n; node[N - 1].r = n; node[N].r = node[1].l;
    node[N * 2].l = n; node[N * 2 - 1].r = n; node[N * 2].r = node[1].l;
    
    //for(int t = 1; t <= N * 2; t++)
    //{
    //    printf("l: %d   r: %d\n", node[t].l, node[t].r);
    //}

    for(int t = 1; t <= N; t++)
    {
        memset(dp, 0, sizeof(dp));
        for(int i = t; i < t + N; i++)
        {
            dp[i][i].l = node[i].l;
            dp[i][i].r = node[i].r;
        }
        for(int len = 2; len <= N; len++)
        {
            for(int l = t; l <= N - len + 1 + t; l++)
            {
                int r = l + len - 1;
                for(int k = l; k < r; k++)
                {
                    int now = dp[l][k].l *  dp[l][k].r * dp[k + 1][r].r + dp[l][k].sum + dp[k + 1][r].sum;
                    if(dp[l][r].sum < now)
                    {
                        dp[l][r].sum = now;
                        dp[l][r].l = dp[l][k].l;
                        dp[l][r].r = dp[k + 1][r].r;
                    }
                }
                ans = max(ans, dp[l][r].sum);
            }
        }
    }

    printf("%d", ans);

    return 0;
}