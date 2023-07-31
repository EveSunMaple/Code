#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#define N 100005

using namespace std;

vector<vector<int>> g(N); // node_vector
int sum[N], way[N], ins[N]; // cut same
int n, m;

namespace SCC
{
    vector<vector<int>> scc;
    // dfs_list / all_up / scc_style / now_crd
    int dfn[N], up[N], bel[N], crd = 0;
    // node_list / list_crd
    int stk[N], top = 0;
    bool vis[N];

    void dfs(int x)
    {
        dfn[x] = up[x] = ++crd; // init x
        stk[++top] = x; // enter x
        vis[x] = true;
        for(int y : g[x])
        {
            if(!dfn[y]) // y not have
            {
                dfs(y);
                up[x] = min(up[x], up[y]);
            }
            else
                if(vis[y]) up[x] = min(up[x], up[y]);
        }
        if(dfn[x] == up[x]) // if x == x
        {
            vector<int> c; // make a new scc
            while(true)
            {
                int y = stk[top--]; // pop stk
                vis[y] = false; // cut y
                bel[y] = scc.size();
                c.push_back(y);
                if(y == x) break;
            }
            sort(c.begin(), c.end());
            scc.push_back(c);
        }
    }
}

using namespace SCC;

int main()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }

    for(int i = 1; i <= n; i++)
        if(!SCC::dfn[i]) SCC::dfs(i);

    printf("%d\n", scc.size());
    for(int i = 1; i <= n; i++)
    {
        if(!scc[bel[i]].size()) continue;
        for(int x : scc[bel[i]])
        {
            printf("%d ", x);
            scc[bel[x]].pop_back();
        }
        printf("\n");
    }

    return 0;
}