#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 1000005
#define k 1000000007

using namespace std;

int ans[N], nxt[N];
char s[N];

void solve()
{
    int cnt = 1;
    memset(s, 0, sizeof(s));
    memset(ans, 0, sizeof(ans));
    memset(nxt, 0, sizeof(nxt));
    cin >> s + 1;
    ans[1] = 1;
    int l = strlen(s + 1);
    for(int i = 2, j = 0; i <= l; i++)
    {
        while(j && s[i] != s[j + 1]) j = nxt[j];
        if(s[i] == s[j + 1]) j++;
        ans[i] = ans[j] + 1;
        nxt[i] = j;
    }
    for(int i = 2, j = 0; i <= l; i++)
    {
        while(j && s[i] != s[j + 1]) j = nxt[j];
        if(s[i] == s[j + 1]) j++;
        while(j + j > i) j = nxt[j];
        cnt = (cnt * (long long)(ans[j] + 1)) % k;
    }
    printf("%d\n", cnt);
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--) solve();
    return 0;
}