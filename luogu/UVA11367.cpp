//主要思想：优先队列BFS+DP
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAX 1005

using namespace std;

int city, road; //当前的城市数和道路数
int C, S, T; //油量C、起点S和终点T
int head[MAX]; //代表一个城市
int toll[MAX]; //每个城市的油价
int edge[MAX * 10]; //储存边的值
int son[MAX * 10]; //子结点链
int ver[MAX * 10]; //代表有向边
/*
注意我们这里用二维数组存结点
因为我们动态规划时要找出最优
所以油量不同的同城市情况也是一个结点
*/
//dist的第一维是当前城市
//dist的第二维是当前油量
int dist[MAX][105]; //存储最小花费
bool tag[MAX][105]; //标记结点
int tot = 0;

struct Node
{
    int crd; //结点下标
    int oil; //到达此结点耗费的油量
    int cost; //到达此结点的总花费
    //结构体函数，方便我们添加结点
    Node(int c, int o, int t)
    {
        //给结点赋值
        crd = c;
        oil = o;
        cost = t;
    }
    //在优先队列中按所花的钱更少的排序，变成小根堆
    bool operator < (const Node &a) const
    {
        //你不用管a是什么，只把符号倒一下就可以了
        return cost > a.cost;
    }
};

priority_queue<Node> q; //存结点Node的小根堆

//没什么好说的邻接表函数
void add(int u, int v, int w)
{
    edge[++tot] = w;
    ver[tot] = v;
    son[tot] = head[u];
    head[u] = tot;
}

int BFS(int start)
{
    while(!q.empty()) q.pop(); //初始化小根堆q
    memset(dist, 0x3f, sizeof(dist)); //初始化dist
    memset(tag, 0, sizeof(tag)); //初始化tag
    q.push(Node(start, 0, 0)); //把起点推入小根堆
    dist[start][0] = 0; //赋值起点
    /*
    因为每次取出结点时，此结点是当前所有状态的最优解
    所以只要我们取出T结点，就可以马上退出广度优先搜索
    */
    //一直计算直到取出T结点
    while(!q.empty())
    {
        Node now = q.top(); //取出最小的结点
        q.pop(); //移出二叉堆
        if(now.crd == T) return now.cost; //如果取出T结点，直接退出
        if(tag[now.crd][now.oil]) continue; //确保此结点没有被扩展过
        tag[now.crd][now.oil] = true; //标记已经扩展过的结点
        //如果油箱没有满且子结点的dist不是最优，则添加一个新的可能改变值的结点
        if(now.oil < C && dist[now.crd][now.oil + 1] > now.cost + toll[now.crd])
        {
            dist[now.crd][now.oil + 1] = now.cost + toll[now.crd]; //更改此时的结点值
            q.push(Node(now.crd, now.oil + 1, now.cost + toll[now.crd])); //把这个更改过，可能影响下一个子结点的结点入队
        }
        //遍历此结点的子结点
        for(int i = head[now.crd]; i; i = son[i])
        {
            if(now.oil < edge[i]) continue; //如果油量不够开，直接continue
            //如果当前城市的子城市在油量为now.oil - edge[i]的情况不是最优解，则更改
            if(dist[ver[i]][now.oil - edge[i]] > now.cost)
            {
                 dist[ver[i]][now.oil - edge[i]] = now.cost; //更新子城市此时油量的dist
                 q.push(Node(ver[i], now.oil - edge[i], now.cost)); //把这个更改过，可能影响下一个子城市的结点入队
            }
        }
    }
    return -1; //如果队列空了都没能取出T结点，说明没有路可走到T结点
}

int main()
{
    scanf("%d %d", &city, &road);
    for(int i = 1; i <= city; i++) 
        scanf("%d", &toll[i]); //输入当前油价
    for(int i = 1; i <= road; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u++; v++; //因为我们下标从1开始，这里要把结点下标都加一
        //添加无向边，看成两条重复的有向边
        add(u, v, w);
        add(v, u, w);
    }

    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++)
    {
        scanf("%d %d %d", &C, &S, &T);
        S++; T++; //因为我们下标从1开始，这里要把起点和终点都加一
        int ans = BFS(S); //开始广度优先搜索
        if(ans == -1) //无解
            printf("%s\n", "impossible");
        else 
            printf("%d\n",ans);
    }

    return 0;
}