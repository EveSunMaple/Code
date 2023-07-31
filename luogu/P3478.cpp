#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#define MAX 1000005

using namespace std;

vector<int> to[MAX];
int cnt[MAX];
int ans[MAX];
bool up[MAX];
int N;

int init(int crd)
{
    int now = 1;

    up[crd] = true;
    for(int son : to[crd])
    {
        if(up[son] == true) continue;
        
        up[son] = true;
        now += init(son);
    }
    
    cnt[crd] = now;
    return now;
}

int find(int crd, int drop)
{
    int now = 0;

    up[crd] = true;
    for(int son : to[crd])
    {
        if(up[son] == true) continue;
        
        up[son] = true;
        now += find(son, drop + 1);
    }

    return now + drop;
}

void solve(int crd, int father)
{
    if(crd != 1) 
        ans[crd] = ans[father] - cnt[crd] * 2 + N;
    up[crd] = true;
    for(int son : to[crd])
    {
        if(up[son] == true) continue;
        
        up[son] = true;
        solve(son, crd);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 1; i < N; i++)
    {
        int u, v;
        scanf("%d %d",&u, &v);
        to[u].push_back(v);
        to[v].push_back(u);
    }

    init(1);
    memset(up, 0, sizeof(up));
    ans[1] = find(1, 0);
    memset(up, 0, sizeof(up));
    solve(1, 0);

    int out = 0;
    for(int i = 1, min = 0; i <= N; i++)
    {
        if(ans[i] > min)
        {
            min = ans[i];
            out = i;
        }
    }

    printf("%d", out);

    return 0;
}