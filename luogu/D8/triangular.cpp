#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define ll long long
#define N 1005

using namespace std;

bool ins[N];

class node
{
public:
    ll l, r;
    ll sum, lazy;
}tree[N][N << 2];

void Pushup(ll tag, ll crd)
{
    tree[tag][crd].sum = tree[tag][crd * 2].sum + tree[tag][crd * 2 + 1].sum;
}
void Pushdown(ll tag, ll crd)
{
    ll lazy = tree[tag][crd].lazy;
    ll l = crd * 2, r = crd * 2 + 1;

    tree[tag][l].lazy += lazy;
    tree[tag][r].lazy += lazy;
    tree[tag][l].sum += lazy * (tree[tag][l].r - tree[tag][l].l + 1);
    tree[tag][r].sum += lazy * (tree[tag][r].r - tree[tag][r].l + 1);
    tree[tag][crd].lazy = 0;
}
ll check(ll tag, ll crd, ll l, ll r)
{
    ll crd_l = tree[tag][crd].l;
    ll crd_r = tree[tag][crd].r;
    ll sum = 0, mid = (crd_l + crd_r) / 2;

    if (l <= crd_l && r >= crd_r)
    {
        return tree[tag][crd].sum;
    }

    Pushdown(tag, crd);

    if (r > mid)
        sum += check(tag, crd * 2 + 1, l, r);
    if (l <= mid)
        sum += check(tag, crd * 2, l, r);

    return sum;
}
void Update(ll tag, ll crd, ll l, ll r, ll num)
{

    ll crd_l = tree[tag][crd].l;
    ll crd_r = tree[tag][crd].r;
    ll sum = 0, mid = (crd_l + crd_r) / 2;

    if (l <= crd_l && r >= crd_r)
    {
        tree[tag][crd].lazy += num;
        tree[tag][crd].sum += num * (crd_r - crd_l + 1);
        return;
    }

    Pushdown(tag, crd);

    if (r > mid)
        Update(tag, crd * 2 + 1, l, r, num);
    if (l <= mid)
        Update(tag, crd * 2, l, r, num);

    Pushup(tag, crd);

    return;
}
void build(ll tag, ll crd, ll l, ll r)
{
    tree[tag][crd].l = l;
    tree[tag][crd].r = r;

    if (l == r)
    {
        tree[tag][crd].sum = 0;
        return;
    }

    build(tag, crd * 2, l, (l + r) / 2);
    build(tag, crd * 2 + 1, (l + r) / 2 + 1, r);
    Pushup(tag, crd);
}

int main()
{
    freopen("triangular.in", "r", stdin);
    freopen("triangular.out", "w", stdout);
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (!ins[x]) { build(x, 1, 1, 1000); ins[x] = true; }
        Update(x, 1, y, y, 1);
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y, d, ans = 0, temp = 0;
        scanf("%d%d%d", &x, &y, &d);
        for (int j = x; j <= x + d; j++)
        {
            ll val = 0;
            if (ins[j]) val = check(j, 1, y, y + d - temp);
            printf("[%d][%d~%d]<%d> \n", j, y, y + d - temp, val);
            ans += val;
            temp++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
