#include <iostream>
#include <cmath>
#include <cstring>
#define ll long long
#define MAX 200009

using namespace std;

ll num[MAX];

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
    ll lazy = tree[crd].lazy % 2;
    ll l = crd * 2, r = crd * 2 + 1;

    tree[l].lazy += tree[crd].lazy; 
    tree[r].lazy += tree[crd].lazy;
    if(lazy == 1)
    {
    	tree[l].sum = (tree[l].r - tree[l].l + 1) - tree[l].sum;
    	tree[r].sum = (tree[r].r - tree[r].l + 1) - tree[r].sum;
	}
	
    tree[crd].lazy= 0;

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
    	tree[crd].sum = (crd_r - crd_l + 1) - tree[crd].sum;
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
    tree[crd].r = r;                            

    if(l == r)
    {
        tree[crd].sum = num[r];               
        return;
    }

    build(crd * 2, l, (l + r) / 2);             
    build(crd * 2 + 1, (l + r) / 2 + 1, r);     
    Pushup(crd);                                

    return;
}

int main()
{
    freopen("E:\\Coding\\TEXT\\P2574_2.in", "r", stdin); 
    
    ll n = 0, m = 0;
    scanf("%lld %lld", &n, &m);
    
    string cnt;
    cin >> cnt;

    for(int i = 1; i <= n; i++)
    {
        num[i] = (ll)cnt[i - 1] - 48;
        //cout << i << " : " << num[i] << endl; 
    }

    build(1, 1, n);

    for(int i = 1; i <= m; i++)
    {
        ll t;
        ll l, r;
        scanf("%lld", &t);
        if(t == 0)
        {
            scanf("%lld %lld", &l, &r);
            Update(1, l, r, 1);
        }
        if(t == 1)
        {
            scanf("%lld %lld", &l, &r);
            printf("%lld\n", check(1, l, r));
        }
    }

    return 0;
}
