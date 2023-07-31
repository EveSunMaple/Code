#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 200005

using namespace std;

vector<vector<int>> g(N);
int col[N];
int n, m;

void check()
{
    
    memset(col, 0, sizeof(col));
    for(int i = 1; i <= n; i++)
    {
        if(!col[i])
        {
            col[i] = 1;

        }
    }
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
}