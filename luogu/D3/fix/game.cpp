#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0) // 加快输入输出速度
#define endl '\n'
#define x first
#define y second
using i64 = long long;

const int N = 1e5 + 5; // 定义常量N为10^5+5

namespace sgt
{                               // 定义一个命名空间sgt，用于封装线段树的操作
    int my[N << 2], op[N << 2]; // 定义两个数组my和op，分别表示每个区间内a序列和b序列的元素个数
    int score[N << 2];          // 定义一个数组score，表示每个区间内a序列中有多少个元素比b序列中对应位置的元素大

#define ls(p) (p << 1)          // 定义一个宏ls(p)，表示p节点的左儿子节点
#define rs(p) (p << 1 | 1)      // 定义一个宏rs(p)，表示p节点的右儿子节点

    void pushup(int p)
    {                                                 // 定义一个函数pushup(p)，用于更新p节点的信息，根据它的左右儿子节点的信息
        int win = min(my[rs(p)], op[ls(p)]);          // 计算p节点的得分，即左右儿子节点中可以匹配的最小值
        score[p] = score[ls(p)] + score[rs(p)] + win; // 更新p节点的得分，等于左右儿子节点的得分之和加上匹配值
        my[p] = my[ls(p)] + my[rs(p)] - win;          // 更新p节点的my值，等于左右儿子节点的my值之和减去匹配值
        op[p] = op[ls(p)] + op[rs(p)] - win;          // 更新p节点的op值，等于左右儿子节点的op值之和减去匹配值
    }

    void modify(int p, int l, int r, int pos, int x, int y)
    { // 定义一个函数modify(p, l, r, pos, x, y)，用于修改线段树中pos位置的my值和op值，分别增加x和y
        if (l == r)
        { // 如果当前区间只有一个元素，即l==r==pos
            my[p] += x;
            op[p] += y;
            return; // 直接修改p节点的my值和op值，并返回
        }
        int mid = l + r >> 1; // 否则，计算当前区间的中点
        if (pos <= mid)
            modify(ls(p), l, mid, pos, x, y); // 如果pos在左半区间内，就递归修改左儿子节点
        else
            modify(rs(p), mid + 1, r, pos, x, y); // 如果pos在右半区间内，就递归修改右儿子节点
        pushup(p);                                // 最后，更新p节点的信息
    }
}
int n, my[N], op[N];
multiset<int> s;
inline void solve()
{             // 定义一个函数solve()，用于解决问题
    cin >> n; // 输入n
    for (int i = 1; i <= n; i++)
    { // 输入b序列，并将每个元素插入到线段树中，增加op值
        cin >> op[i], sgt::modify(1, 1, N, op[i], 0, 1);
    }
    for (int i = 1; i <= n; i++)
    { // 输入a序列，并将每个元素插入到线段树中，增加my值，并将每个元素插入到multiset s中
        cin >> my[i], sgt::modify(1, 1, N, my[i], 1, 0), s.insert(my[i]);
    }

    int ans = sgt::score[1]; // 定义一个变量ans，表示当前的最大得分，等于根节点的得分
    for (int i = 1; i <= n; i++)
    {                                       // 从左到右遍历b序列
        sgt::modify(1, 1, N, op[i], 0, -1); // 将b[i]从线段树中删除，减少op值

        int l = op[i] + 1, r = *s.rbegin(); // 定义二分搜索的左右边界，l为b[i]+1，r为a序列中最大的元素
        while (l < r)
        {                                     // 当左边界小于右边界时，继续搜索
            int mid = l + r + 1 >> 1;         // 计算中点
            sgt::modify(1, 1, N, mid, -1, 0); // 将mid从线段树中删除，减少my值
            if (1 + sgt::score[1] == ans)
            {
                l = mid; // 如果删除mid后的得分加一等于ans，说明存在一个大于b[i]的元素，那么就在右半区间继续搜索
            }
            else
            {
                r = mid - 1; // 否则，就在左半区间继续搜索
            }
            sgt::modify(1, 1, N, mid, +1, 0); // 将mid重新插入到线段树中，增加my值
        }

        sgt::modify(1, 1, N, l, -1, 0); // 将l从线段树中删除，减少my值
        if (l <= r && 1 + sgt::score[1] == ans)
        {                       // 如果找到了一个大于b[i]的元素，并且删除它后的得分加一等于ans，说明这是一个最优解
            ans--;              // 更新ans，减一
            cout << l << ' ';   // 输出这个元素
            s.erase(s.find(l)); // 将这个元素从multiset s中删除
            continue;           // 跳过剩余的步骤，进入下一次循环
        }
        sgt::modify(1, 1, N, l, +1, 0); // 将l重新插入到线段树中，增加my值

        l = 1, r = op[i]; // 定义二分搜索的左右边界，l为1，r为b[i]
        while (l < r)
        {                                     // 当左边界小于右边界时，继续搜索
            int mid = l + r + 1 >> 1;         // 计算中点
            sgt::modify(1, 1, N, mid, -1, 0); // 将mid从线段树中删除，减少my值
            if (sgt::score[1] == ans)
            {
                l = mid; // 如果删除mid后的得分等于ans，说明存在一个小于等于b[i]的元素，那么就在右半区间继续搜索
            }
            else
            {
                r = mid - 1; // 否则，就在左半区间继续搜索
            }
            sgt::modify(1, 1, N, mid, +1, 0);
        }
        sgt::modify(1, 1, N, l, -1, 0);
        cout << l << ' ';
        s.erase(s.find(l));
    }
}

int main()
{
    fastio;
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}