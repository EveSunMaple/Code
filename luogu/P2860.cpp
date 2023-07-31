#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#define N 500005

using namespace std;

queue<int> node;
int head[N * 2], deg[N];
int sum[N], way[N], ins[N]; // cut same
int ans, tot = 1;
bool vis[N];
int n, m, t;

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
    int dfn[N], up[N], bel[N], crd = 0;
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
                bel[y] = dcc.size();
                c.push_back(y);
                if(y == x) break;
            }
            dcc.push_back(c);
        }
    }
}

using namespace e_DCC;

//void solve(int i) // 入口
//{
//    vis[i] = true;
//    for(int x : dcc[i]) // 在这个SCC中取点
//    {
//        for(int j = head[x]; j; j = edge[j].nxt) // 向外扩展
//        {
//            int y = edge[j].ver;
//            int nxt = bel[y]; // 获得这个结点的SCC结点
//            if(vis[nxt]) continue; // 如果标记相同跳过
//            deg[i]++; deg[nxt]++;
//            vis[nxt] = true; // 打上标记防止重复遍历
//            solve(nxt);
//        }
//    }
//}

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
        for(int j = head[i]; j; j = edge[j].nxt)
        {
            int y = edge[j].ver;
            if(bel[i] == bel[y]) continue;
            deg[bel[i]]++;
        }
    for(int i = 0; i < dcc.size(); i++)
    {
        if(deg[i] == 1) ans++;
    }
    
    printf("%d", (ans + 1) / 2);

    return 0;
}