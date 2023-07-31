#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 600005

using namespace std;

struct circle
{
    int ver;
    int nxt;
}edge[N * 2];
int head[N], tot;

int bel[N], dfn[N], up[N];
int stk[N], top, crd, tag;
bool vis[N], check[N];

int ans;

void dfs(int u)
{
    dfn[u] = up[u] = ++crd; 
    stk[++top] = u;
    vis[u] = true;
    for (int i = head[u]; i; i = edge[i].nxt)
    {
        int v = edge[i].ver;
        if (!dfn[v]) 
        {
            dfs(v);
            up[u] = min(up[u], up[v]);
        }
        else
            if (vis[v]) up[u] = min(up[u], up[v]);
    }
    if (dfn[u] == up[u]) 
    {
        tag++;
        while (true)
        {
            int v = stk[top--]; 
            vis[v] = false;
            bel[v] = tag;
            if (v == u) break;
        }
    }
}
int main()
{
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[++tot].ver = 3 * v - 1;
        edge[tot].nxt = head[3 * u];
        head[3 * u] = tot;
        edge[++tot].ver = 3 * v - 2;
        edge[tot].nxt = head[3 * u - 1];
        head[3 * u - 1] = tot;
        edge[++tot].ver = 3 * v;
        edge[tot].nxt = head[3 * u - 2];
        head[3 * u - 2] = tot;
    }
    for(int i = 1; i <= n * 3; i++)
        if(!dfn[i]) dfs(i);
    for (int i = 1; i <= n; i++)
        if (bel[3 * i] == bel[3 * i - 1]) ans++;
    printf("%d", ans);
    return 0;
}