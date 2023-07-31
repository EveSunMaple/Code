#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#define N 500005

using namespace std;

vector<vector<int>> g(N);
int head[N * 2];
int sum[N], way[N], ins[N]; // cut same
int n, m, a, b;
int tot = 0;
int cnt = 0;

struct node
{
    int ver;
    int nxt;
}edge[N * 2];

void add(int u, int v)
{
    edge[++tot].ver = v;
    edge[tot].nxt = head[u];
    head[u] = tot;
}

namespace v_DCC
{
    // dfs_list / all_up / now_crd
    int dfn[N], up[N], crd = 0;
    int stk[N], top;
    bool cut[N], has = false;

    void dfs(int x, int from)
    {
        dfn[x] = up[x] = ++crd; // init x
        stk[++top] = x; // enter x
        for(int i = head[x]; i; i = edge[i].nxt)
        {
            int y = edge[i].ver;
            if(!dfn[y])
            {
                dfs(y, i);
                up[x] = min(up[x], up[y]);
                if(up[y] >= dfn[x])
                {
                    cnt++;
                    while (true)
                    {
                        int t = stk[top--];
                        g[cnt].push_back(t);
                        g[t].push_back(cnt);
                        if(t == y) break;
                    }
                    g[x].push_back(cnt);
                    g[cnt].push_back(x);
                }
            }
            else if (i != (from ^ 1))
                up[x] = min(up[x], dfn[y]);
        }
    }
}

using namespace v_DCC;

void solve(int u, int ans, int from) 
{
    if (u == b) 
    {
        if (ans == 1e9) printf("No solution");
        else printf("%d", ans);
        exit(0);
    }
    if (u != a && g[u].size() > 1 && u <= n) 
        ans = min(ans, u);
    for (int v : g[u]) 
    {
        if (v == from) continue;
        solve(v, ans, u);
    }
}

int main()
{
    scanf("%d", &n);
    while (true)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if(!u && !v) break;
        add(u, v);
        add(v, u);
    }
    scanf("%d%d", &a, &b);
    cnt = n;
    dfs(a, 0);
    if (dfn[b] == 0) 
    {
        printf("No solution\n");
        return 0;
    }

    solve(a, 1e9, 0);
    
    return 0;
}