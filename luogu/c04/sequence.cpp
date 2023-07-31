#include <iostream>
#include <cstring>
#include <cstdio>
#define N 100005

using namespace std;

struct sequence
{
    int l, r;
}node[N];

int main()
{
    int n, m;
    bool order = true;
    scanf("%d%d", &n ,&m);
    for (int i = 1; i <= n; i++)
    {
        node[i].l = i - 1;
        node[i].r = i + 1;
    }
    node[1].l = n;
    node[n].r = 1;
    while (m--)
    {
        int temp;
        scanf("%d", &temp);
        if (temp == 1)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            node[node[u].l].r = node[u].r;
            node[node[u].r].l = node[u].l;
            node[u].l = v;
            node[u].r = node[v].r;
            node[node[v].r].l = u;
            node[v].r = u;
        }
        else if (temp == 2)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            node[node[u].l].r = node[u].r;
            node[node[u].r].l = node[u].l;
            node[u].r = v;
            node[u].l = node[v].l;
            node[node[v].l].r = u;
            node[v].l = u;
        }
        else if (temp == 3) order = !order;
        else
        {
            int crd = 1;
            while (true)
            {
                printf("%d ", crd);
                if (order) crd = node[crd].r;
                else crd = node[crd].l;
                if (crd == 1) break;
            }
            printf("\n");
        }
    }
    return 0;
}