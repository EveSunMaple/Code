#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 5005

using namespace std;

vector<vector<int>> g(N);
int outdeg[N];
int indeg[N];
int dp[N];
int q[N];
int l = 0, r = 0;
int sum;
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        outdeg[u]++;
        indeg[v]++;
    }

    for(int i = 1; i <= n; i++)
    {
        if(indeg[i] == 0)
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
            if(outdeg[u] == 0)
            {
                sum += dp[u];
                sum %= 80112002;
            }
            for(int v : g[u])
            {
                dp[v] += dp[u];
                dp[v] %= 80112002;
                if(--indeg[v] == 0) q[++r] = v;
            }
        }
    }

    printf("%d", sum);

    return 0;
}