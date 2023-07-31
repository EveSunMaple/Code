#include <iostream>
#include <cmath>
#define ll long long
#define MAX 500005

using namespace std;

ll num[MAX];
ll p = 0;

//定义节点
class node
{
public:
    ll l, r;
    ll sum, add, mul;
}tree[MAX * 4];

void Pushup(ll crd)
{
    tree[crd].sum = (tree[crd * 2].sum + tree[crd * 2 + 1].sum) % p;

    return;
}
void Pushdown(ll crd)
{
    
    ll add = tree[crd].add;
    ll mul = tree[crd].mul;
    ll l = crd * 2, r = crd * 2 + 1;

    //printf("tr[%lld] to tr[%lld] & tr[%lld]\n",crd,l,r);

    tree[l].sum = (tree[l].sum * mul + add * (tree[l].r - tree[l].l + 1)) % p;
    tree[r].sum = (tree[r].sum * mul + add * (tree[r].r - tree[r].l + 1)) % p;

    tree[l].mul = (tree[l].mul * mul) % p;
    tree[r].mul = (tree[r].mul * mul) % p;
    tree[l].add = (tree[l].add * mul + add) % p; 
    tree[r].add = (tree[r].add * mul + add) % p; 

    tree[crd].add = 0; 
    tree[crd].mul = 1; 

    return;
}

ll check(ll crd, ll l, ll r)
{
    ll crd_l = tree[crd].l;
    ll crd_r = tree[crd].r;
    ll sum = 0, mid = (crd_l + crd_r) / 2;
    
    if(l <= crd_l && r >= crd_r)
    {          
        return tree[crd].sum % p;
    }
    
    Pushdown(crd);
    
    if(r > mid)
        sum = (sum + check(crd * 2 + 1, l, r)) % p;
    if(l <= mid)
        sum = (sum + check(crd * 2, l, r)) % p;

    return sum % p;
}

void Update(ll cnt, ll crd, ll l, ll r, ll num)
{
    ll crd_l = tree[crd].l;
    ll crd_r = tree[crd].r;
    ll mid = (crd_l + crd_r) / 2;
    
    if(l <= crd_l && r >= crd_r)
    {          
        if(cnt == 1)
        {
            tree[crd].add = (tree[crd].add * num) % p;
            tree[crd].mul = (tree[crd].mul * num) % p;
            tree[crd].sum = (tree[crd].sum * num) % p;
        }
        if(cnt == 2)
        {
            tree[crd].add = (tree[crd].add + num) % p;
            tree[crd].sum = (tree[crd].sum + num * (crd_r - crd_l + 1)) % p;
        }

        return;
    }

    Pushdown(crd);

    if(r > mid)
        Update(cnt, crd * 2 + 1, l, r, num);
    if(l <= mid)
        Update(cnt, crd * 2, l, r, num);

    Pushup(crd);

    return;
}

void build(ll crd, ll l, ll r)
{
    tree[crd].l = l;
    tree[crd].r = r;                            //把区间确定
	tree[crd].mul = 1;

    if(l == r)
    {
        tree[crd].sum = num[r] % p;               //赋值
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
    scanf("%lld %lld %lld", &n, &m, &p);

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
            Update(t, 1, l, r, num);
        }
        if(t == 2)
        {
            ll num;
            scanf("%lld %lld %lld", &l, &r, &num);
            Update(t, 1, l, r, num);
        }
        if(t == 3)
        {
            scanf("%lld %lld", &l, &r);
            printf("%lld\n", check(1, l, r));
        }
    }

    return 0;
}