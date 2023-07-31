#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

queue<int> wait;
const int N = 1e5 + 10;
int n, sit, ans = 1e9;
int num[N], cl[N];

// no time, no rank
int sol(int l, int r, bool temp)
{
    int sum = 0;
    for (int i = l; i <= r; i++)
    {
        for (int j = i + 1; j <= r; j++)
        {
            if ((cl[i] > cl[j]) && temp || (cl[i] < cl[j]) && !temp)
            {
                swap(cl[i], cl[j]);
                sum++;
            }
        }
    }
    return sum;
}

int main()
{
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    scanf("%d", &n);
    int max_num = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
        if (max_num < num[i])
            max_num = num[i];
    }
    for (int i = 1; i <= n; i++)
        if (num[i] == max_num)
            wait.push(i);
    while (!wait.empty())
    {
        sit = wait.front();
        wait.pop();
        int temp = 0;
        for (int i = 1; i <= n; i++)
            cl[i] = num[i];
        temp += sol(1, sit - 1, true);
        temp += sol(sit + 1, n, false);
        ans = min(temp, ans);
        // printf("%d->%d\n", sit, ans);
    }
    printf("%d", ans);
    return 0;
}