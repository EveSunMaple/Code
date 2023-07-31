#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 300005
#define ll long long

using namespace std;

struct cover
{
    int l, r;
    ll temp;
} node[N];

pair<int, int> tag[N];
ll DP[N];
bool vis[N];
int fi[N];
int n, m;
int tot;

bool cmp(cover a, cover b)
{
    if (a.l < b.l)
        return true;
    if (a.l == b.l)
        return a.r < b.r;
    return false;
}

ll sol(ll base)
{
    memset(tag, 0, sizeof(tag));
    memset(DP, 0, sizeof(DP));
    memset(fi, 0, sizeof(fi));
    ll ans = 0;
    for (int i = 1; i <= tot; i++)
    {
        // DP[node[i].r] = max(DP[node[i].r], DP[node[i].l] + node[i].temp);
        if (vis[i])
            continue;
        int temp = DP[node[i].r];
        if (temp == 0)
            temp = ans;
        if (temp < DP[node[i].l] + node[i].temp)
        {
            DP[node[i].r] = DP[node[i].l] + node[i].temp;
            // printf("l : %d => %d;\n",tag[node[i].l].first, i);
            // printf("r : %d => %d;\n",tag[node[i].r].second, i);
            // vis[tag[node[i].l].first] = false;
            // vis[tag[node[i].r].second] = false;
            vis[i] = true;
            fi[i] = max(tag[node[i].l].first, tag[node[i].r].second);
            tag[node[i].l].first = i;
            tag[node[i].r].second = i;
            int l = node[i].l;
            for (int j = fi[i]; j; j = fi[j])
            {
                if (node[j].r <= l)
                {
                    vis[j] = true;
                    l = node[j].l;
                }
                else
                    vis[j] = false;
            }
            // printf("DP[%d] = max(%d,%d);\n",node[i].r, DP[node[i].r], DP[node[i].l] + node[i].temp);
        }
        ans = max(ans, DP[node[i].r]);
    }
    return ans + base;
}

int main()
{
    freopen("cover.in", "r", stdin);
    freopen("cover.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int l, r, temp;
        scanf("%d%d%d", &l, &r, &temp);
        node[++tot].l = l;
        node[tot].r = r;
        node[tot].temp = temp;
    }
    int r = 0;
    sort(node + 1, node + tot + 1, cmp);
    // printf("=====================================\n");
    // for (int i = 1; i <= tot; i++)
    //     printf("%d %d %d\n", node[i].l, node[i].r, node[i].temp);
    ll temp = 0;
    for (int i = 1; i <= m; i++)
    {
        temp = sol(temp);
        printf("%lld ", temp);
    }
    return 0;
}