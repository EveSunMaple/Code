#pragma GCC optimize ("O2")
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 200005
#define ll long long
#define mod 1000000007
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)

using namespace std;

bool num[N];
char list[N];
ll prepar[N];

// ll gol(ll n)
// {
//     return n << 1;
// }
//
// ll gor(ll n)
// {
//     return (n << 1) + 1;
// }
//
// class node
// {
// public:
//     ll l, r;
//     ll sum, lazy;
// }tree[N * 4];
//
// void Pushup(ll crd)
// {
//     tree[crd].sum = tree[gol(crd)].sum + tree[gor(crd)].sum;
// }
// void Pushdown(ll crd)
// {
//     ll lazy = tree[crd].lazy;
//     ll l = gol(crd), r = gor(crd);
//
//     tree[l].lazy += lazy;
//     tree[r].lazy += lazy;
//     tree[l].sum += lazy * (tree[l].r - tree[l].l + 1);
//     tree[r].sum += lazy * (tree[r].r - tree[r].l + 1);
//     tree[crd].lazy = 0;
// }
//
// ll check(ll crd, ll l, ll r)
// {
//     ll crd_l = tree[crd].l;
//     ll crd_r = tree[crd].r;
//     ll sum = 0, mid = (crd_l + crd_r) >> 1;
//
//     if(l <= crd_l && r >= crd_r)
//     {
//         return tree[crd].sum;
//     }
//
//     Pushdown(crd);
//     if(l <= mid) sum += check(gol(crd), l, r);
//     if(r > mid) sum += check(gor(crd), l, r);
//     return sum;
// }
//
// void Update(ll crd, ll l, ll r, ll num)
// {
//
//     ll crd_l = tree[crd].l;
//     ll crd_r = tree[crd].r;
//     ll mid = (crd_l + crd_r) >> 1;
//
//     if(l <= crd_l && r >= crd_r)
//     {
//         tree[crd].lazy += num;
//         tree[crd].sum += num * (crd_r - crd_l + 1);
//         return;
//     }
//
//     Pushdown(crd);
//     if(l <= mid) Update(gol(crd), l, r, num);
//     if(r > mid) Update(gor(crd), l, r, num);
//     Pushup(crd);
// }
//
// void Clear(ll crd, ll l, ll r)
// {
//     ll crd_l = tree[crd].l;
//     ll crd_r = tree[crd].r;
//     ll mid = (crd_l + crd_r) >> 1;
//
// 	if(crd_l == crd_r)
//     {
//         tree[crd].sum = 0;
// 		tree[crd].lazy = 0;
// 		return;
//     }
//
//     Pushdown(crd);
//     if(l <= mid) Clear(gol(crd), l, r);
//     if(r > mid) Clear(gor(crd), l, r);
// 	Pushup(crd);
// }
//
// void build(ll crd, ll l, ll r)
// {
//     tree[crd].l = l;
//     tree[crd].r = r;
//
//     if(l == r)
//     {
//         tree[crd].sum = (list[r - 1] - '0');
//         return;
//     }
//
//     build(gol(crd), l, (l + r) >> 1);
//     build(gor(crd), ((l + r) >> 1) + 1, r);
//     Pushup(crd);
// }

int main()
{
    fastio;
    freopen("D.in", "r", stdin);
    freopen("D copy.out", "w", stdout);
    cin >> list;
    int len = strlen(list);
    prepar[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        num[i] = list[i - 1] - '0';
        prepar[i] = (prepar[i - 1] * 2) % mod;
    }
    int n;
    cin >> n;
    while (n--)
    {
        ll op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            int has = 0;
            for (int i = l; i <= r; i++)
            {
                if (num[i]) 
                {
                    num[i] = 0;
                    has++;
                }
            }
            for (int i = l; i < has + l; i++)
                num[i] = 1;
        }
        else if (op == 2)
        {
            int has = 0;
            for (int i = l; i <= r; i++)
            {
                if (num[i]) 
                {
                    num[i] = 0;
                    has++;
                }
            }
            for (int i = r; i > r - has; i--)
                num[i] = 1;
        }
        else if (op == 3)
        {
            ll cnt = 0, ans = 0;
            for (int i = r; i >= l; i--)
            {
                if (num[i]) ans = (ans + prepar[cnt]) % mod;
                cnt++;
            }
            // printf("%lld\n", ans);
            cout << ans << '\n';
        }
    }
    return 0;
}
