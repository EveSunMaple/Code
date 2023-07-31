#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 500005
#define LL long long

using namespace std;

int head[N * 2];
LL sum[N], ans[N];
int tot = 0;
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
        int ch = 0, cnt = 0; sum[x] = 1;
        for(int i = head[x]; i; i = edge[i].nxt)
        {
            int y = edge[i].ver;
            // if(y == from) continue;
            if(!dfn[y]) // y not have
            {
                dfs(y, i);
                sum[x] += sum[y];
                up[x] = min(up[x], up[y]);
                if(up[y] >= dfn[x]) 
                {
                    ans[x] += (long long)sum[y] * (n - sum[y]);
                    cnt += sum[y];
                    ch++;
                    if(from != 0 || ch > 1) cut[x]=true;
                }
            }
            else up[x] = min(up[x], dfn[y]);
        }
        if(!cut[x]) ans[x] = 2 * (n - 1);
	    else ans[x] += (long long)(n - cnt - 1) * (cnt + 1) + (n - 1);
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
    for(int i = 1; i <= n; i++)
        printf("%lld\n", ans[i]);
    
    return 0;
}