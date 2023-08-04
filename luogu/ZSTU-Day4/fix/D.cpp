#pragma GCC optimize ("O2")
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 200005
#define ll long long
#define mod 1000000007
#define gol(n) n << 1
#define gor(n) (n << 1) + 1
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)

using namespace std;

ll prepar[N];
char list[N];
bool num[N];

class node
{
public:
    ll l, r;
    ll sum, real;
    int lazy;
    node()
    { l = 0; r = 0; sum = 0; real = 0; lazy = -1; }
}tree[N * 4];

void Pushup(ll crd)
{
    tree[crd].sum = tree[gol(crd)].sum + tree[gor(crd)].sum;
    tree[crd].real = (((tree[gol(crd)].real * prepar[tree[gor(crd)].r - tree[gor(crd)].l + 1]) % mod) + tree[gor(crd)].real) % mod;
}
void Pushdown(ll crd)
{
    ll lazy = tree[crd].lazy;
    ll l = gol(crd), r = gor(crd);

	if (lazy >= 0)
    {
		tree[l].lazy = lazy; 
	    tree[r].lazy = lazy;
	}
    if (tree[l].lazy == 0) { tree[l].sum = 0; tree[l].real = 0; }
	if (tree[r].lazy == 0) { tree[r].sum = 0; tree[r].real = 0; }
    if (tree[l].lazy == 1) { tree[l].sum = tree[l].r - tree[l].l + 1; tree[l].real = (prepar[tree[l].sum] - 1) % mod; }
	if (tree[r].lazy == 1) { tree[r].sum = tree[r].r - tree[r].l + 1; tree[r].real = (prepar[tree[r].sum] - 1) % mod; }
    tree[crd].lazy = -1;
}

void Update(ll crd, ll l, ll r, ll tag)
{
    ll crd_l = tree[crd].l;
    ll crd_r = tree[crd].r;
    ll mid = (crd_l + crd_r) >> 1;
    
    if(l <= crd_l && r >= crd_r)
    {          
        tree[crd].lazy = tag;
        if (tag == 0)
        {
            tree[crd].sum = 0; 
            tree[crd].real = 0;
        }
        if (tag == 1)
        {
            tree[crd].sum = crd_r - crd_l + 1; 
            tree[crd].real = prepar[tree[crd].sum] - 1;
        }
		Pushdown(crd);
        return;
    }

    Pushdown(crd);
    if(l <= mid) Update(gol(crd), l, r, tag);
    if(r > mid) Update(gor(crd), l, r, tag);
    Pushup(crd);
}

ll GetReal(ll crd, ll l, ll r)
{
    ll crd_l = tree[crd].l;
    ll crd_r = tree[crd].r;
    ll sum = 0, mid = (crd_l + crd_r) >> 1;
    
    if(l <= crd_l && r >= crd_r)
    {          
        return (tree[crd].real * prepar[r - crd_r]) % mod;
    }
    
    Pushdown(crd);
    if(l <= mid) sum = (sum + GetReal(gol(crd), l, r)) % mod;
    if(r > mid) sum = (sum + GetReal(gor(crd), l, r)) % mod;
    Pushup(crd);
    return sum;
}

ll GetSum(ll crd, ll l, ll r)
{
    ll crd_l = tree[crd].l;
    ll crd_r = tree[crd].r;
    ll sum = 0, mid = (crd_l + crd_r) >> 1;
    
    if(l <= crd_l && r >= crd_r)
    {          
        return tree[crd].sum;
    }
    
    Pushdown(crd);
    if(l <= mid) sum = (sum + GetSum(gol(crd), l, r)) % mod;
    if(r > mid) sum = (sum + GetSum(gor(crd), l, r)) % mod;
    Pushup(crd);
    return sum;
}

void build(ll crd, ll l, ll r)
{
    tree[crd].l = l;
    tree[crd].r = r;

    if(l == r)
    {
        tree[crd].sum = num[r];
        if (num[r]) tree[crd].real = 1;
        return;
    }

    build(gol(crd), l, (l + r) >> 1);            
    build(gor(crd), ((l + r) >> 1) + 1, r);    
    Pushup(crd);
}

int main()
{
    fastio;
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    cin >> list;
    int len = strlen(list);
    prepar[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        num[i] = list[i - 1] - '0';
        prepar[i] = (prepar[i - 1] << 1) % mod;
    }
    build(1, 1, len);
    int T; 
    cin >> T;
    while (T--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            ll has = GetSum(1, l, r);
            Update(1, l, r, 0);
            if (has)
                Update(1, l, l + has - 1, 1);
        }
        else if (op == 2)
        {
            ll has = GetSum(1, l, r);
            Update(1, l, r, 0);
            if (has)
                Update(1, r - has + 1, r, 1);
        }
        else if (op == 3)
            cout << GetReal(1, l, r) << endl;
    }
    return 0;
}