#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

bool map[105][105];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, k, x, y;
        scanf("%d%d%d", &n, &m, &k);
        scanf("%d%d", &x, &y);
        bool check = true;
        //memset(map, false, sizeof(map));
        for (int i = 1; i <= k; i++)
        {
            int xi, yi;
            scanf("%d%d", &xi, &yi);
            int temp = abs(xi - x) + abs(yi - y) - 1;
            if (temp & 1) check = false;
            //if (xi > 1) map[xi - 1][yi] = true;
            //if (xi < n) map[xi + 1][yi] = true;
            //if (yi > 1) map[xi][yi - 1] = true;
            //if (yi < m) map[xi][yi + 1] = true;
        }
        //if (x > 1 && map[x - 1][y] == false) check = true;
        //if (x < n && map[x + 1][y] == false) check = true;
        //if (y > 1 && map[x][y - 1] == false) check = true;
        //if (y < m && map[x][y + 1] == false) check = true;
        if (check) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}