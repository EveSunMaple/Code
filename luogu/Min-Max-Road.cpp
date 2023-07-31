#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#define MAX 10000
int head[MAX]; //代表一个结点，也是子结点链的起点
int edge[MAX]; //储存边的值
int son[MAX]; //子结点链
int ver[MAX]; //代表有向边
int dist[MAX]; //最短路
bool tag[MAX]; //标记结点
int tot = 0; // 边的数量
using namespace std;
//pair的第一维是dist的相反数（把大根堆转换成小根堆）
//pair的第二维是结点下标
priority_queue<pair<int int>> q; //用二叉堆存结点
void Dijkstra()
{
    memset(dist, 0x3f, sizeof(dist)); //初始化dist
    memset(tag, 0, sizeof(tag)); //初始化tag
    dist[1] = 0; //设置起点
    q.push(make_pair(0, 1)); //把起点加入二叉堆
    //一直计算直到队列为空
    while(q.size())
    {
        int crd = q.top().second; //父结点下标
        q.pop(); //移出二叉堆
        if(tag[crd]) continue; //确保此结点没有被扩展过
        tag[crd] = true; //标记已经走过的点
        //遍历此结点的子结点
        for(int j = head[crd]; j; j = son[j])
        {
            if(dist[crd] + edge[j] < dist[ne])
            {
                 dist[ne] = dist[crd] + edge[j]; //更新子结点的dist
                 q.push(make_pair(-dist[ne], ne)); //把新的二元组插入堆
            }
        }
    }
    return;
}