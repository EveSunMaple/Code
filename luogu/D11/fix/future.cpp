#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 200005
#define INF 1e9

using namespace std;

int s[N];
vector<int> que[N];
class node
{
public:
    int l, r, val;
}tree[N * 4];

void Pushup(int crd)
{
    tree[crd].val = min(tree[crd << 1].val, tree[crd << 1 | 1].val);
}

int check(int crd, int l, int r)
{
    int crd_l = tree[crd].l;
    int crd_r = tree[crd].r;
    int sum = INF, mid = (crd_l + crd_r) >> 1;
    if (l <= crd_l && r >= crd_r)
    {   
        return tree[crd].val;
    }
    if (r > mid)
        sum = min(sum, check(crd << 1 | 1, l, r));
    if (l <= mid)
        sum = min(sum, check(crd << 1, l, r));
    return sum;
    // if (r <= mid) return check(crd << 1, l, r); 
    // else if (l > mid) return check(crd << 1 | 1, l, r); 
    // else return min(check(crd << 1, l, mid), check(crd << 1 | 1, mid + 1, r));
}

void Update(int crd, int aim, int val)
{
    int crd_l = tree[crd].l;
    int crd_r = tree[crd].r;
    int mid = (crd_l + crd_r) >> 1;
    if (crd_l == crd_r)
    {          
        tree[crd].val = min(val, tree[crd].val);
        return;
    }
    if (aim > mid)
        Update(crd << 1 | 1, aim, val);
    if (aim <= mid)
        Update(crd << 1, aim, val);
    Pushup(crd);
}

void build(int crd, int l, int r)
{
    tree[crd].l = l;
    tree[crd].r = r;     
    if (l == r)
    {
        if (!l) tree[crd].val = 0;
        else  tree[crd].val = INF;
        return;
    }
    build(crd << 1, l, (l + r) >> 1);            
    build(crd << 1 | 1, ((l + r) >> 1) + 1, r);    
    Pushup(crd);         
}

int main()
{
    freopen("future.in", "r", stdin);
    freopen("future.out", "w", stdout);
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        if (s[i]) ans++;
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        que[l - 1].push_back(r);
    }
    build(1, 0, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < que[i].size(); j++)
            Update(1, que[i][j], check(1, i, que[i][j]));
        Update(1, i + 1, check(1, i, i) + (s[i] ? 1 : -1));
    }
    printf("%d\n", ans - check(1, n, n));
    return 0;
}