#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 50;
int top, ans, n;
int stk[N];
int fi[N];

inline int calc()
{
    int cnt = 0, num = 0;
    for (int i = 1; i <= top; i++)
    {
        num += stk[i];
        //printf ("(%d) ", stk[i]);
    }
    //printf ("->[%d] ", num);
    while (num) 
        { if (num % 10 == 4) cnt++; num /= 10; }
    //printf("-> | %d |\n", cnt);
    return cnt;
}

void dfs(int crd)
{
    stk[++top] = fi[crd];
    ans += calc();
    for (int i = crd + 1; i <= n; i++)
    {
        dfs(i);
    }
    top--;
}

int main()
{
    freopen("four.in", "r", stdin);
    freopen("four.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        // int temp;
        // scanf("%d", &temp);
        // while (temp)
        // {
        //     if (temp % 10 == 4) fi[i]++;
        //     temp /= 10;
        // }
        scanf("%d", &fi[i]);
    }
    for (int i = 1; i <= n; i++) dfs(i);
    printf("%d", ans);
    return 0;
}