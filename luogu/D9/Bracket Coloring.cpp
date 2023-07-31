#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#define N 100005

using namespace std;

int stk[N], top, tag = 0;
int ans[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        tag = 0;
        scanf("%d", &n);
        string str;
        cin >> str;
        str = ' ' + str;
        for (int i = 1; i <= n; i++)
        {
            if (!top)
            {
                tag++;
                stk[++top] = str[i];
            }
            else
            {
                if (str[i] == stk[top])
                {
                    stk[++top] = str[i];
                }
                else top--;
            }
            ans[i] = tag;
        }
        if (top) printf("-1\n");
        else 
            for (int i = 1; i <= n; i++)
                printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}