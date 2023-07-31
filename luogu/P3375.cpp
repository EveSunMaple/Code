#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 1000005

using namespace std;

int nxt[N];
int f[N], n, m;

int main()
{
    char s1[N], s2[N];
    cin >> s1 + 1; // 1
    cin >> s2 + 1; // 1
    n = strlen(s1 + 1);
    m = strlen(s2 + 1);
    // start 1
    nxt[1] = 0;
    for(int i = 2, j = 0; i <= m; i++)
    {
        while(j && s2[i] != s2[j + 1]) j = nxt[j];
        if(s2[i] == s2[j + 1]) j++;
        nxt[i] = j;
    }
    for(int i = 1, j = 0; i <= n; i++)
    {
        while(j && s1[i] != s2[j + 1]) j = nxt[j];
        if(s1[i] == s2[j + 1]) j++;
        if(j == m)
        {
            printf("%d\n", i - j + 1);
            j = nxt[j];
        }
    }  
    for (int i = 1; i <= m; i++)
        printf("%d ", nxt[i]);
    return 0;
}