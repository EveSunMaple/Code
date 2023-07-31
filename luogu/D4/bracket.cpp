#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define ll long long
#define N 1000005

using namespace std;

const int p = 1e9 + 7;
string line;
bool tag[N];
int len;

class node
{
public:
    ll l, r;
    ll sum, lazy;
} tree[N << 2];

void Pushup(ll crd)
{
    tree[crd].sum = tree[crd * 2].sum + tree[crd * 2 + 1].sum;

    return;
}
void Pushdown(ll crd)
{
    ll lazy = tree[crd].lazy;
    ll l = crd * 2, r = crd * 2 + 1;

    tree[l].lazy += lazy;
    tree[r].lazy += lazy;
    tree[l].sum += lazy * (tree[l].r - tree[l].l + 1);
    tree[r].sum += lazy * (tree[r].r - tree[r].l + 1);
    tree[crd].lazy = 0;

    return;
}
ll check(ll crd, ll l, ll r)
{
    ll crd_l = tree[crd].l;
    ll crd_r = tree[crd].r;
    ll sum = 0, mid = (crd_l + crd_r) / 2;

    if (l <= crd_l && r >= crd_r)
    {
        return tree[crd].sum;
    }

    Pushdown(crd);

    if (r > mid)
        sum += check(crd * 2 + 1, l, r);
    if (l <= mid)
        sum += check(crd * 2, l, r);

    return sum;
}
void Update(ll crd, ll l, ll r, ll num)
{

    ll crd_l = tree[crd].l;
    ll crd_r = tree[crd].r;
    ll sum = 0, mid = (crd_l + crd_r) / 2;

    if (l <= crd_l && r >= crd_r)
    {
        tree[crd].lazy += num;
        tree[crd].sum += num * (crd_r - crd_l + 1);
        return;
    }

    Pushdown(crd);

    if (r > mid)
        Update(crd * 2 + 1, l, r, num);
    if (l <= mid)
        Update(crd * 2, l, r, num);

    Pushup(crd);

    return;
}
void build(ll crd, ll l, ll r)
{
    tree[crd].l = l;
    tree[crd].r = r;

    if (l == r)
    {
        tree[crd].sum = 0;
        return;
    }

    build(crd * 2, l, (l + r) / 2);
    build(crd * 2 + 1, (l + r) / 2 + 1, r);
    Pushup(crd);

    return;
}

int find(int crd)
{
    tag[crd] = true;
    int time_l = 1;
    int time_r = 0;
    for (int i = crd; i <= len; i++)
    {
        if (line[i] == '(')  
        {
            time_l++;
            if (!tag[i + 1])
                find(i + 1);
        }
        else time_r++;
        if (time_r > time_l) return i;
        if (time_l == time_r) // find a bracket -> i = )
        {
            time_l = time_r = 0;
            //printf("HAVE->(%d, %d)\n", crd - 1, i);
            Update(1, crd - 1, i, 1);
        }
        //if (time_l == 1) find(i + 1, deep);
        //if (time_l == 2) find(i + 1, deep + 1);
    }
    return len;
}

int main()
{
    freopen("bracket.in", "r", stdin);
    freopen("bracket.out", "w", stdout);
    fastio;
    cin >> line;
    len = line.length() - 1;
    build(1, 0, len);
    for (int i = 0; i <= len; i++)
    {
        if (line[i] == '(') i = find(i + 1);
        //cout << i << endl;
    }
    ll ans = 0;
    for (int i = 0; i <= len; i++)
    {
        //printf("%lld ", check(1, i, i));
        ans = (ans + ((i + 1) * check(1, i, i) % p)) % p;
    }
    printf("%lld", ans);
    return 0;
}
