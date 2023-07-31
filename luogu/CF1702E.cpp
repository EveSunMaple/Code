#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 200005

using namespace std;

struct point
{
    int node;
    int first;
    int second;
    point(int a, int b, int c)
    {
        node = a;
        first = b;
        second = c;
    }
};

vector<vector<int>> g(N);
vector<vector<int>> p(N);
bool no = false;
int col[N];
int t, n;

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

void runTime()
{
    for(int i = 1; i <= n; i++)
    {
        g[i].clear(); 
        p[i].clear();
    }
    no = false;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if(u == v || p[u].size() > 2 || p[v].size() > 2) 
            no = true;
        if(!no)
        {
            for(int t : p[u])
            {
                g[i].push_back(t);
                g[t].push_back(i);
            }
            for(int t : p[v])
            {
                g[i].push_back(t);
                g[t].push_back(i);
            }
            p[u].push_back(i);
            p[v].push_back(i);
        }
    }
    if(check() && !no) printf("YES\n");
    else printf("NO\n");
}

int main()
{
    scanf("%d", &t);
    for(; t > 0; t--)
    {
        runTime();
    }
    return 0;
}