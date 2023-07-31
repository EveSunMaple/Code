#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int dp[10][10][10][10];
int map[10][10];
int N; 

void DP()
{
    /*
    1. 第一条路x++，第二条路x++
    2. 第一条路y++，第二条路x++
    3. 第一条路x++，第二条路y++
    4. 第一条路y++，第二条路y++
    */
    for(int x1 = 1; x1 <= N; x1++)
    {
        for(int y1 = 1; y1 <= N; y1++)
        {
            for(int x2 = 1; x2 <= N; x2++)
            {
                for(int y2 = 1; y2 <= N; y2++)
                {
                    int next_map = 0;
                    int next_sum = max(max(dp[x1 - 1][y1][x2 - 1][y2], dp[x1][y1 - 1][x2][y2 - 1]), max(dp[x1 - 1][y1][x2][y2 - 1], dp[x1][y1 - 1][x2 - 1][y2]));
                    if(x1 == x2 && y1 == y2) next_map = map[x1][y1];
                    else next_map = map[x1][y1] + map[x2][y2];
                    dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], next_sum + next_map);
                }
            }
        }
    }

    printf("%d", dp[N][N][N][N]);

    return;
}

int main()
{
    scanf("%d", &N);
    for(; ;)
    {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        if(x == 0 && y == 0) break;
        map[x][y] = v; 
    }

    DP();

    return 0;
}