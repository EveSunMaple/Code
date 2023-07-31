#include <iostream>
#include <climits>
#include <cstring>
#include <cstdio>
#define N 20005
#define M 2005

using namespace std;

int a[N];
int f[M][M], g[M][M];

int main()
{
    freopen("friend.in", "r", stdin);
    freopen("friend.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        memset(f, 0x3f, sizeof(f));
        memset(g, 0x3f, sizeof(g));
        for (int i = 2; i <= m; i++)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                // 第一个点是i 第二个点是j -> 实际写出来是[i][i - j]
                f[i % m][i - j] = a[i] + a[j];                           // 初始化f数组
                g[i % m][i - j] = min(g[i % m][i - j - 1], f[i % m][i - j]); // 比较在i ~ j这些人中取哪些更优
                                                                             // 因为实际上此时g[i][i - j - 1]就是在1 ~ j + 1中最优的选择
            }
        }
        for (int i = m + 1; i <= n; i++)
        {
            for (int j = i - 1; j >= i - m + 1; j--)
            {
                // j循环的过程就是遍历DP的过程
                f[i % m][i - j] = a[i] + g[j % m][j - i + m];                // j - i + m是最后一个区间的长度，也就是从当前最优的选择转移过来
                g[i % m][i - j] = min(g[i % m][i - j - 1], f[i % m][i - j]); // 此时g数组含义仍然是在1 ~ j中最优的选择
                                                                             // 我们比较先前的g数组与现在转移的f数组，选择最优的保留进入下一次转移
            }
        }

        int ans = INT_MAX;
        for (int i = n - m - 1; i <= n; i++) // 枚举最后一个区间
            for (int j = i - 1; j >= n - m + 1; j--)
                ans = min(ans, f[i % m][i - j]); // 取出最后最优秀的解
        printf("%d\n", ans);
    }
    return 0;
}