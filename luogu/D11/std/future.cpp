#include <vector>
#include <cstdio>
#include <algorithm>
#define FOR(i, l, r) for(int i = l; i <= r; ++i)

using namespace std;

const int inf = 1e9;
const int N = 800010;

int mn[N], b[N];
int n, m, l, r, ans;
vector <int> p[N];

void build(int h, int l, int r)
{
    if (l == r)
    {
        if (!l) mn[h] = 0; else mn[h] = inf;
        return;
    }
    int mid = (l + r) >> 1;
    build(h << 1, l, mid); build(h << 1 | 1, mid + 1, r);
    mn[h] = min(mn[h << 1], mn[h << 1 | 1]);
}

int find(int h, int l, int r, int ll, int rr)
{
    if (l == ll && r == rr) return mn[h];
    int mid = (l + r) >> 1;
    if (rr <= mid) return find(h << 1, l, mid, ll, rr); else
    if (ll > mid) return find(h << 1 | 1, mid + 1, r, ll, rr); else
        return min(find(h << 1, l, mid, ll, mid), find(h << 1 | 1, mid + 1, r, mid + 1, rr));
}

void change(int h, int l, int r, int x, int y)
{
    if (l == r) {mn[h] = min(mn[h], y); return;}
    int mid = (l + r) >> 1;
    if (x <= mid) change(h << 1, l, mid, x, y);
        else change(h << 1 | 1, mid + 1, r, x, y);
    mn[h] = min(mn[h << 1], mn[h << 1 | 1]);
}

int main()
{
    freopen("future.in", "r", stdin);
    freopen("future.out", "w", stdout);
    
    scanf("%d", &n);
    ans = n;
    FOR(i, 0, n - 1)
    {
        scanf("%d", &b[i]);
        if (!b[i]) --ans;
    }
    scanf("%d", &m);
    FOR(i, 1, m)
    {
        scanf("%d%d", &l, &r);
        p[l - 1].push_back(r);
    }
    build(1, 0, n);
    FOR(i, 0, n - 1)
    {
        for(int j = 0; j < p[i].size(); ++j)
            change(1, 0, n, p[i][j], find(1, 0, n, i, p[i][j]));
        change(1, 0, n, i + 1, find(1, 0, n, i, i) + (b[i] ? 1 : -1));
    }
    printf("%d\n", ans - find(1, 0, n, n, n));
    return 0;
}
