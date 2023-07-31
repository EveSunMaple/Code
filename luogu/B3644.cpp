#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 105

using namespace std;

vector<vector<int>> g(N);
int deg[N];
int q[N];
int l = 0, r = 0;
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j; cin >> j;)
        {
            if(j == 0) break;
            g[i].push_back(j);
            deg[j]++;
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

    for(int i = 1; i <= n; i++)
        printf("%d ", q[i]);

    return 0;
}