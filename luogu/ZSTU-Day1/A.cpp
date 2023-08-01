#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct point
{
    int x, sum, line;
}num[10005];

bool cmp(point a, point b)
{
    if (a.sum > b.sum) return true;
    if (a.sum < b.sum) return false;
    if (a.x > b.x) return true;
    if (a.x < b.x) return false;
    return a.line < b.line;
}

void swap(point &a, point &b)
{
    point temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int temp = x + y + z;
        num[i].x = x;
        num[i].sum = temp;
        num[i].line = i;
        //num[i] = point(x, y, z, temp, i);
    }
    sort(num + 1, num + 1 + n, cmp);
    for (int i = 1; i <= min(5, n); i++)
        printf("%d %d\n", num[i].line, num[i].sum);
    return 0;
}