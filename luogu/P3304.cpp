#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define ll long long
#define MAX 200005

using namespace std;

struct line
{
    int ver;
    int edge;
    line(int v, int e)
    {
        ver = v;
        edge = e;
    }
};

vector<line> g[MAX];
int N; // 结点树
ll deep[MAX]; // 结点深度
ll dis[MAX]; // 记录每个直径结点的最长链长度
ll dis1[MAX], dis2[MAX]; // 记录每个结点到直径两端点的距离
int path[MAX], path_len = 0; // 记录直径上的结点
int fa[MAX]; // 记录每个结点的父亲结点
bool vis[MAX]; // 标记直径上的结点
ll point; // 记录符合要求点数

// 遍历直径上的结点并将它们存入数组中
void get_path(int u, int v)
{
    while(u != v)
    {   
        vis[u] = true; // 标记直径上的结点
        path[++path_len] = u;
        //printf("point: %d--line: %d\n", u, path_len);
        u = fa[u];
        vis[u] = true; // 标记直径上的结点
    }
    path[++path_len] = v;
    vis[v] = true; // 标记直径上的结点
    //printf("point: %d--line: %d\n", v, path_len);
}
// 求出从u出发的最长链长度（这条链不能经过直径）
ll get_chain(int crd, int from)
{
    ll res = 0;
    for(line son : g[crd])
    {
        if(son.ver == from || vis[son.ver]) continue;
        res = max(res, son.edge + get_chain(son.ver, crd));
    }
    return res;
}
pair<int, ll> dfs(int crd, int from, int d, bool now)
{ 
    fa[crd] = from; // 记录当前结点的父亲结点
    pair<int, ll> node;
    node.first = crd;
    node.second = deep[crd];
    if(now) dis1[crd] = d; // 记录其他结点到结点1的距离
    else    dis2[crd] = d; // 记录结点到直径端点2的距离
    for(line son : g[crd])
    {
        if(son.ver == from) continue;
        deep[son.ver] = deep[crd] + son.edge;
        pair<int, ll> nxt = dfs(son.ver, crd, d + son.edge, now);
        if(nxt.second > node.second) 
        {
            node.first = nxt.first;
            node.second = nxt.second;
        }
    }
    return node;
}

int main()
{
    scanf("%d", &N);

    for(int i = 1; i < N; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(line(v, w));
        g[v].push_back(line(u, w));
    }

    pair<int, ll> node = dfs(1, 0, 0, 1);
    memset(deep, 0, sizeof(deep));
    memset(fa, 0, sizeof(fa));
    pair<int, ll> node_1 = dfs(node.first, 0, 0, 1);
    memset(deep, 0, sizeof(deep));
    memset(fa, 0, sizeof(fa));
    pair<int, ll> node_2 = dfs(node_1.first, 0, 0, 0);

    get_path(node_2.first, node_1.first);
    for(int i = 1; i <= path_len; i++) dis[path[i]] = get_chain(path[i], 0);

    point = path_len - 1;
    int i = 0;
    for(i = 2; i <= path_len - 1; i++)
    {
        int node = path[i];
        if(dis[node] == dis2[node]) 
        {
            int cut = path_len - i;
            point -= cut;
            //printf("1: ");
            //printf("cut_point: %d--cut_line: %d\n", node, cut);
            break;
        }
    }
    if(i >= path_len) i = path_len - 1;
    for(i; i > 1; i--)
    {
        int node = path[i];
        if(dis[node] == dis1[node])
        {
            int cut = i - 1;
            point -= cut;
            //printf("2: ");
            //printf("cut_point: %d--cut_line: %d\n", node, cut);
            break;
        }
    }
    
    printf("%lld\n", node_2.second);
    printf("%d", point);
    
    return 0;
}