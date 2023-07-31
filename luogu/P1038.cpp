#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#define N 105

using namespace std;

struct node
{
    int ver;
    int edge;    
    node(int a, int b)
    {
        ver = a;
        edge = b;
    }
};

priority_queue<pair<int, int>> ans;
vector<vector<node>> g(N);
bool check;
int outdeg[N];
int indeg[N];
//int start[N];
int q[N], U[N];
int c[N];
int l = 0, r = 0;
int n, p;

int main()
{
    scanf("%d%d", &n, &p);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &c[i], &U[i]);
        if(c[i] == 0) c[i] -= U[i];
    }
    for(int i = 1; i <= p; i++)
    {
        int f, s, w;
        scanf("%d%d%d", &f, &s, &w);
        g[f].push_back(node(s, w));
        outdeg[f]++;
        indeg[s]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(indeg[i] == 0)
            q[++r] = i;
    }
    while(l < r)
    {
        for(int i = l; i <= r; i++)
        {
            int u = q[++l];
            if(outdeg[u] == 0)
            {
                ans.push(make_pair(-u, c[u]));
            }
            for(node v : g[u])
            {
                if(c[u] >= 0) c[v.ver] += v.edge * c[u];
                if(--indeg[v.ver] == 0) q[++r] = v.ver;
            }
        }
    }

    while(!ans.empty())
    {
        pair<int, int> t = ans.top();
        ans.pop();
        if(t.first != 0 && t.second > 0)
        {
            printf("%d %d\n", -t.first, t.second);
            check = true;
        }
    }

    if(!check) printf("NULL");

    return 0;
}