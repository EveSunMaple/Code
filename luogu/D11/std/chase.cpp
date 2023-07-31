#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define FOR(i, l, r) for(int i = l; i <= r; ++i)

using namespace std;

const int N = 500010;

struct edge{int to, next, v;} e[N * 2];
int n, x, y, z, cnt, tot, sp, st, mn, ans, stq;
int head[N], d[4][N];

int read()
{
    int x = 0; char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
    return x;
}

void ins(int x, int y, int z)
{
    e[++cnt].to = y; e[cnt].next = head[x]; e[cnt].v = z; head[x] = cnt;
}

void dfs(int f, int x, int fa, int noko)
{
    for(int i = head[x]; i; i = e[i].next)
        if (e[i].to != fa)
        {
            if (e[i].v > sp) continue;
            d[f][e[i].to] = d[f][x];
            if (e[i].v > noko)
            {
                ++d[f][e[i].to];
                dfs(f, e[i].to, x, sp - e[i].v);
            }
            else dfs(f, e[i].to, x, noko - e[i].v);
        }
}

void check(int x, int y)
{
    int mn = n + 1;
    FOR(i, 1, tot) mn = min(mn, d[i][x]);
    ans = max(ans, max(mn, d[0][x]));
    if (d[0][x] > mn) return;
    for(int i = head[x]; i; i = e[i].next)
        if (e[i].to != y && (d[0][x] < mn || d[0][x] == d[0][e[i].to]))
            check(e[i].to, x);
}

int main()
{
    freopen("chase.in", "r", stdin);
    freopen("chase.out", "w", stdout);

    n = read(); 
    FOR(i, 1, n - 1)
    {
        x = read(), y = read(), z = read();
        ins(x, y, z); ins(y, x, z);
    }
    tot = read();
    FOR(i, 0, tot)
    {
        FOR(j, 1, n) d[i][j] = n + 1;
        st = read(); sp = read();
        if (!i) stq = st;
        d[i][st] = 0;
        dfs(i, st, 0, 0);
    }
    check(stq, 0);
    if (ans == n + 1) ans = -1;
    printf("%d\n", ans);
    return 0;
}