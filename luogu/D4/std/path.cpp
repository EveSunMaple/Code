#include <bits/stdc++.h>
using namespace std;

#define N 400005

#define pb push_back
int fa[N];
struct node
{
    int x, y, z;
} b[N];
int ans[N], n, m, Q;
set<array<int, 2>> q[N];
set<int> e[N];

int get(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = get(fa[x]);
}

inline bool cmp(node x, node y)
{
    return x.z < y.z;
}

void combine(int x, int y, int val)
{
    for (auto u : e[x])
    {
        while (1)
        {
            auto it = q[y].lower_bound({u, -1});
            if (it == q[y].end() || (*it)[0] != u)
                break;
            int id = (*it)[1];
            ans[id] = val;
            assert(q[y].count({u, id}));
            assert(q[u].count({y, id}));
            q[y].erase(it);
            q[u].erase({y, id});
        }
    }
    vector<array<int, 2>> delq;
    for (auto u : q[x])
    {
        if (e[y].count(u[0]))
        {
            ans[u[1]] = val;
            q[u[0]].erase({x, u[1]});
            delq.pb(u);
        }
    }
    for (auto u : delq)
        q[x].erase(u);
    fa[x] = y;
    for (auto v : e[x])
    {
        assert(e[v].count(x));
        e[v].erase(x);
        if (v != y)
        {
            e[v].insert(y);
            e[y].insert(v);
        }
    }
    e[x].clear();
    for (auto v : q[x])
    {
        assert(v[0] != y);
        assert(q[v[0]].count({x, v[1]}));
        q[v[0]].erase({x, v[1]});
        q[v[0]].insert({y, v[1]});
        q[y].insert({v[0], v[1]});
    }
    q[x].clear();
}

int main()
{
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &Q);
    for (int i = 1; i <= n; i++)
        e[i].clear(), q[i].clear();
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].z);
        e[b[i].x].insert(b[i].y);
        e[b[i].y].insert(b[i].x);
    }
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    sort(b + 1, b + 1 + m, cmp);
    for (int i = 1; i <= Q; i++)
    {
        ans[i] = 0;
        int x, y;
        scanf("%d%d", &x, &y);
        if (e[x].count(y))
        {
            ans[i] = 1;
            continue;
        }
        q[x].insert({y, i});
        q[y].insert({x, i});
    }
    for (int i = 1; i <= m; i++)
    {
        b[i].x = get(b[i].x), b[i].y = get(b[i].y);
        if (b[i].x == b[i].y)
            continue;
        if (q[b[i].x].size() + e[b[i].x].size() > q[b[i].y].size() + e[b[i].y].size())
            swap(b[i].x, b[i].y);
        combine(b[i].x, b[i].y, b[i].z + 1);
    }
    for (int i = 1; i <= Q; i++)
        printf("%d\n", ans[i] - 1);
}