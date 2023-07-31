#include <algorithm>
#include <iostream>
#include <cmath>
#define N 200005

using namespace std;

int num[N];
bool tag[N];

class node
{
public:
    bool lazy;
    int l, r, sum;
}tree[N * 4];

class quest
{
public:
    int l, r;
}way[N];

void Pushup(int crd)
{
    tree[crd].sum = tree[crd * 2].sum + tree[crd * 2 + 1].sum;
}
void Pushdown(int crd)
{
    bool lazy = tree[crd].lazy;
    int l = crd * 2, r = crd * 2 + 1;

    tree[l].lazy = lazy || tree[l].lazy; 
    tree[r].lazy = lazy || tree[r].lazy;
    if (tree[l].lazy) tree[l].sum = 0; // tree[l].r - tree[l].l + 1;
    if (tree[r].lazy) tree[r].sum = 0; // tree[r].r - tree[r].l + 1;
}

int check(int crd, int l, int r)
{
    int crd_l = tree[crd].l;
    int crd_r = tree[crd].r;
    int sum = 0, mid = (crd_l + crd_r) / 2;
    
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

void Update(int crd, int l, int r)
{
    
    int crd_l = tree[crd].l;
    int crd_r = tree[crd].r;
    int sum = 0, mid = (crd_l + crd_r) / 2;
    
    if (l <= crd_l && r >= crd_r)
    {          
        tree[crd].lazy = true;
        tree[crd].sum = 0; // crd_r - crd_l + 1;
        return;
    }

    Pushdown(crd);

    if (r > mid)
        Update(crd * 2 + 1, l, r);
    if (l <= mid)
        Update(crd * 2, l, r);

    Pushup(crd);
}

void build(int crd, int l, int r)
{
    tree[crd].l = l;
    tree[crd].r = r;                           

    if (l == r)
    {
        tree[crd].sum = num[r];               
        return;
    }

    build(crd * 2, l, (l + r) / 2);            
    build(crd * 2 + 1, (l + r) / 2 + 1, r);    
    Pushup(crd);         
}

bool cmp(quest a, quest b)
{
    int ran_a = a.r - a.l + 1;
    int ran_b = b.r - b.l + 1;
    if (ran_a != ran_b) return ran_a < ran_b;
	return a.r < b.r;
	// return (double)check(1, a.l, a.r) / (double)ran_a > (double)check(1, b.l, b.r) / (double)ran_b;
	// return a.l < b.l;
}

int L, R;

// void dfs(int &ans, int crd, int l, int r)
// {
//     // ans = max(ans, check(1, l, r));
//     if (way[crd + 1].l < r) 
//     {
//     	//if (way[crd + 1].r > r)
//         dfs(ans, crd + 1, l, way[crd + 1].r);
//         if (tag[crd + 1] == false)
//         {
//             tag[crd + 1] = true;
//             dfs(ans, crd + 1, way[crd + 1].l, way[crd + 1].r);
//         }
//     }
//     int temp = check(1, l, r);
//     if (temp > ans)
//     {
//         ans = temp;
//         L = l;
//         R = r;
//     }
// }

int main()
{
    freopen("future.in", "r", stdin);
    freopen("future.out", "w", stdout);
    int n, m, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
        if (num[i] == 0) 
        {
            num[i] = -1;
            ans++;
        }
    }
    build(1, 1, n);    
    scanf("%d", &m); 
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &way[i].l, &way[i].r);
    sort(way + 1, way + 1 + m, cmp);
    // for (int i = 1; i <= m; i++)
    // {
    //     int temp = -1e9; L = 0; R = 0;
    //     //if (tag[i]) continue;
    //     dfs(temp, i, way[i].l, way[i].r);
    //     tag[i] = true;
    //     printf("%d %d %d\n", temp, L, R);
    //     if (temp > 0)
    //     {
    //         ans += temp;
    //         Update(1, L, R);
    //     }
    // }
    for (int i = 1; i <= m; i++)
    {
        int l = way[i].l, r = way[i].r;
        int origin = r - l + 1;
        int temp = check(1, l, r);
        if (temp > 0) 
        {
            ans += temp;
            Update(1, l, r);
        }
    }
    printf("%d", ans);
    return 0;
}
