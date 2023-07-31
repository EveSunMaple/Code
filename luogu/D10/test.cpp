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
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
        }
        while (1)
        {
            for (int i = 1; i <= n; i++)
            {
                int temp = b[i];
                b[i] = abs(a[i] - temp);
                a[i] = temp;
                printf ("%d ", b[i]);
            }
            printf("\n");
        }
    }
    return 0;
}