#include <iostream>
#include <cstring>
#include <cstdio>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define N 1000005

using namespace std;

char str[N];
char stk[N];
int top;

int main()
{
    fastio;
    freopen("amagiri.in", "r", stdin);
    freopen("amagiri.out", "w", stdout);
    int win = true;
    cin >> str + 1;
    int len = strlen(str + 1);
    for (int i = 1; i <= len; i++)
    {
        if (str[i] == stk[top])
        {
            top--;
            win = !win;
        }
        else stk[++top] = str[i];
    }
    if (win) printf("PT-109");
    else printf("amagiri");
    return 0;
}