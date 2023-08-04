#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        bool find = false;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int temp;
            scanf("%d", &temp);
            if (temp == 0) find = true;
        }
        for (int i = 1; i <= n; i++)
        {
            int temp;
            scanf("%d", &temp);
            if (temp == 0) find = true;
        }
        if (find && (n & 1)) printf("1!\n");
        else printf("0!\n");
    }
    return 0;
}