#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 100005

using namespace std;

vector<int> g[N];
int fa[N], de[N];
int go_up[N];
bool vis[N];

struct Query
{
    int v, id;
};

struct Ans
{
    int u, v, fa;
};

bool cmp(Ans a, Ans b)
{
    return de[a.fa] > de[b.fa];
}

vector<Query> query[N];
Ans ans[N];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool check(int u, int fa)
{
    bool res = true;
    if (vis[u]) return false;
    if (u == fa) return res;
    res = check(go_up[u], fa);
    return res;
}

void update(int u, int fa)
{
    vis[u] = true;
    if (u == fa) return;
    update(go_up[u], fa);
}

void tarjan(int u, int d)
{
    de[u] = d;
    fa[u] = u;
    vis[u] = true;
    for (int v : g[u])
    {
        if (!vis[v])
        {
            tarjan(v, d + 1);
            go_up[v] = u;
            fa[v] = u;
        }
    }
    for (Query q : query[u])
    {
        int v = q.v, id = q.id;
        if (vis[v])
            ans[id].fa = find(v);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        query[u].push_back({v, i});
        query[v].push_back({u, i});
        ans[i].u = u; ans[i].v = v;
    }
    tarjan(1, 1);
    sort(ans + 1, ans + 1 + m, cmp);
    int res = 0;
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= m; i++)
    {
        Ans temp = ans[i];
        int u = temp.u;
        int v = temp.v;
        int fa = temp.fa;
        if (check(u, fa) && check(v, fa))
        {
            update(u, fa);
            update(v, fa);
            res++;
        }
    }
    printf("%d", res);
    // for (int i = 1; i <= m; i++)
    //     cout << ans[i] << endl;
    return 0;
}