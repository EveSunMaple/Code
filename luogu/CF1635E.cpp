#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 200005

using namespace std;

struct style
{
    int o;
    int u;
    int v;
    style(int a, int b, int c)
    {
        o = a;
        u = b;
        v = c;
    }
};

vector<style> all;
vector<vector<int>> g(N);
vector<vector<int>> p(N);
int col[N];
int deg[N];
int q[N];
int t[N];
int l, r;
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
    for(int i = 1; i <= n; i++)
    {
        if(!col[i])
        {
            col[i] = 1;
            check_over = check_over && dfs(i, 0);
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
        int o, u, v;
        scanf("%d%d%d", &o, &u, &v);
        all.push_back(style(o, u, v));
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(check())
    {
        for(style car : all)
        {
            if((car.o == 1 && col[car.u] == 2) || (car.o == 2 && col[car.u] == 1))
            {
                p[car.u].push_back(car.v);
                deg[car.v]++;
            }
            if((car.o == 2 && col[car.u] == 2) || (car.o == 1 && col[car.u] == 1))
            {
                p[car.v].push_back(car.u);
                deg[car.u]++;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(deg[i] == 0)
                q[++r] = i;
        }
        while(l < r)
        {
            for(int i = l; i <= r; i++)
            {
                int u = q[++l];
                for(int v : g[u])
                {
                    if(--deg[v] == 0) q[++r] = v;
                }
            }
        }
        if(l - 1 < n)
        {
            printf("NO");
            return 0;
        }
        for(int i = 1; i <= n; i++)
            t[q[i]] = i;
        printf("YES\n");
        for(int i = 1; i <= n; i++)
        {
            if(col[i] == 1) printf("R %d\n", t[i]);
            if(col[i] == 2) printf("L %d\n", t[i]);
        }
    }
    else printf("NO");

    return 0;
}