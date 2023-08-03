#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 200005

using namespace std;

struct B
{
    int l, r;
}edge[N];

bool cmp(B a, B b)
{
    return a.r < b.r;
}

int main()
{
    // ex
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &edge[i].l, &edge[i].r);
        if (edge[i].l > edge[i].r) swap(edge[i].l, edge[i].r);
    }
    sort(edge + 1, edge + 1 + n, cmp);
    int ans = 0;
    int last = 0;
    for (int i = 1; i <= m; i++)
    {
        if (edge[i].l > last)
        {
            last = edge[i].r;
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}