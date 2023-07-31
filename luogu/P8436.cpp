#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 2000005

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

namespace e_DCC
{
    vector<vector<int>> dcc;
    int dfn[N], up[N], crd = 0;
    int stk[N], top = 0;

    void dfs(int x, int from)
    {
        dfn[x] = up[x] = ++crd; // init x
        stk[++top] = x; // enter x
        for(int i = head[x]; i; i = edge[i].nxt)
        {
            int y = edge[i].ver;
            // if(y == from) continue;
            if(!dfn[y]) // y not have
            {
                dfs(y, i); 
                up[x] = min(up[x], up[y]);
            }
            else if (i != (from ^ 1))
                up[x] = min(up[x], dfn[y]);
        }
        if(dfn[x] == up[x]) // if x == x
        {
            vector<int> c; // make a new scc
            while(true)
            {
                int y = stk[top--]; // pop stk
                c.push_back(y);
                if(y == x) break;
            }
            dcc.push_back(c);
        }
    }
}

using namespace e_DCC;

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

    printf("%d\n", dcc.size());
    for(int i = 0; i < dcc.size(); i++)
    {
        printf("%d ", dcc[i].size());
        for(int x : dcc[i])
            printf("%d ", x);
        printf("\n");
    }
    
    return 0;
}