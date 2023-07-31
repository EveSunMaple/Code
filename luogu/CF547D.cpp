#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 200005

using namespace std;

//struct point
//{
//    int node;
//    int first;
//    int second;
//    point(int a, int b, int c)
//    {
//        node = a;
//        first = b;
//        second = c;
//    }
//};

vector<vector<int>> g(N);
//vector<vector<point>> x(N);
//vector<vector<point>> y(N);
int lstu[N], lstv[N];
bool no = false;
int col[N];
int n;

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
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        //if(u == v || p[u].size() > 2 || p[v].size() > 2) 
        //    no = true;
        if(lstu[u])
        {
            g[i].push_back(lstu[u]);
            g[lstu[u]].push_back(i);
            lstu[u] = 0;
        }
        else lstu[u] = i;
        if(lstv[v])
        {
            g[i].push_back(lstv[v]);
            g[lstv[v]].push_back(i);
            lstv[v] = 0;
        }
        else lstv[v] = i;
        //for(point t : x[u])
        //{
        //    if(t.second == v) continue;
        //    g[i].push_back(t.node);
        //    g[t.node].push_back(i);
        //}
        //for(point t : y[v])
        //{
        //    if(t.first == u) continue;
        //    g[i].push_back(t.node);
        //    g[t.node].push_back(i);
        //}
        //x[u].push_back(point(i, u, v));
        //y[v].push_back(point(i, u, v));
    }
    check();
    for(int i = 1; i <= n; i++)
    {
        if(col[i] == 1) printf("b");
        if(col[i] == 2) printf("r");
    }

    return 0;
}