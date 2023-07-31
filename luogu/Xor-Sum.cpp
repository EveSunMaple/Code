#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 100005

using namespace std;

int node[32 * N][2];
int last[32 * N];
int n, m, tot;

void solve()
{
    // memset(node, 0, sizeof(node));
    // memset(last, 0, sizeof(last));
    tot = 0, node[0][0] = node[0][1] = last[0] = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        int num, u = 0;
        scanf("%d", &num);
        for(int j = 31; j >= 0; j--)
        {
            bool c = (num >> j) & 1;
            // if(!node[u][c]) node[u][c] = ++tot;
            if (!node[u][c]) { node[u][c] = ++tot, node[tot][0] = node[tot][1] = last[tot] = 0; }
            u = node[u][c];
        }
        last[u] = num;
    }
    for(int i = 1; i <= m; i++)
    {
        int s, u = 0;
        scanf("%d", &s);
        for(int j = 31; j >= 0; j--)
        {
            bool v2 = (s >> j) & 1;
            bool v1 = !v2;
            if(node[u][v1]) u = node[u][v1];
            else u = node[u][v2];
        }
        printf("%d\n", last[u]);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}