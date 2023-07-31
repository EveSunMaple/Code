#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define MAX 500005

using namespace std;

vector<int> g[MAX]; // 邻接表存储图
int update[MAX][21]; // update[i][j] 表示节点 i 的第 2^j 个祖先
int deep[MAX]; // deep[i] 表示节点 i 的深度
bool vit[MAX]; // 标记数组，用于 DFS 遍历
int N, M, S; // N 表示节点数，M 表示查询次数，S 表示根节点

// DFS 遍历图，初始化 update 数组和 deep 数组
void dfs(int crd, int line)
{
    vit[crd] = true;
    deep[crd] = line;
    for(int son : g[crd])
    {
        if(vit[son]) continue;
        update[son][0] = crd;
        for(int i = 1; i <= 20; i++)
        {
            update[son][i] = update[update[son][i - 1]][i - 1];
        }
        dfs(son, line + 1);
    }
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
    scanf("%d%d%d", &N, &M, &S);
    for(int i = 1; i < N; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(S, 1); // 遍历图，初始化数组
    for(int i = 1; i <= M; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", lca(x, y)); // 查询 x 和 y 的 LCA
    }

    return 0;
}
