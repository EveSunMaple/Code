#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int peo[50005][2];
bool tag[50005];
int ins[50005];
int sta[100005];
int ans = 0;
int n;

void check(int u, int from, int order)
{
    if (tag[u]) return;
    else tag[u] = true;
    if (order > n) order = 1;
    sta[u - order + 50000]++;
    ans = max(ans, sta[u - order + 50000]);
    sta[u - order + 50000]++;
    ans = max(ans, sta[u - order + 50000]);
    if (peo[u][0] == from) check(peo[u][1], u, order + 1);
    else check(peo[u][0], u, order + 1);
}

int main()
{
    bool ok = false;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &peo[i][0], &peo[i][1]);
        ins[peo[i][0]]++; ins[peo[i][1]]++;
        if (peo[i][0] == i || peo[i][1] == i) ok = true;
        if (peo[i][0] > n || peo[i][1] > n) ok = true;
    }
    for (int i = 1; i <= n; i++)
        if (ins[i] != 2 || ok)
        {
            printf("-1");
            return 0;
        }
    check(1, peo[1][0], 1);
    memset(tag, 0, sizeof(tag));
    memset(sta, 0, sizeof(sta));
    check(1, peo[1][1], 1);
    printf("%d", n - ans);
    return 0;
}