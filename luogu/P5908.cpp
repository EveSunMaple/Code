#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define MAX 100005

using namespace std;

vector<int> g[MAX];
bool vit[MAX];
int n, d;
int ans;

void dfs(int crd, int line)
{
    if(line > d) return;
    vit[crd] = true; ans++;
    for(int son : g[crd])
    {
        if(vit[son]) continue;
        dfs(son, line + 1);
    }
}

int main()
{
    scanf("%d%d", &n, &d);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d", ans - 1);

    return 0;
}