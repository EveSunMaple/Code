#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 100005

using namespace std;

int fa[N];

int getfa(int a)
{
    return fa[a] == a ? a : fa[a] = getfa(fa[a]); 
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &c, &a, &b);
        if (c == 1)
            fa[getfa(a)] = getfa(b);
        else
        {
            if (getfa(a) == getfa(b))
                printf(("Y\n"));
            else printf("N\n");
        }
    }
    return 0;
}