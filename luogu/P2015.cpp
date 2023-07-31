#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#define MAX 500

using namespace std;

int N, M;
vector<vector<int>> to(MAX);
bool up[MAX];
int f[MAX][MAX];
int w[MAX][MAX];
int ans;

void solve(int crd)
{
    up[crd] = true;
    for(int son : to[crd])
    {
        if(up[son] == true) continue;
        up[son] = true; 
        solve(son);
        for(int r = M; r >= 1; r--)
        {
            for(int l = r - 1; l >= 0; l--)
            {
                f[crd][r] = max(f[crd][r], f[crd][r - l - 1] + f[son][l] + w[crd][son]);
                ans = max(f[crd][r], ans);
            }
        }
    }
}

int main()
{
    memset(w, -1, sizeof(w));
    scanf("%d %d", &N, &M);
    for(int i = 1; i < N; i++)
    {
        int u, v, s;
        scanf("%d %d %d",&u, &v ,&s);
        to[u].push_back(v);
        to[v].push_back(u);
        w[u][v] = s; w[v][u] = s;
    }
    solve(1);
    cout << f[1][M];

    return 0;
}