#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool a[6];
bool color[11];

int main()
{
    freopen("mayan.in", "r", stdin);
    freopen("mayan.out", "w", stdout);
    bool check;
    int tot = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 5; i++)
    {
        while (true)
        {
            int temp;
            scanf("%d", &temp);
            if (!temp)
                break;
            a[i] = true;
            color[temp] = true;
            tot++;
        }
    }
    int aim = 0;
    for (int i = 1; i <= 10; i++)
    	aim += color[i];
    if (aim > 1) check = true; 
    if (tot % 3 || check)
    {
        printf("-1");
        return 0;
    }
    if (a[1] && a[2] && !a[3] && a[4] && !a[5])
    {
        if (n == 1)
        {
            printf("3 0 -1\n");
            return 0;
        }
        else if (n == 3)
        {
            printf("3 0 -1\n");
            printf("2 0 1\n");
            printf("3 0 -1\n");
            return 0;
        }
        else if (n == 5)
        {
            printf("3 0 -1\n");
            printf("2 0 1\n");
            printf("3 0 1\n");
            printf("4 0 -1\n");
            printf("3 0 -1\n");
            return 0;
        }
        else
        {
            printf("-1");
            return 0;
        }
    }
    if (a[1] && a[2] && !a[3] && !a[4] && a[5])
    {
        if (n == 2)
        {
            printf("4 0 -1\n");
            printf("3 0 -1\n");
            return 0;
        }
        else if (n == 4)
        {
            printf("4 0 -1\n");
            printf("3 0 1\n");
            printf("4 0 -1\n");
            printf("3 0 -1\n");
            return 0;
        }
        else
        {
            printf("-1");
            return 0;
        }
    }
    if (a[1] && a[2] && a[3] && !a[4] && !a[5])
    {
        if (n == 2)
        {
            printf("2 0 1\n");
            printf("3 0 -1\n");
            return 0;
        }
        else if (n == 4)
        {
            printf("2 0 1\n");
            printf("3 0 -1\n");
            printf("2 0 1\n");
            printf("3 0 -1\n");
            return 0;
        }
        else
        {
            printf("-1");
            return 0;
        }
    }
    if (!a[1] && a[2] && !a[3] && a[4] && a[5])
    {
        if (n == 1)
        {
            printf("1 0 1\n");
            return 0;
        }
        else if (n == 3)
        {
            printf("1 0 -1\n");
            printf("0 0 1\n");
            printf("1 0 1\n");
            return 0;
        }
        else if (n == 5)
        {
            printf("1 0 1\n");
            printf("2 0 -1\n");
            printf("1 0 -1\n");
            printf("0 0 1\n");
            printf("1 0 1\n");
            return 0;
        }
        else
        {
            printf("-1");
            return 0;
        }
    }
    if (a[1] && !a[2] && !a[3] && a[4] && a[5])
    {
        if (n == 2)
        {
            printf("0 0 1\n");
            printf("1 0 1\n");
            return 0;
        }
        else if (n == 4)
        {
            printf("0 0 1\n");
            printf("1 0 -1\n");
            printf("0 0 1\n");
            printf("1 0 1\n");
            return 0;
        }
        else
        {
            printf("-1\n");
            return 0;
        }
    }
    if (!a[1] && !a[2] && a[3] && a[4] && a[5])
    {
        if (n == 2)
        {
            printf("2 0 -1\n");
            printf("1 0 1\n");
            return 0;
        }
        else if (n == 4)
        {
            printf("2 0 -1\n");
            printf("1 0 1\n");
            printf("2 0 -1\n");
            printf("1 0 1\n");
            return 0;
        }
        else
        {
            printf("-1\n");
            return 0;
        }
    }
    if (!a[1] && a[2] && a[3] && !a[4] && a[5])
    {
        if (n == 1)
        {
            printf("4 0 -1\n");
            return 0;
        }
        else if (n == 2)
        {
            printf("2 0 1\n");
            printf("1 0 1\n");
            return 0;
        }
        else if (n == 3)
        {
            printf("4 0 -1\n");
            printf("3 0 1\n");
            printf("4 0 -1\n");
            return 0;
        }
        else if (n == 4)
        {
            printf("2 0 1\n");
            printf("1 0 1\n");
            printf("2 0 -1\n");
            printf("1 0 1\n");
            return 0;
        }
        else
        {
            printf("-1\n");
            return 0;
        }
    }
    if (a[1] && !a[2] && a[3] && a[4] && !a[5])
    {
        if (n == 1)
        {
            printf("0 0 1\n");
            return 0;
        }
        else if (n == 2)
        {
            printf("2 0 -1\n");
            printf("3 0 -1\n");
            return 0;
        }
        else if (n == 3)
        {
            printf("0 0 1\n");
            printf("1 0 -1\n");
            printf("0 0 1\n");
            return 0;
        }
        else if (n == 4)
        {
            printf("2 0 -1\n");
            printf("1 0 1\n");
            printf("2 0 -1\n");
            printf("3 0 -1\n");
            return 0;
        }
        else
        {
            printf("-1\n");
            return 0;
        }
    }
    if (a[1] && !a[2] && a[3] && !a[4] && a[5])
    {
        if (n == 2)
        {
            printf("0 0 1\n");
            printf("4 0 -1\n");
            return 0;
        }
        else if (n == 3)
        {
            printf("0 0 1\n");
            printf("2 0 1\n");
            printf("1 0 1\n");
            return 0;
        }
        else if (n == 5)
        {
            printf("2 0 -1\n");
            printf("1 0 1\n");
            printf("2 0 1\n");
            printf("0 0 1\n");
            printf("1 0 1\n");
            return 0;
        }
        else
        {
            printf("-1\n");
            return 0;
        }
    }
    return 0;
}
