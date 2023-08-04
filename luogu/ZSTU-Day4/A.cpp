#include <iostream>
#include <cstring>
#include <cstdio>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)

using namespace std;

int go_0[4];
int go_1[4];
/*
1 1 0 0
1 0 1 0
1 0 0 1
0 1 1 0
0 1 0 1
0 0 1 1
*/

int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        bool up_0 = false;
        bool up_1 = true;
        for (int j = 1; j <= n; j++)
        {
            string now;
            cin >> now;
            for (int t = 0; t < n; t++)
            {
                if ((now[t] - '0') != up_0) go_0[i]++;
                if ((now[t] - '0') != up_1) go_1[i]++;
                up_0 = !up_0;
                up_1 = !up_1;
            }
        }
    }

    int ans = 1e9;
    ans = min(ans, go_0[0] + go_0[1] + go_1[2] + go_1[3]);// 0 0 1 1
    ans = min(ans, go_0[0] + go_1[1] + go_0[2] + go_1[3]);// 0 1 0 1
    ans = min(ans, go_0[0] + go_1[1] + go_1[2] + go_0[3]);// 0 1 1 0
    ans = min(ans, go_1[0] + go_0[1] + go_0[2] + go_1[3]);// 1 0 0 1
    ans = min(ans, go_1[0] + go_0[1] + go_1[2] + go_0[3]);// 1 0 1 0
    ans = min(ans, go_1[0] + go_1[1] + go_0[2] + go_0[3]);// 1 1 0 0
    // cout << ans;
    printf("%d", ans);
    return 0;
}