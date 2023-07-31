#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#define MAX 500

using namespace std;

int N, M;
vector<vector<int>> to(MAX);
int f[MAX][MAX];
int w[MAX];
int ans;

void solve(int crd)
{
    f[crd][0] = 0;
    f[crd][1] = w[crd];
    for(int son : to[crd])
    {
        solve(son);
        for(int r = M; r > 0; r--)
        {
            for(int l = 1; l < r; l++)
            {
                f[crd][r] = max(f[crd][r], f[crd][r - l] + f[son][l]);
                ans = max(f[crd][r], ans);
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        int s, k;
        scanf("%d %d", &k ,&s);
        to[k].push_back(i);
        w[i] = s;
    }
    M++;
    solve(0);
    cout << ans;

    return 0;
}