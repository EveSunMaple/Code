#include <iostream>
#include <cstring>
#include <cstdio>
#define N 500005

using namespace std;

struct chase
{
    int ver;
    int nxt;
    int val;
}edge[N * 2];

int head[N], day[4][N];
int temp, n, t, tot;
int ans, st, sp;

void add(int u, int v, int w)
{
    edge[++tot].val = w;
    edge[tot].ver = v;
    edge[tot].nxt = head[u];
    head[u] = tot;
}

void check(int aim, int fa)
{
    int MAX = n + 1;
    for (int i = 1; i <= t; i++) MAX = min(MAX, day[i][aim]); // 获取每一个点到aim的天数
    ans = max(ans, max(MAX, day[0][aim])); // 比较最大天数
    if (day[0][aim] > MAX) return;
    for(int i = head[aim]; i; i = edge[i].nxt)
    {
        int v = edge[i].ver;
        if (v != fa && (day[0][aim] < MAX || day[0][aim] == day[0][v]))
            check(v, aim);
    }
}

void dfs(int tag, int u, int fa, int other)
{
    for(int i = head[u]; i; i = edge[i].nxt)
    {
        int v = edge[i].ver;
        if (v == fa) continue;
        if (edge[i].val > sp) continue; // 如果时间速度不够，退出
        day[tag][v] = day[tag][u];
        if (edge[i].val > other)
        {
            ++day[tag][v];
            dfs(tag, v, u, sp - edge[i].val);
        }
        else dfs(tag, v, u, other - edge[i].val);
    }
}

int main()
{
    freopen("chase.in", "r", stdin);
    freopen("chase.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w); add(v, u, w);
    }
    scanf("%d", &t);
    for (int i = 0; i <= t; i++)
    {
        scanf("%d%d", &st, &sp);
        for (int j = 1; j <= n; j++) day[i][j] = n + 1;
        if (!i) temp = st;
        day[i][st] = 0; // 第i个人到其他点的时间
        dfs(i, st, 0, 0);
    }
    check(temp, 0); // 最后一个作为入口
    if (ans == n + 1) ans = -1; // 如果是初始上限，说明抓不到
    printf("%d\n", ans);
    return 0;
}