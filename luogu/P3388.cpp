#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 100005

using namespace std;

int head[N * 2];
int sum[N], way[N], ins[N]; // cut same
int ans, tot = 1;
int n, m;

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
    bool cut[N];

    void dfs(int x, int from)
    {
        dfn[x] = up[x] = ++crd; // init x
        int ch = 0;
        for(int i = head[x]; i; i = edge[i].nxt)
        {
            int y = edge[i].ver;
            // if(y == from) continue;
            if(!dfn[y]) // y not have
            {
                dfs(y, i); ch++;
                up[x] = min(up[x], up[y]);
                if(up[y] >= dfn[x]) cut[x] = true;
            }
            else if (i != (from ^ 1))
                up[x] = min(up[x], dfn[y]);
        }
        if(from == 0 && ch <= 1) cut[x] = false;
        ans += cut[x];
    }
}

using namespace v_DCC;

int main()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }

    for(int i = 1; i <= n; i++)
        if(!dfn[i]) dfs(i, 0);

    printf("%d\n", ans);
    for(int i = 1; i <= n; i++)
        if(cut[i]) printf("%d ", i);
    
    return 0;
}