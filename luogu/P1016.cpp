//主要思想：优先队列BFS+DP
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAX 1005

using namespace std;

int city, road; 
int C, S, T;
int head[MAX]; 
double toll[MAX];
int edge[MAX * 10];
int son[MAX * 10]; 
int ver[MAX * 10];
int dist[MAX][105];
bool tag[MAX][105];
int tot = 0;

struct Node
{
    int crd;
    int oil;
    int cost;
    Node(int c, int o, int t)
    {
        crd = c;
        oil = o;
        cost = t;
    }
    bool operator < (const Node &a) const
    {
        return cost > a.cost;
    }
};

priority_queue<Node> q; 

void add(int u, int v, int w)
{
    edge[++tot] = w;
    ver[tot] = v;
    son[tot] = head[u];
    head[u] = tot;
}

int BFS(int start)
{
    while(!q.empty()) q.pop(); 
    memset(dist, 0x3f, sizeof(dist)); 
    memset(tag, 0, sizeof(tag)); 
    q.push(Node(start, 0, 0));
    dist[start][0] = 0; 
    while(!q.empty())
    {
        Node now = q.top(); 
        q.pop();
        if(now.crd == T) return now.cost; 
        if(tag[now.crd][now.oil]) continue;
        tag[now.crd][now.oil] = true; 
        if(now.oil < C && dist[now.crd][now.oil + 1] > now.cost + toll[now.crd])
        {
            dist[now.crd][now.oil + 1] = now.cost + toll[now.crd]; 
            q.push(Node(now.crd, now.oil + 1, now.cost + toll[now.crd])); 
        }
        for(int i = head[now.crd]; i; i = son[i])
        {
            if(now.oil < edge[i]) continue;
            if(dist[ver[i]][now.oil - edge[i]] > now.cost)
            {
                 dist[ver[i]][now.oil - edge[i]] = now.cost; 
                 q.push(Node(ver[i], now.oil - edge[i], now.cost)); 
            }
        }
    }
    return -1; 
}

int main()
{
    scanf("%d %d", &city, &road);
    for(int i = 1; i <= city; i++) 
        scanf("%d", &toll[i]);
    for(int i = 1; i <= road; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u++; v++;
        add(u, v, w);
        add(v, u, w);
    }

    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++)
    {
        scanf("%d %d %d", &C, &S, &T);
        S++; T++;
        int ans = BFS(S);
        if(ans == -1)
            printf("%s\n", "impossible");
        else 
            printf("%d\n",ans);
    }

    return 0;
}