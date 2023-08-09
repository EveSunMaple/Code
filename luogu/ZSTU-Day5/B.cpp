#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

int main()
{
    // printf("%.5f", (double)3.14159265758);
    bool flag = false;
    int L, N, M;
    scanf("%d%d%d", &L, &N, &M);
    int w = N + L;
    int h = M + L;
    int d = gcd(w, h);
    if ((d - L) < 0 || L > N || L > M) flag = true;
    if (flag) printf("-1");
    else
    {
        int change = d / L;
        double ans = 1.0*((double)d / int((double)change+0.0000001)) - (double)L; 
        printf("%.5f", ans);
    }
    return 0;
}