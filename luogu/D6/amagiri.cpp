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
int nxt[N];

int main()
{
    fastio;
    freopen("amagiri.in", "r", stdin);
    freopen("amagiri.out", "w", stdout);
    int win = true;
    cin >> str + 1;
    int len = strlen(str + 1);
    for (int i = 1; i < len && i > 0;)
    {
        if (!nxt[i]) nxt[i] = i + 1;
        char l = str[i];
        char r = str[nxt[i]];
        if (l == r)
        {
            win = !win;
            nxt[i - 1] = nxt[i] + 1;
            if (i > 1) i--;
            else i = nxt[i - 1];
        }
        else i = nxt[i];
    }
    if (win) printf("PT-109");
    else printf("amagiri");
    return 0;
}