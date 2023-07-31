#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#define N 500005

using namespace std;

queue<int> node;
vector<vector<int>> g(N); // node_vector
int sum[N], way[N], ins[N]; // cut same
int edge[N], dp[N], a[N];
int n, m, s, t;
bool check[N];
int ans = 0;

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
                a[scc.size()] += edge[y];
                vis[y] = false; // cut y
                bel[y] = scc.size();
                c.push_back(y);
                if(y == x) break;
            }
            scc.push_back(c);
        }
    }
}

void bfs(int i)
{
    node.push(i);
    while(!node.empty())
    {
        int u = node.front();
        //printf("From:%d    ins[u]:%d\n", u, ins[u]);
        ins[u] = ++t;
        node.pop();
        for(int x : SCC::scc[u])
        {
            for(int y : g[x])
            {
                int nxt = SCC::bel[y];
                if(ins[nxt] == t || dp[u] + a[nxt] <= dp[nxt]) continue;
                ins[nxt] = t;
                dp[nxt] = dp[u] + a[nxt];
                if(check[nxt]) ans = max(ans, dp[nxt]);
                //printf("   Goto:%d\n", nxt);
                node.push(nxt);
                //dfs(nxt, i);
            }
        }
    }
}

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
        scanf("%d", &edge[i]);
    for(int i = 1; i <= n; i++)
        if(!SCC::dfn[i]) SCC::dfs(i);

    scanf("%d%d", &s, &m);
    while (m--)
    {
        int x;
        scanf("%d", &x);
        check[SCC::bel[x]] = true;
    }

    dp[SCC::bel[s]] = a[SCC::bel[s]];
    bfs(SCC::bel[s]);

    //for(int i = 0; i < SCC::scc.size(); i++)
    //{   
    //    sum[i] = 0; way[i] = 1;
    //    t++; ins[i] = t;
    //    for(int x : scc[i])
    //    {
    //        for(int y : g[x])
    //        {
    //            if(ins[bel[y]] == t) continue;
    //            ins[bel[y]] = t;
    //            if(sum[i] < sum[bel[y]]) { sum[i] = sum[bel[y]]; way[i] = 0; }
    //            if(sum[i] == sum[bel[y]]) { way[i] = (way[i] + way[bel[y]]) % k; }
    //        }
    //    }
    //    sum[i] += scc[i].size();
    //    if(sum[i] > ans) { ans = sum[i]; sol = way[i]; }
    //    else if(sum[i] == ans) { sol = (sol + way[i]) % k; }
    //}

    printf("%d", ans);
    
    return 0;
}