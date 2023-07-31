#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define N 100005
#define T_u 1
#define T_v 2

using namespace std;

struct truck
{
    int ver, nxt;
    int val;
}edge[N];

int tot;
int head[N];
int tag[N];

void add(int u, int v, int w)
{
    edge[++tot].val = w;
    edge[tot].ver = v;
    edge[tot].nxt = head[u];
    head[u] = tot;
    edge[++tot].val = w;
    edge[tot].ver = u;
    edge[tot].nxt = head[v];
    head[v] = tot;
}

bool check(int mid, int u, int v)
{
    memset(tag, 0, sizeof(tag));
    queue<int> u_;
    queue<int> v_;
    u_.push(u); tag[u] = T_u;
    v_.push(v); tag[v] = T_v;
    while (!u_.empty() && !v_.empty())
    {
        int temp = u_.front();
        u_.pop();
        for (int i = head[temp]; i; i = edge[i].nxt)
        {
            int oth = edge[i].ver;
            if (edge[i].val < mid) continue;
            if (tag[oth] == T_u) continue;
            if (tag[oth] == T_v) return true;
            tag[oth] = T_u;
            u_.push(oth);
        }
        temp = v_.front();
        v_.pop();
        for (int i = head[temp]; i; i = edge[i].nxt)
        {
            int oth = edge[i].ver;
            if (edge[i].val < mid) continue;
            if (tag[oth] == T_v) continue;
            if (tag[oth] == T_u) return true;
            tag[oth] = T_v;
            v_.push(oth);
        }
    }
    return false;
}

int main()
{
    fastio;
    freopen("truck.in", "r", stdin);
    freopen("truck.out", "w", stdout);
    int n, m, MIN = 1e9, MAX = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        MIN = min(MIN, w);
        MAX = max(MAX, w);
    }
    int q; scanf("%d", &q);
    while (q--)
    {
        int u, v;
        int l = MIN;
        int r = MAX;
        scanf("%d%d", &u, &v);
        if (!check(l, u, v))
        {
            printf("-1\n");
            continue;
        }
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (check(mid, u, v)) l = mid;
            else r = mid - 1;
        }
        printf("%d\n", l);
    }
    return 0;
}