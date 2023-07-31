#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 100005

using namespace std;

int node[32 * N][2];
int last[32 * N];
int has[32 * N];
int list[1005];
int n, tot;

void add(int num)
{
    int u = 0;
    for(int j = 31; j >= 0; j--)
    {
        bool c = (num >> j) & 1;
        if (!node[u][c]) { node[u][c] = ++tot, node[tot][0] = node[tot][1] = last[tot] = has[tot] = 0; }
        u = node[u][c];
        has[u]++;
    }
    last[u] = num;
}

void update(int target, int way)
{
    int u = 0;
    for(int i = 31; i >= 0; i--)
    {
        bool v = (target >> i) & 1;
        if(!node[u][v]) break;
        u = node[u][v];
        has[u] += way;
    }
}

void solve()
{
    int ans = 0;
    tot = 0, node[0][0] = node[0][1] = last[0] = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &list[i]);
        add(list[i]);
    }
    for(int x = 1; x <= n; x++)
    {
        for(int y = x + 1; y <= n; y++)
        {
            int u = 0, num = list[x] + list[y];
            update(list[x], -1);
            update(list[y], -1);
            for(int j = 31; j >= 0; j--)
            {
                bool v2 = (num >> j) & 1;
                bool v1 = !v2;
                if(node[u][v1] && has[node[u][v1]]) u = node[u][v1];
                else u = node[u][v2];
            }
            update(list[x], 1);
            update(list[y], 1);
            ans = max(ans, num ^ last[u]);
        }    
    }
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}