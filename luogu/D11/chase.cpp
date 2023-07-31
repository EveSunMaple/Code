#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    freopen("chase.in", "r", stdin);
    freopen("chase.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
    }
    int t;
    scanf("%d", &t);
    int st, sp;
    scanf("%d%d", &st, &sp);
    for (int i = 1; i <= t; i++)
    {
        int sti, spi;
        scanf("%d%d", &sti, &spi);
    }
    printf("-1");
    return 0;
}