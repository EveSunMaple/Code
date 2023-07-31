#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1000010;

char s[N];
int len, top, st[N];

int main()
{
    freopen("amagiri.in", "r", stdin);
    freopen("amagiri.out", "w", stdout);

    scanf("%s", s);
    len = strlen(s);
    for(int i = 0; i < len; ++i)
        if (s[i] == st[top]) --top; else st[++top] = s[i];
    if ((len - top) & 2) puts("amagiri"); else puts("PT-109");

    return 0;
}
