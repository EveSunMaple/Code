#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 1000000

using namespace std;

vector<vector<pair<int, int>>> g(N);
int node[N][2], last[N];
int x[N];
int n, ans, tot;

void init(int u, int from)
{
    for(auto t : g[u])
    {
        int v = t.first;
        int w = t.second;
        if(v == from) continue;
        x[v] = x[u] ^ w;
        init(v, u);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    init(1, 0);
    for(int i = 1; i <= n; i++)
    {
        int u = 0;
        for(int j = 31; j >= 0; j--)
        {
            bool c = (x[i] >> j) & 1;
            if(!node[u][c]) node[u][c] = ++tot;
            u = node[u][c];
        }
        last[u] = x[i];
    }
    for(int i = 1; i <= n; i++)
    {
        int u = 0;
        for(int j = 31; j >= 0; j--)
        {
            bool v2 = (x[i] >> j) & 1;
            bool v1 = !v2;
            if(node[u][v1]) u = node[u][v1];
            else u = node[u][v2];
        }
        ans = max(ans, last[u] ^ x[i]);
    }
    printf("%d", ans);
    return 0;
}