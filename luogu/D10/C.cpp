#include <iostream>
#include <cstring>
#include <cstdio>
#define pir pair<int, int>
#define N 100005

using namespace std;

int a[N], b[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        int aim = 0;
        scanf("%d", &n);
        bool check = true;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
            int c = abs(a[i] - b[i]);
            // if a > b -> a * i = b * (i - 1)
            
        }
        if (check) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}