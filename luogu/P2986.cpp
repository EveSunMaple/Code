#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#define MAX 100005
#define ll long long

using namespace std;

ll head[MAX * 2];  
ll down[MAX * 2];  
ll edge[MAX * 2];     
ll ver[MAX * 2];   
bool up[MAX];    
ll cow[MAX];         
ll num[MAX];        
ll sum[MAX];       
ll tot = 0;        
ll ans = 1e9;     
ll cnt = 0;
int N;

void add(int crd, int son, int w)
{
    tot++;
    edge[tot] = w;
    ver[tot] = son;         
    down[tot] = head[crd];  
    head[crd] = tot;        
}

void solve(int crd)
{
    num[crd] = cow[crd];
    up[crd] = true;
    for(int i = head[crd]; i; i = down[i])
    {
        int son = ver[i];
        if(up[son] == true) continue;
        up[son] = true; 
        solve(son);
        num[crd] += num[son];
        sum[crd] += sum[son];
        sum[crd] += num[son] * edge[i];
    }
}

void update(int crd, int father, int lin, ll map[], ll now[])
{
    up[crd] = true;
    if(father > 0)
    {
        map[father] -= map[crd];
        map[father] -= now[crd] * edge[lin];

        now[father] -= now[crd];
        now[crd] += now[father];

        map[crd] += map[father];
        map[crd] += now[father] * edge[lin];
    }
    ans = min(ans, map[crd]);
    for(int i = head[crd]; i; i = down[i])
    {
        int son = ver[i];
        if(up[son] == true) continue;
        up[son] = true; 
        //ll a[N + 1];
        //ll b[N + 1];
        //for(int i = 1; i <= N; i++)
        //{
        //    a[i] = map[i];
        //    b[i] = num[i];
        //}
        update(son, crd, i, map, num);
    }
}

int main()
{
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++)
    {
        scanf("%lld", &cow[i]);
        cnt += cow[i];
    }
    for(int i = 1; i < N; i++)
    {
        int u, v, w;
        scanf("%d %d %d",&u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    
    solve(1);
    
    //for(int i = 1; i <= N; i++)
    //{
    //    solve(i);
    //    ans = min(ans, sum[i]);
    //    memset(up, 0, sizeof(up));
    //    memset(sum, 0, sizeof(sum));
    //}

    memset(up, 0, sizeof(up));

    update(1, 0, 0, sum, num);

    cout << ans;

    return 0;
}