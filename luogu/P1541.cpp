#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAX 41

using namespace std;

int f[MAX][MAX][MAX][MAX]; //记录卡片状态最优
int m[355]; //地图
int g[4]; //一共几张

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++) scanf("%d", &m[i]);
    for(int i = 1; i <= M; i++)
    {
        int t; scanf("%d", &t);
        g[--t]++;
    }

    f[0][0][0][0] = m[1];

    for(int a = 0; a <= g[0]; a++)
    {
        for(int b = 0; b <= g[1]; b++)
        {
            for(int c = 0; c <= g[2]; c++)
            {
                for(int d = 0; d <= g[3]; d++)
                {
                    int now = 1 + a + b * 2 + c * 3 + d * 4;
                    if(a > 0) f[a][b][c][d] = max(f[a][b][c][d], f[a - 1][b][c][d] + m[now]);
                    if(b > 0) f[a][b][c][d] = max(f[a][b][c][d], f[a][b - 1][c][d] + m[now]);
                    if(c > 0) f[a][b][c][d] = max(f[a][b][c][d], f[a][b][c - 1][d] + m[now]);
                    if(d > 0) f[a][b][c][d] = max(f[a][b][c][d], f[a][b][c][d - 1] + m[now]);
                }
            }
        }
    }

    printf("%d", f[g[0]][g[1]][g[2]][g[3]]);

    return 0;
}