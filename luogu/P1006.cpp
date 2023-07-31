#include <iostream>
#include <cstdio>
#include <cmath>
#define N 55

using namespace std;

int map[N][N];
int DP[N][N][N][N];
int m, n;

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);
        
}