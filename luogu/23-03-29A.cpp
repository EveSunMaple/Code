#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 1e9 

using namespace std;

int T = 0, N = 0;
int map[1002][1002];
int leth[1002];
bool tip[1002];

int main()
{
    memset(leth, 0x7f, sizeof(leth));
    scanf("%d %d", &T, &N);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            map[i][j] = INF;
    for(int i = 1; i <= T; i++)
    {
        int x = 0, y = 0;
        scanf("%d %d", &x , &y);
        scanf("%d", &map[x][y]);
        map[y][x] = map[x][y];
    }
    
    leth[1] = 0;
    tip[1] = true;
    int x = 1, y = 1;
    for(int i = 1; i <= N; i++)
    {
        int min = INF;
        for(int j = 1; j <= N; j++)
        {
            if(map[y][j] + leth[y] < leth[j])
            {
                leth[j] = map[y][j] + leth[y];    
            }
        }
        for(int j = 1; j <= N; j++)
            if(map[x][j] < min && tip[j] == false) {min = map[x][j]; y = j;}    
        tip[y] = true;
        cout << "S:  " << map[x][y] + leth[x] << "   T:  " << leth[y] << endl;
        cout << "X:  " << x << "   Y:  " << y << endl;
        x = y;
    }
    for(int i = 1; i <= N; i++)

    cout << leth[i] << endl;
    
    return 0;
}