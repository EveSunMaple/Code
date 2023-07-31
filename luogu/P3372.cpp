#include <iostream>
#include <cmath>
#define ll long long
#define MAX 500005

using namespace std;

ll num[MAX];

//定义节点
class node
{
public:
    ll l, r;
    ll sum, lazy;
}tree[MAX * 4];

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
    
    if(l <= crd_l && r >= crd_r)
    {          
        return tree[crd].sum;
    }
    
    Pushdown(crd);
    
    if(r > mid)
        sum += check(crd * 2 + 1, l, r);
    if(l <= mid)
        sum += check(crd * 2, l, r);

    return sum;
}

void Update(ll crd, ll l, ll r, ll num)
{
    
    ll crd_l = tree[crd].l;
    ll crd_r = tree[crd].r;
    ll sum = 0, mid = (crd_l + crd_r) / 2;
    
    if(l <= crd_l && r >= crd_r)
    {          
        tree[crd].lazy += num;
        tree[crd].sum += num * (crd_r - crd_l + 1);
        return;
    }

    Pushdown(crd);

    if(r > mid)
        Update(crd * 2 + 1, l, r, num);
    if(l <= mid)
        Update(crd * 2, l, r, num);

    Pushup(crd);

    return;
}

void build(ll crd, ll l, ll r)
{
    tree[crd].l = l;
    tree[crd].r = r;                            //把区间确定

    if(l == r)
    {
        tree[crd].sum = num[r];               //赋值
        return;
    }

    build(crd * 2, l, (l + r) / 2);             //左儿子
    build(crd * 2 + 1, (l + r) / 2 + 1, r);     //右儿子
    Pushup(crd);                                //儿子求和

    return;
}

int main()
{
    ll n = 0, m = 0;
    scanf("%lld %lld", &n, &m);

    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &num[i]);
    }

    build(1, 1, n);     //建树

    for(int i = 1; i <= m; i++)
    {
        ll t;
        ll l, r;
        scanf("%lld", &t);
        if(t == 1)
        {
            ll num;
            scanf("%lld %lld %lld", &l, &r, &num);
            Update(1, l, r, num);
        }
        if(t == 2)
        {
            scanf("%lld %lld", &l, &r);
            printf("%lld\n", check(1, l, r));
        }
    }

    return 0;
}