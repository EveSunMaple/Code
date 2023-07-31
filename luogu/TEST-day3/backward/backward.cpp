#include <iostream>
#include <cstring>
#include <time.h>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 400005

using namespace std;

vector<vector<int>> g(N);
int c[N], check[N];
int type, n, m;
int ans;

void dfs(int crd, int d)
{
    if(d < 0) return;
    if(!check[c[crd]])
    {
        check[c[crd]] = true;
        ans++;
    }
    for(int v : g[crd])
         dfs(v, d - 1);
}

void solve(int u, int k)
{
    ans = 0;
    memset(check, 0, sizeof(check));
    dfs(u, k); printf("%d\n", ans);
}

int main()
{
    freopen("backward.in", "r", stdin);
    freopen("backward.out", "w", stdout);
    scanf("%d%d", &type, &n);
    for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for(int i = 2; i <= n; i++)
    {
        int f;
        scanf("%d", &f);
        g[f].push_back(i);
    }
    scanf("%d", &m);
    while(m--) 
    {
        int u, k;
        scanf("%d%d", &u, &k);
        solve(u, k);
    }
    return 0;
}