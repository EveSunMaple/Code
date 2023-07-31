#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define MAX 500005
#define ll long long

using namespace std;

//vector<int> g[MAX]; // 邻接表存储图
struct star
{
    int ver; // 指向的结点
    int next; // 下一条边
}node[MAX * 2];
int head[MAX]; // 表头数组
int update[MAX][21]; // update[i][j] 表示节点 i 的第 2^j 个祖先
int deep[MAX]; // deep[i] 表示节点 i 的深度
bool vit[MAX]; // 标记数组，用于 DFS 遍历
int edge[MAX]; // 用于储存树上差分的数组
int N, K; // N 表示主要边数，K 表示运输线路
ll ans; // 存储最大压力的边的压力
int tot; // 当前边的数量

// 前向星添加边
void add(int u, int v)
{
    node[++tot].next = head[u];
    node[tot].ver = v;
    head[u] = tot;
}

// DFS 遍历图，初始化 update 数组和 deep 数组
void dfs(int crd, int line)
{
    vit[crd] = true;
    deep[crd] = line;
    for(int l = head[crd]; l; l = node[l].next)
    {
        int son = node[l].ver;
        if(vit[son]) continue;
        update[son][0] = crd;
        for(int i = 1; i <= 20; i++)
        {
            update[son][i] = update[update[son][i - 1]][i - 1];
        }
        dfs(son, line + 1);
    }
}

// DFS 遍历图，求得所有边的压力
void solve(int crd, int from)
{
    for(int l = head[crd]; l; l = node[l].next)
    {
        int son = node[l].ver;
        if(son == from) continue;
        solve(son, crd);
        edge[crd] += edge[son];
    }
    ans = max(ans, (ll)edge[crd]);
}

// 查询 x 和 y 的 LCA
int lca(int x, int y)
{
    if(deep[x] < deep[y]) swap(x, y);
    for(int i = 20; i >= 0; i--)
    {
        if(deep[update[x][i]] >= deep[y]) x = update[x][i];
    }
    if(x == y) return x;
    for(int i = 20; i >= 0; i--)
    {
        if(update[x][i] != update[y][i])
        {
            x = update[x][i];
            y = update[y][i];
        }
    }
    return update[x][0];
}

int main()
{
    scanf("%d%d", &N, &K);
    for(int i = 1; i < N; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs(1, 1); // 遍历图，初始化数组
    for(int i = 1; i <= K; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        // 更新 edge 差分数组
        edge[x]++; edge[y]++;
        edge[lca(x, y)] -= 1;
        edge[update[lca(x, y)][0]] -= 1;
    }
    solve(1, 0);
    printf("%lld", ans);
    return 0;
}
