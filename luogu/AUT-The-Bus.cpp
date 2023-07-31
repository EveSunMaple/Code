#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 10000
int edge[MAX]; //储存点的值
int dist[MAX]; //最短路
bool tag[MAX]; //标记结点
int tot = 0; // 边的数量
using namespace std;
vector<int> g[MAX]; // 邻接表存储图
void BellmonFord()
{
    memset(dist, 0, sizeof(dist)); //初始化dist
    memset(tag, 0, sizeof(tag)); //初始化tag
    dist[1] = 0; //设置起点 queue<int> q; //定义队列，存储可能改变的结点
    queue<int> q; //定义队列，存储可能改变的结点
    q.push(1); //把起点添加进队列
    tag[1] = true; //打上标记
    //一直计算直到队列为空
    while(q.size())
    {
        int crd = q.front(); //从队列中取一个结点
        q.pop(); //移出队列
        tag[crd] = false; //去掉标记
        //遍历连接crd的子节点
        for(int son : g[crd])
        {
            printf("son--%d--crd--%d---\n", son, crd);
            if(dist[crd] + edge[son] >= dist[son])
            {
                dist[son] = dist[crd] + edge[son]; //更新子结点的dist
                q.push(son); //把新的插入堆
                tag[son] = true; //打上标记
            }
        }
    }
    return;
}

int main()
{
    int n, m, k; //n列，m行
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j + 1 <= n) g[(i - 1) * n + j].push_back((i - 1) * n + j + 1);
            if(i + 1 <= m) g[(i - 1) * n + j].push_back(i * n + j);
            //if(i == 1 && j == 1) printf("---%d---\n", i * n + j);
        }
    }
    for(int i = 1; i <= k; i++)
    {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        edge[(y - 1) * n + x] = v;
    }
    /*for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%5d", edge[(i - 1) * n + j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------\n");
    */BellmonFord();
    /*for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%5d", dist[(i - 1) * n + j]);
        }
        printf("\n");
    }*/
    printf("%d", dist[n * m]);
    return 0;
}