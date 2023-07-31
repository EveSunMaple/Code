#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define N 205

using namespace std;

int type[N];
//int stk[N], top;
int MAX, MIN, ans;
int n, k;

bool cmp(int a, int b)
{
    return a > b;
}

bool check(int temp)
{
    if (temp == 0
     || temp == MIN
     || temp == MAX
     || temp == MIN - 1) return true;
    return false;
}

void dfs(int crd, int step, int sum)
{
    if (check(sum)) ans = max(ans, step);
    for (int i = crd + 1; i <= n; i++)
    {
        dfs(i, step + 1, sum ^ type[i]);
    }
}

int main()
{
    //fastio;
    // 真的毫无头绪，我是fw呜呜呜
    freopen("music.in", "r", stdin);
    freopen("music.out", "w", stdout);
    scanf("%d%d", &n, &k); // cannot use scanf and printf
    //cin >> n >> k;
    MIN = 1 << k;
    MAX = (MIN - 1) + MIN;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        type[i] = 1;
        string str;
        cin >> str;
        for (int j = 0; j < k; j++)
        {
            type[i] <<= 1;
            if (str[j] == 'A') type[i]++;
        }
        // sum ^= type[i];
    }
    dfs(0, 0, 0);
    printf("%d", ans);
    //cout << ans;
    // sort(type + 1, type + 1 + n, cmp);
    // for (int i = 2; i <= m; i++)
    // {
    //     
    // }
    // sort(type + 1, type + 1 + n, cmp);
    // for (int i = 1; i <= n; i++)
    // {
    //     top = i;
    //     for (int j = top; j >= 0; j--)
    //     {
    //         cout << "stk[j] = " << stk[j] << "|" << check(stk[j]) << endl;
    //         cout << "type[i] ^ stk[j] = " << (type[i] ^ stk[j]) << "|" << check(type[i] ^ stk[j]) << endl;
    //         if (check(stk[j]) || check(type[i] ^ stk[j]))
    //         {
    //             stk[top] = type[i] ^ stk[j];
    //             //top = max(j + 1, top);
    //         }
    //     }
    // }
    // int ans = 0;
    // for (int j = top; j >= 0; j--)
    // {
    //     if (check(stk[j])) 
    //         { cout << j; break; }
    // }
    return 0;
}