#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define ll long long
#define N 10000005

using namespace std;

const int mod = 1e9 + 7;
char line[N];
int stk[N];
int mch[N];
ll ans[N];
int up[N];
int l[N];
int r[N];
int top;
int len;

int main()
{
    freopen("bracket.in", "r", stdin);
    freopen("bracket.out", "w", stdout);
    fastio;
    scanf("%s", line + 1);
    len = strlen(line + 1);
    for (int i = 1; i <= len; i++)
    {
        if (line[i] == '(')
        {                     // 如果找到一个左括号
            up[i] = stk[top]; // 记录i位置左括号的前一个左括号位置
            stk[++top] = i;
        }
        else if (top)
        { // 给两个括号配对
            mch[i] = stk[top];
            mch[stk[top]] = i;
            top--;
        }
    }
    for (int i = 1; i <= len; i++)
    { // 从左边开始找右括号
      // 如果找到了非第一的右括号
      // 它左边的标记数为
      // 它配对的左括号的左边（右括号）的标记数加一
        if (!mch[i] || line[i] == '(')
            continue;
        l[i] = l[mch[i] - 1] + 1;
    }
    for (int i = len; i >= 1; i--)
    { // 从右边开始找左括号
      // 如果找到了非最后的左括号
      // 它右边的标记数为
      // 它配对的右括号的右边（左括号）的标记数加一
        if (!mch[i] || line[i] == ')')
            continue;
        r[i] = r[mch[i] + 1] + 1;
    }
    for (int i = 1; i <= len; i++)
    {
        if (!mch[i] || line[i] == ')')
            continue;
        // 这个区间被覆盖的次数为左右括号的标记之积
        ans[i] = 1LL * r[i] * l[mch[i]] % mod;
        if (up[i]) // 如果这个左括号有父亲，则还要加上父亲的次数
            ans[i] = (ans[i] + ans[up[i]]) % mod;
        ans[mch[i]] = ans[i];
    }

    ll temp = 0;
    for (int i = 1; i <= len; i++)
        temp += 1LL * ans[i] * i % mod;
    printf("%lld", temp);
    return 0;
}
