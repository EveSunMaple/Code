#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define MAX 105

using namespace std;

vector<int> g[MAX];
int edge[MAX];
int deep[MAX];
int sol[MAX];
int sum[MAX];
int peo[MAX];
int ans = 1e9;
int tot;
int n;

int init(int crd, int from)
{
    int now = 0;
    peo[crd] = edge[crd];
    for(int son : g[crd])
    {
        if(son == from) continue;
        deep[son] = deep[crd] + 1;
        now += init(son, crd);
        sum[crd] += sum[son] + peo[son];
        peo[crd] += peo[son];
    }
    return now + deep[crd];
}

void solve(int crd, int from)
{
    if(crd != 1)
    {
        int far = tot - peo[crd];
        sol[crd] = sol[from] - peo[crd] + far;
        peo[crd] = tot;
    }
    for(int son : g[crd])
    {
        if(son == from) continue;
        solve(son, crd);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int w, u, v;
        scanf("%d%d%d", &w, &u, &v);
        edge[i] = w;
        if(v > 0) {g[i].push_back(v); g[v].push_back(i);}
        if(u > 0) {g[i].push_back(u); g[u].push_back(i);}
    }
    init(1, 0);
    sol[1] = sum[1];
    tot = peo[1];
    //for(int i = 1; i <= n; i++) printf("deep[%d] = %d\n", i, deep[i]);
    //for(int i = 1; i <= n; i++) printf("sum[%d] = %d\n", i, sum[i]);
    //for(int i = 1; i <= n; i++) printf("peo[%d] = %d\n", i, peo[i]);
    solve(1, 0);
    //for(int i = 1; i <= n; i++) printf("sol[%d] = %d\n", i, sol[i]);
    for(int i = 1; i <= n; i++) ans = min(ans, sol[i]);
    printf("%d", ans);
    return 0;
}