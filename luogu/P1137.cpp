#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 100005

using namespace std;

vector<vector<int>> g(N);
int deg[N];
int dp[N];
int q[N];
int l = 0, r = 0;
int n, m;

int main()
{
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        deg[v]++;
    }

    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 0)
        {
            q[++r] = i;
            dp[i] = 1;
        }
    }
    while(l < r)
    {
        for(int i = l; i <= r; i++)
        {
            int u = q[++l];
            for(int v : g[u])
            {
                dp[v] = max(dp[v], dp[u] + 1);
                if(--deg[v] == 0) q[++r] = v;
            }
        }
    }

    for(int i = 1; i <= n; i++)
        printf("%d\n", dp[i]);

    return 0;
}