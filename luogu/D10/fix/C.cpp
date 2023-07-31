#include <iostream>
#include <cstring>
#include <cstdio>
#define N 200005

using namespace std;

int a[N], b[N];
bool tag[4];

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

int check(int a, int b)
{
    bool A = a % 2;
    bool B = b % 2;
    if (A == 0 && B) return 1;
    if (B == 0 && A) return 2;
    return 3;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        tag[1] = false;
        tag[2] = false;
        tag[3] = false;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
        for (int i = 1; i <= n; i++)
        {
            int temp = 1;
            if (a[i] == 0 && b[i] == 0) continue;
            temp = gcd(a[i], b[i]);
            int x = check(a[i] / temp, b[i] / temp);
            tag[x] = true;
        }
        if (tag[1] + tag[2] + tag[3] <= 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}