#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAX 10000
int head[MAX]; //代表一个节点，也是子节点链的起点
int edge[MAX]; //储存边的值
int son[MAX]; //子结点链
int ver[MAX]; //代表有向边
int dist[MAX]; //最短路
bool tag[MAX]; //标记结点
int tot = 0; // 边的数量
int T, N;

using namespace std;

void add(int u, int v, int w)
{
    edge[++tot] = w;
    ver[tot] = v;
    son[tot] = head[u];
    head[u] = tot;
}

void Dijkstra()
{
    memset(dist, 0x3f, sizeof(dist)); //初始化dist
    memset(tag, 0, sizeof(tag)); //初始化tag
    dist[1] = 0; //设置起点
    //计算除终点以外的结点出发的子结点的最短路
    for(int i = 1; i < N; i++)
    {
        int crd = 0; //父节点下标
        //遍历tot条边，找到指向结点dist最小的边
        for(int j = 0; j <= tot; j++)
        {
            if(!tag[j] && (crd == 0 || dist[crd] > dist[j]))
            {
                crd = j;
            }
        }
        tag[crd] = true; //标记已经走过的点
        //遍历此结点的子节点
        for(int j = head[crd]; j; j = son[j])
        {
            int ne = ver[j];
            dist[ne] = min(dist[ne], dist[crd] + edge[j]); //更新子结点的dist
        }
    }
    return;
}

int main()
{
    scanf("%d %d", &T, &N);

    for(int i = 1; i <= T; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    Dijkstra();
    printf("%d", dist[N]);

    return 0;
}