#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 300005

using namespace std;

vector<vector<int>> g(N);
string ch;

int node[N][26];
int outdeg[N];
int indeg[N];
int q[N];
int ans;
int l, r;
int n, m;

//void dfs(int u)
//{
//    node[u][ch[u - 1] - 97]++;
//    for(int v : g[u])
//    {
//        for(int i = 0; i <= 25; i++)
//            node[v][i] = node[u][i];
//        dfs(v);
//    }
//    if(outdeg[u] == 0)
//    {
//        for(int i = 0; i <= 25; i++)
//            ans = max(ans, node[u][i]);
//        return;
//    }
//}

int main()
{
    scanf("%d%d", &n, &m);
    cin >> ch;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        outdeg[u]++;
        indeg[v]++;
    }

    for(int i = 1; i <= n; i++)
    {
        if(indeg[i] == 0)
            q[++r] = i;
    }

    while(l < r)
    {
        for(int i = l; i <= r; i++)
        {
            int u = q[++l];
            if(u <= 0) continue;
            node[u][ch[u - 1] - 97]++;
            if(outdeg[u] == 0)
            {
                for(int i = 0; i <= 25; i++)
                    ans = max(ans, node[u][i]);
            }
            for(int v : g[u])
            {
                for(int i = 0; i <= 25; i++)
                    node[v][i] = max(node[v][i], node[u][i]);
                if(--indeg[v] == 0) q[++r] = v;
            }
        }
    }

    if(l - 1 < n)
    {
        cout << -1;
        return 0;
    }

    //for(int i = 1; i <= n; i++)
    //{
    //    if(clone[i] == 0)
    //        dfs(i);
    //}

    printf("%d", ans);

    return 0;
}