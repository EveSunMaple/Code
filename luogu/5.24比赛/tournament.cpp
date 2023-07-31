#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MaxN = 1005;

int n, k, a[MaxN], f[MaxN][MaxN], g[MaxN][MaxN], f_[MaxN][MaxN];

// cmin 函数用于更新 x 的最小值
inline bool cmin(int &x, int y) {
    return x > y ? x = y, true : false;
}

// transition 函数用于进行一次转移
void transition() {
    // 将 f_ 数组初始化为一个很大的值
    memset(f_, 0x3f, sizeof(f_));
    // 初始化 g 数组的对角线元素
    for (int i = 1; i <= n; i++)
        g[i][i] = i;
    // 枚举区间长度 h
    for (int h = 1; h <= n; h++) {
        // 枚举区间左端点 l
        for (int l = 1; l + h <= n; l++) {
            // 计算区间右端点 r
            int r = l + h;
            // 枚举决策点 x
            for (int x = g[l][r - 1]; x <= g[l + 1][r]; x++) {
                // 更新状态 f_[l][r] 和最优决策点 g[l][r]
                if (cmin(f_[l][r], f[l][x] + f[x + 1][r] + abs(a[x] - a[r])))
                    g[l][r] = x;
            }
        }
    }
    // 将 f_ 数组中的值更新到 f 数组中
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            cmin(f[i][j], f_[i][j]);
}

int main() {
    // 读入数据
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 将战力值从小到大排序
    sort(a + 1, a + n + 1);
    // 将 f 数组初始化为一个很大的值
    memset(f, 0x3f, sizeof(f));
    // 将对角线上的元素初始化为 0
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
    // 进行 k 次转移
    while (k--)
        transition();
    // 输出答案
    cout << f[1][n] << "\n";
    return 0;
}
