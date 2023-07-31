#include <algorithm>
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
    int u, v;
    int val;
    truck(int a, int b, int c)
    {
        u = a;
        v = b;
        val = c;
    }
    truck()
    {
        u = 0;
        v = 0;
        val = 0;
    }
};

vector<truck> edge;            // 直接存储无向边
vector<pair<int, int>> que[N]; // 保存从N到<first>的第<second>次询问
int fa[N];                     // 并查集的父亲代表元素
int ans[300005];

bool cmp(truck a, truck b)
{
    return a.val > b.val;
}

int get_fa(int a)
{
    return a == fa[a] ? a : fa[a] = get_fa(fa[a]);
}

void merge(int sm, int la, int val)
{
    for (auto temp : que[sm])
    {
        int v = temp.first;
        int id = temp.second;
        if (get_fa(v) == la)
            ans[id] = val;
        else
            que[la].push_back(temp);
    }
    fa[sm] = la;
}

int main()
{
    fastio;
    freopen("truck.in", "r", stdin);
    freopen("truck.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edge.push_back(truck(u, v, w));
    }
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        ans[i] = -1;
        scanf("%d%d", &u, &v);
        que[u].push_back({v, i});
        que[v].push_back({u, i});
    }
    sort(edge.begin(), edge.end(), cmp);
    for (truck temp : edge) // 从大开始合并
    {
        int sm = get_fa(temp.u);
        int la = get_fa(temp.v);
        if (sm == la)
            continue;
        if (que[sm].size() > que[la].size())
            swap(sm, la);
        merge(sm, la, temp.val);
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
    return 0;
}