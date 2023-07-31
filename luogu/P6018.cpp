#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 500005

using namespace std;

struct line
{
    int ver;
    int nxt;
}edge[N * 2];
int head[N * 2];

int fa[N]; // node_father
int node[N]; // node
int trie[N * 25][2]; // trie
int son[N * 25]; // son_sum
int w[N * 25]; // have time
int tag[N]; // lazy_tag
int val[N]; // node_val
int tot = 1; // node_tot
int cnt; // edge_cnt
int n, m;

void add(int u, int v)
{
    edge[++cnt].ver = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt; 
}

void dfs(int u, int from)
{
    fa[u] = from;
    for(int i = head[u]; i; i = edge[i].nxt)
    {
        int v = edge[i].ver;
        if(v == from) continue;
        dfs(v, u);
    }
}

void push_up(int crd)
{
    w[crd] = son[crd] = 0;
    if(trie[crd][0])
    {
        w[crd] += w[trie[crd][0]];
        son[crd] ^= son[trie[crd][0]] << 1;
    }
    if(trie[crd][1])
    {
        w[crd] += w[trie[crd][1]];
        son[crd] ^= (son[trie[crd][1]] << 1) | (w[trie[crd][1]] & 1);
    }
}

int init_make()
{
    tot++;
    trie[tot][0] = trie[tot][1] = 0;
    w[tot] = son[tot] = 0;
    return tot;
}

void add_node(int& crd, int num, int deep)
{
    if(!crd) crd = init_make();
    if(deep > 20) { ++w[crd]; return; }
    add_node(trie[crd][num & 1], num >> 1, deep + 1);
    push_up(crd);
}

void del_node(int crd, int num, int deep)
{
    if(deep > 20) { --w[crd]; return; }
    del_node(trie[crd][num & 1], num >> 1, deep + 1);
    push_up(crd);
}

void adl(int crd)
{
    if(trie[crd][1]) adl(trie[crd][1]);
    swap(trie[crd][0], trie[crd][1]);
    push_up(crd);
}

int get_val(int crd)
{
    if (fa[crd]) { return tag[fa[crd]] + val[crd]; }
    return val[crd];
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &val[i]);
        if(fa[i]) add_node(node[fa[i]], val[i], 0);
    }
    while (m--)
    {
        int tree, crd;
        scanf("%d%d", &tree, &crd);
        if (tree == 1)
        {
            ++tag[crd];
            if (crd != 1)
            {
                if (fa[fa[crd]]) { del_node(node[fa[fa[crd]]], get_val(fa[crd]), 0); }
                ++val[fa[crd]];
                if (fa[fa[crd]]) { add_node(node[fa[fa[crd]]], get_val(fa[crd]), 0); }
            }
            adl(node[crd]);
        }
        else if (tree == 2)
        {
            int v;
            scanf("%d", &v);
            if (crd != 1) { del_node(node[fa[crd]], get_val(crd), 0); }
            val[crd] -= v;
            if (crd != 1) { add_node(node[fa[crd]], get_val(crd), 0); }
        }
        else 
        {
            printf("%d\n", son[node[crd]] ^ get_val(fa[crd]));
        }
    }
    return 0;
}