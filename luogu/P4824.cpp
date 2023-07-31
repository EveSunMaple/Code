#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 1000005

using namespace std;

char s1[N], s2[N];
int nxt[N], f[N];
int stk[N], top;

int main()
{
    cin >> s1 + 1;
    cin >> s2 + 1;
    int l1 = strlen(s1 + 1);
    int l2 = strlen(s2 + 1);
    for(int i = 2, j = 0; i <= l2; i++)
    {
        while(j && s2[i] != s2[j + 1]) j = nxt[j];
        if(s2[i] == s2[j + 1]) j++;
        nxt[i] = j;
    }
    for(int i = 1, j = 0; i <= l1; i++)
    {
        while(j && s1[i] != s2[j + 1]) j = nxt[j];
        if(s1[i] == s2[j + 1]) j++;
        f[i] = j;
        stk[++top] = i;
        if(j == l2)
        {
            top -= l2;
            j = f[stk[top]];
        }
    }
    for(int i = 1; i <= top; i++)
    {
        printf("%c", s1[stk[i]]);
    }
    return 0;
}