#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k, x;
        scanf("%d%d%d", &n, &k, &x);
        if (k == 1)
        {
            printf("NO\n");
            continue;
        }
        if (x != 1)
        {
            printf("YES\n");
            printf("%d\n", n);
            for (int i = 1; i <= n; i++) 
                printf("1 ");
            printf("\n");
        }
        else
        {
            if (n % 2 == 1)
            {
                if (k >= 3)
                {
                    printf("YES\n");
                    printf("%d\n", n / 2);
                    for (int i = 1; i <= n / 2 - 1; i++) 
                        printf("2 "); 
                    printf("3 ");
                    printf("\n");
                }
                else 
                {
                    printf("NO\n");
                    continue;
                }
            }
            else
            {
                printf("YES\n");
                printf("%d\n", n / 2);
                for (int i = 1; i <= n / 2; i++) 
                    printf("2 ");
                printf("\n");
            }
        }
    }
    return 0;
}