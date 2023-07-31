#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 300000;

vector<int> G[N + 5];
multiset<ll> f[N + 5];

struct range
{
    int l, r, a;

    bool operator<(const range &rhs) const
    {
        return l < rhs.l || (l == rhs.l && r > rhs.r);
    }
} r[N + 5];

void merge(multiset<ll> &a, multiset<ll> &b)
{
    if (a.size() < b.size())
        swap(a, b);

    vector<ll> p;
    for (auto x : b)
    {
        p.push_back(x + *a.begin());
        a.erase(a.begin());
    }
    for (auto x : p)
        a.insert(x);
}

void dfs(int u)
{
    for (int i = 0; i < (int)G[u].size(); ++i)
    {
        int v = G[u][i];
        dfs(v);
        merge(f[u], f[v]);
    }
    f[u].insert(-r[u].a);
}

int n;

int main()
{
    scanf("%*d%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", &r[i].l, &r[i].r, &r[i].a);
    }

    vector<int> stk;
    stk.push_back(0);
    sort(r + 1, r + n + 1);

    for (int i = 1; i <= n; ++i)
    {
        while (stk.back() != 0 && r[stk.back()].r < r[i].r)
            stk.pop_back();
        G[stk.back()].push_back(i);
        stk.push_back(i);
    }
    dfs(0);

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (f[0].size())
        {
            ans -= *f[0].begin();
            f[0].erase(f[0].begin());
        }
        printf("%lld ", ans);
    }
    return 0;
}
