#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 100005

using namespace std;

vector<vector<int>> g(N);
int col[N];
int n, m;

bool dfs(int u, int from)
{
    for(int v : g[u])
    {
        if(v == from) continue;
        if(col[v] == col[u]) return false;
        if(col[v] > 0) continue;
        col[v] = 3 - col[u];
        if(!dfs(v, u)) return false;
    }
    return true;
}

bool check(int s)
{
    bool check_over = true;
    memset(col, 0, sizeof(col));
    for(int i = s; i <= n + s - 1; i++)
    {
        int node = (i - 1) % n + 1;
        if(!col[node])
        {
            col[node] = 1;
            check_over = check_over && dfs(node, 0);
        }
    }
    for(int i = 1; i <= n; i++)
        if(!col[i]) check_over = false;
    return check_over;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(check(1))
    {
        int a = 0, b = 0;
        for(int i = 1; i <= n; i++)
        {
            if(col[i] == 1) a++;
            if(col[i] == 2) b++;
        }
        int ans = min(a, b);
        for(int s = 1; s <= n; s++)
        {
            check(s);
            a = 0, b = 0;
            for(int i = 1; i <= n; i++)
            {
                if(col[i] == 1) a++;
                if(col[i] == 2) b++;
            }
            ans = min(ans, min(a, b));
        }
        printf("%d", ans);
    }
    else printf("Impossible");
    return 0;
}