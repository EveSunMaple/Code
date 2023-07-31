#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 20005

using namespace std;

//struct node
//{
//    int ver;
//    int edge;
//    bool open = false;
//    node(int a, int b)
//    {
//        ver = a;
//        edge = b;
//    }
//};
vector<vector<pair<int, int>>> g(N);
int l = 0, r = 1e9, mid;
int col[N];
int n, m;

bool dfs(int u, int from)
{
    for(pair<int, int> v : g[u])
    {
        if(v.first == from) continue;
        if(v.second <= mid) continue;
        if(col[v.first] == col[u]) return false;
        if(col[v.first] > 0) continue;
        col[v.first] = 3 - col[u];
        if(!dfs(v.first, u)) return false;
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
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    
    while (l < r)
    {
        mid = (l + r) / 2;
        if(check()) r = mid;
        else l = mid + 1;
    }

    printf("%d", l);

    return 0;
}