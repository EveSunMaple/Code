#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m, ans;
int map[201][201];
int leh[201][201];
bool use[201][201];

int dfs(int x,int y)
{
    if(leh[x][y])
        return leh[x][y];

    leh[x][y] = 1;

    for(int i = 0; i < 4; i++)
    {  
        int xx = dx[i] + x;
        int yy = dy[i] + y;
        if(xx > 0 && yy > 0 && xx <= n && yy <= m && map[x][y] > map[xx][yy])
        {
       	    dfs(xx, yy);
            leh[x][y] = max(leh[x][y], leh[xx][yy] + 1);
        }
    }

    return leh[x][y];
}
int main()
{	
   scanf("%d %d", &n, &m);

   for(int i = 1; i <= n ;i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &map[i][j]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            ans = max(ans, dfs(i, j));

    printf("%d", ans);

    return 0;
}