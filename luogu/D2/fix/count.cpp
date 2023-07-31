#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const int N = 1e5 + 10, Mod = 10086;
int n, val[N], head[N], cnt, ans;

struct Edge
{
    int to, next;
} e[N << 1];

void add(int u, int v)
{ // 添加一条从u到v的边
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

ll f[N]; // f[i]表示以i为根的子树中所有路径的权值积的和，再乘以i自己的val值，再对Mod取模；

void DP(int now, int fa)
{                         // 从now开始递归计算f
    ll tmp = 0, temp = 0; // tmp表示所有儿子的f值之和，temp表示所有儿子的f值之积之和
    for (int i = head[now]; i; i = e[i].next)
    { // 遍历now的所有儿子
        int v = e[i].to;
        if (v == fa)
            continue;        // 如果是父亲节点，跳过
        DP(v, now);          // 递归计算儿子节点的f和g
        tmp += f[v];         // 累加儿子节点的f值到tmp中
        temp += f[v] * f[v]; // 累加儿子节点的f值的平方到temp中
    }
    f[now] = ((tmp + 1) * val[now]) % Mod; // 计算now自己的f值，等于now自己的val值乘以所有儿子节点的f值之和再加上now自己的val值，再对Mod取模
    tmp = (tmp * tmp - temp) / 2 % Mod;    // 计算now自己的g值，等于所有儿子节点的f值之和的平方减去所有儿子节点的f值之积之和，再除以2，再对Mod取模
    tmp = (tmp * val[now]) % Mod;          // 完善路径，补全now节点
    ans = (ans + f[now] + tmp) % Mod;
}

int main()
{
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    scanf("%d", &n); // 输入n，表示有n个节点
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]); // 输入每个节点的val值
    for (int i = 1, u, v; i < n; i++)
    { // 输入n-1条边，构成一棵树
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u); // 双向添加边，方便遍历
    }
    DP(1, 0);            // 从根节点1开始递归计算f和g
    printf("%d\n", ans); // 输出最终答案ans，表示所有路径权值积之和对Mod取模后的结果
    return 0;
}
