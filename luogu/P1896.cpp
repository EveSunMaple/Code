#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

long long dp[10][2000][100];
int sit[2000]; //预处理情况数
int num[2000]; //对应的国王数
int cnt = 0; //有几种情况
int N, K;

void dfs(int t, int sum, int crd)
{
    if(crd >= N) //如果超出边界，返回
    {
        sit[++cnt] = t;
        num[cnt] = sum;
        return;
    }
    dfs(t, sum, crd + 1); //这里不加国王，crd下标只加一
    dfs(t + (1 << crd), sum + 1, crd + 2); //这里增加国王，因为国王不能相邻所以crd下标加二
}
int main()
{
    scanf("%d%d", &N, &K);
    dfs(0, 0, 0); //计算上一层什么都不放可能的方案数

    for(int i = 1; i <= cnt; i++) dp[1][i][num[i]] = 1; //初始化什么都不放也是一种情况

    for(int i = 2; i <= N; i++)
    {
        for(int j = 1; j <= cnt; j++) //枚举这一层的情况
        {
            for(int k = 1; k <= cnt; k++)//枚举上一层的情况
            {
                if(sit[j] & sit[k]) continue; //如果有两种国王重合，跳过
                if((sit[j] << 1) & sit[k]) continue; //因为国王的判定范围为一个圈，左移
                if(sit[j] & (sit[k] << 1)) continue; //因为国王的判定范围为一个圈，右移
                for(int s = K; s >= num[j]; s--) 
                    dp[i][j][s] += dp[i - 1][k][s - num[j]]; //枚举合法的国王数
            }
        }
    }
    long long ans = 0;
    for(int i = 1;i <= cnt; i++) ans += dp[N][i][K]; //把所有合法情况加起来

    printf("%lld", ans);

    return 0;
}