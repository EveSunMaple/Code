#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#define MAX 20000
#define ll long long

using namespace std;

ll head[MAX * 2];  //节点数组
ll down[MAX * 2];  //节点数组子节点的边的下标
ll ver[MAX * 2];   //有向边数组
ll edge[MAX];      //节点的值
bool up[MAX];      //标记节点
ll sum[MAX];       //节点与子节点的最大和
ll tot = 0;        //边数量
ll ans = -1e9;     //所有情况的最值

void add(int crd, int son)
{
    tot++;
    ver[tot] = son;         //有向边加一
    down[tot] = head[crd];  //把节点的第一条边作为down数组的值（插入第一位）
    head[crd] = tot;        //重置节点指向第一条边
}

int solve(int crd)
{
    sum[crd] = edge[crd];   //加上自己的值
    up[crd] = true;
    for(int i = head[crd]; i; i = down[i])
    {
        int son = ver[i];
        if(up[son] == true) continue;
        up[son] = true; 
        ll now = solve(son);
        if(now > 0)
            sum[crd] += now;
    }
    //ans = max(ans, sum[crd]);
    return sum[crd];
}

void update(int crd, int father, ll map[])
{
    if(map[crd] > 0) map[father] -= map[crd];
    if(map[father] > 0) map[crd] += map[father];
    ans = max(ans, map[crd]);
    for(int i = head[crd]; i; i = down[i])
    {
        int son = ver[i];
        if(up[son] == true) continue;
        up[son] = true; 
        update(son, crd, map);
    }
}

int main()
{
    int N;
    //freopen("P1122_4.in", "r", stdin);
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++)
        scanf("%lld", &edge[i]);
    for(int i = 1; i < N; i++)
    {
        int u, v;
        scanf("%d %d",&u, &v);
        add(u, v);
        add(v, u);
    }
    
    solve(1);

    memset(up, 0, sizeof(up));

    update(1, 0, sum);

    cout << ans;

    return 0;
}
