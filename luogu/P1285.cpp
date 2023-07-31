#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#define N 105

using namespace std;

vector<vector<int>> g(N);
vector<vector<int>> x(N);
priority_queue<int> first;
priority_queue<int> second;
queue<int> fix;
//vector<vector<node>> y(N);
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
        for(; ;)
        {
            int v;
            scanf("%d", &v);
            if(v == 0) break;
            x[i].push_back(v);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int u = 1; u <= n; u++)
        {
            bool add = true;
            if(u == i) continue;
            for(int v : x[u])
            {
                if(i == v) add = false;
            }
            if(add)
            {
                g[i].push_back(u);
                g[u].push_back(i);
            }
        }
    }
    if(check())
    {
        for(int i = 1; i <= n; i++)
        {
            if(g[i].empty()) fix.push(i);
            else if(col[i] == 1) first.push(-i);
            else if(col[i] == 2) second.push(-i);
        }
        while (!fix.empty())
        {
            if(first.size() < second.size())
                { first.push(-fix.front()); fix.pop(); }
            else 
                { second.push(-fix.front()); fix.pop(); }
        }
        printf("%d ", first.size());
        while (!first.empty())
            { printf("%d ", -first.top()); first.pop(); }

        printf("\n%d ", second.size());
        while (!second.empty())
            { printf("%d ", -second.top()); second.pop(); }
    }
    else
        printf("No solution");
    return 0;
}