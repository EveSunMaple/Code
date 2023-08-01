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
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        fa[getfa(u)] = getfa(v);
    }
    for (int i = 1; i <= q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (getfa(a) == getfa(b))
            printf(("YES\n"));
        else printf("NO\n");
    }
    return 0;
}