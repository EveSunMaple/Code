#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#define N 1000005

using namespace std;

pair<int, int> stk[N];
int top = 0;
int ans[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        top = 0;
        scanf("%d", &n);
        string str;
        cin >> str;
        bool fr = false, ba = false;
        for (int i = 0; i < n; i++)
        {
            int temp = str[i];
            if (!top || stk[top].first == temp)
            {
                stk[++top] = make_pair(temp, i);
            }
            else
            {
                if (stk[top].first == '(')
                    { ans[stk[top--].second] = ans[i] = 1; fr = true; }
                else 
                    { ans[stk[top--].second] = ans[i] = 2; ba = true; }
            }
        }
        if (top) printf("-1");
        else 
        {
            if (fr && ba)
            {
                printf("2\n");
                for (int i = 0; i < n; i++) printf("%d ", ans[i]);
            }
            else 
            {
                printf("1\n");
                for (int i = 0; i < n; i++) printf("1 ");
            }
        }
        printf("\n");
    }
    return 0;
}