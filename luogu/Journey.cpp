#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 5005

using namespace std;

struct node
{
    int ver;
    int edge;    
    node(int a, int b)
    {
        ver = a;
        edge = b;
    }
    node()
    {
        ver = edge = 0;
    }
};
vector<vector<node>> g(N);
vector<int> s;
int deg[N];
int dp[N][N];
int q[N], p[N][N];
int l = 0, r = 0;
int n, m, T;

void out(int net, int sum)
{
    if(net != 0) out(p[net][sum], sum - 1);
    if(net != 0) printf("%d ", net);
}

int main()
{
    scanf("%d%d%d", &n, &m, &T);

    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(node(v, w));
        deg[v]++;
    }

    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 0)
        {
            q[++r] = i;
        }
    }
    
    while(l < r)
    {
        for(int i = l; i <= r; i++)
        {
            int u = q[++l];
		    s.push_back(u);
            for(node v : g[u])
            {
                if(--deg[v.ver] == 0) q[++r] = v.ver;
                //if(dp[u].edge + v.edge <= T)
                //{
                //    //if(dp[u].ver + 1 > dp[v.ver].ver)
                //    //{
                //    //    p[v.ver] = u;
                //    //    dp[v.ver].ver = dp[u].ver + 1;
                //    //    dp[v.ver].edge = dp[u].edge + v.edge;
                //    //}
                //    /*else */if(/*dp[u].ver + 1 == dp[v.ver].ver &&*/ dp[u].edge + v.edge < dp[v.ver].edge)
                //    {
                //        p[v.ver] = u;
                //        dp[v.ver].ver = dp[u].ver + 1;
                //        dp[v.ver].edge = dp[u].edge + v.edge;
                //    }
                //}
            }
        }
    }
    dp[1][1] = 0;
	for(int i = 0; i < s.size(); i++)
	{
		int u = s[i];
        for(node v : g[u])
            for(int j = 2; j <= n; j++) // 枚举经过点数
		        if(dp[u][j - 1] + v.edge < dp[v.ver][j]) // 如果当前路径和比原先的好
		        {
		        	dp[v.ver][j] = dp[u][j - 1] + v.edge; // 更新
		        	p[v.ver][j] = u; // 记录路径中的上一个点
		        }
    }
    for(int i = n; i >= 0; i--)
    {
        if(dp[n][i] <= T)
        {
            printf("%d\n", i);
            out(n, i); break;
        }
    }

    return 0;
}