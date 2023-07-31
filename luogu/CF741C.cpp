#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 200005

using namespace std;

vector<vector<int>> g(N);
vector<pair<int, int>> p;
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

bool check()
{
    bool check_over = true;
    memset(col, 0, sizeof(col));
    for(int i = 1; i <= n * 2; i++)
    {
        if(!col[i])
        {
            col[i] = 1;
            check_over = check_over && dfs(i, 0);
        }
    }
    for(int i = 1; i <= n * 2; i++)
        if(!col[i]) check_over = false;
    return check_over;
}

inline void out()
{
    for(pair<int, int> t : p)
        printf("%d %d\n", col[t.first], col[t.second]);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        p.push_back(make_pair(u, v));
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for(int i = 1; i <= n * 2; i += 2)
    {
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
    }
    if(check())
    {
        out();
        return 0;
    }
    //else
    //{
    //    for(int i = 1; i <= n * 2; i += 2)
    //    {
    //        g[i].pop_back();
    //        if(i + 1 < n * 2)
    //            g[i + 1].push_back(i + 2);
    //        else
    //            g[i + 1].push_back(1);
    //    }
    //    if(check())
    //    {
    //        out();
    //        return 0;
    //    }
    //}

    printf("-1");
    return 0;
}