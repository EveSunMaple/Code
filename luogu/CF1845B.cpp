#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

struct node
{
    int x, y;
};


int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int ans = 1;
        node a, b, c;
        scanf("%d%d", &a.x, &a.y);
        scanf("%d%d", &b.x, &b.y);
        scanf("%d%d", &c.x, &c.y);
        if (b.y >= a.y && c.y >= a.y) // 都在上方
        {
            //printf("%d\n", min(c.y, b.y) - a.y + 1);
            ans += min(c.y, b.y) - a.y;
        }
        if (b.y <= a.y && c.y <= a.y) // 都在下方
        {
            //printf("%d\n", max(c.y, b.y) - a.y + 1);
            ans += a.y - max(c.y, b.y);
        }
        if (b.x >= a.x && c.x >= a.x) // 都在右方
        {
            //printf("%d\n", min(c.x, b.x) - a.x + 1);
            ans += min(c.x, b.x) - a.x; 
        }
        if (b.x <= a.x && c.x <= a.x) // 都在左方
        {
            //printf("%d\n", max(c.x, b.x) - a.x + 1);
            ans += a.x - max(c.x, b.x);
        }
        printf("%d\n", ans);
    }
    return 0;
}