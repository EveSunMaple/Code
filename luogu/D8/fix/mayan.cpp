#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

//模拟+DFS搜索->总情况为35^5

int n;
int ans[6][3];
bool fin = false;

void update(int now[9][9])
{
    for (int i = 0; i < 5; i++)
    {
        int temp = 0;
        for (int j = 0; j < 7; j++)
        {
            if (now[i][j] == 0) temp++;
            else 
            {
                if (!temp) { continue; }
                now[i][j - temp] = now[i][j];
                now[i][j] = 0;
            }
        }
    }
}

void copy(int temp[9][9], int now[9][9])
{
    for (int i = 0; i < 5; i++) 
        for (int j = 0; j < 7; j++)
            temp[i][j] = now[i][j];
}

bool check(int now[9][9])
{
    for (int i = 0; i < 5; i++)
        if (now[i][0]) return false;
    return true;
}

void move(int x, int y, int w, int now[9][9])
{
    int temp = now[x][y];
    now[x][y] = now[x + w][y];
    now[x + w][y] = temp;
}

bool remove(int now[9][9])
{
    bool tag[5][7];
    bool flag = false;
    memset(tag, 0, sizeof(tag));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i > 0 && i < 4 && now[i][j] == now[i - 1][j] && now[i][j] == now[i + 1][j] && now[i][j])
            {
                tag[i - 1][j] = true;
                tag[i + 1][j] = true;
                tag[i][j] = true;
                flag = true;
            }
            if (j > 0 && j < 6 && now[i][j] == now[i][j + 1] && now[i][j] == now[i][j - 1] && now[i][j])
            {
                tag[i][j + 1] = true;
                tag[i][j - 1] = true;
                tag[i][j] = true;
                flag = true;
            }
        }
    }
    if (!flag) return false;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (tag[i][j]) now[i][j] = 0, tag[i][j] = 0;
        }
    }
    return true;
}

void dfs(int step, int map[9][9])
{
    if (fin) return;
    if (step == n + 1 && check(map)) { fin = true; return; }
    if (step == n + 1) { return ; }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (!map[i][j]) continue;
            if (i < 4)
            {
                ans[step][0] = i;
                ans[step][1] = j;
                ans[step][2] = 1;
                int temp[9][9];
                copy(temp, map);
                move(i, j, 1, temp); update(temp);
                while (remove(temp)) update(temp);
                dfs(step + 1, temp);
                if (fin) { return ; }
            }
            if (i > 0)
            {
                ans[step][0] = i;
                ans[step][1] = j;
                ans[step][2] =-1;
                int temp[9][9];
                copy(temp, map);
                move(i, j,-1, temp); update(temp);
                while (remove(temp)) update(temp);
                dfs(step + 1, temp);
                if (fin) { return ; }
            }
        }
    }
}

int main()
{
    //freopen("mayan.in", "r", stdin);
    //freopen("mayan.out", "w", stdout);
    int map[9][9];
    scanf("%d", &n);
    memset(map, 0, sizeof(map));
    for (int i = 0; i < 5; i++)
    {
        int temp = 1;
        for (int j = 0; temp; j++)
        {
            scanf("%d", &temp);
            map[i][j] = temp;
        }
    }
    dfs(1, map);
    if (!fin)
    {
        printf("-1");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
    }
    return 0;
}