#include <iostream>
#include <cstring>
#include <cstdio>
#define N 100005

using namespace std;

int A[N], B[N];
int n, ans = 0;

bool check(int aim)
{
    for (int i = 1; i <= n; i++)
    {
        if (aim == A[i] || aim == B[i]) return true;
    }
    return false;
}

int main()
{
    freopen("C.in", "r", stdin);
    freopen("C copy.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (check(A[i] ^ B[j])) ans++;
            }
        }
        if (ans & 1) printf("1!\n");
        else printf("0!\n");
    }
    return 0;
}