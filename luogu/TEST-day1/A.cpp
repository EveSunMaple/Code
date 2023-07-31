#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 510

using namespace std;

vector<vector<int>> g(N);
bool he[N];
int deg[N];
int q[N];
int l = 0, r = 0;
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int x, m;
        scanf("%d%d", &x, &m); he[x] = true;
        for(int j = 1; j <= m; j++)
        {
            int y; scanf("%d", &y);
            g[x].push_back(y);
            deg[y]++;
        }
    }

    for(int i = 1; i <= 505; i++)
    {
        if(deg[i] == 0 && he[i] == true)
            q[++r] = i;
    }

    while(l < r)
    {
        for(int i = l; i <= r; i++)
        {
            int u = q[++l];
            for(int v : g[u])
            {
                if(!he[v]) continue;
                if(--deg[v] == 0) q[++r] = v;
            }
        }
    }

    int ans = n - l + 1;
    if(l == 0) ans = n;
    if(ans == 0) printf("YES");
    else printf("%d", ans);

    return 0;
}