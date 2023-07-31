#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 200005

using namespace std;

struct circle
{
    int ver;
    int nxt;
}edge[N * 2];
int head[N], tot;

int dfn[N], up[N];
int stk[N], top, crd;
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
            if (vis[v]) 
            {    
                if ((up[u] - up[v] + 1) % 3) check[u] = true; 
                up[u] = min(up[u], up[v]);
            }
    }
    if (dfn[u] == up[u]) 
    {
        vector<int> temp; 
        bool add = false;
        while (true)
        {
            int v = stk[top--]; 
            vis[v] = false;
            temp.push_back(v);
            if (check[v]) add = true;
            if (v == u) break;
        }
        if (add) ans += temp.size();
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
        edge[++tot].ver = v;
        edge[tot].nxt = head[u];
        head[u] = tot;
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) dfs(i);
    printf("%d", ans);
    return 0;
}
