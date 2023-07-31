#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define MAX 50004

using namespace std;

vector<int> g[MAX];
int ans, up = 1e9;
int deep[MAX];
int sol[MAX];
int sum[MAX];
int n;

int init(int crd, int from)
{
    int now = 0;
    for(int son : g[crd])
    {
        if(son == from) continue;
        deep[son] = deep[crd] + 1;
        now += init(son, crd);
    }
    return now + deep[crd];
}

void solve(int crd, int from)
{
    if(crd != 1) sol[crd] = sol[from] - sum[crd] + (n - sum[crd]);
    for(int son : g[crd])
    {
        if(son == from) continue;
        solve(son, crd);
    }
}

void dfs(int crd, int from)
{
    int now = 0;
    sum[crd] = 1;
    for(int son : g[crd])
    {
        if(son == from) continue;
        dfs(son, crd);
        sum[crd] += sum[son];
        now = max(now, sum[son]);
    }
    now = max(now, n - sum[crd]);
    if(now == up && crd < ans) ans = crd;
    if(now < up)
    {
        up = now;
        ans = crd;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    sol[1] = init(1, 0);
    dfs(1, 0);
    solve(1, 0);
    //for(int i = 1; i <= n; i++) printf("sol[%d] = %d\n", i, sol[i]);
    //for(int i = 1; i <= n; i++) printf("sum[%d] = %d\n", i, sum[i]);
    printf("%d %d", ans, sol[ans]);
    return 0;
}