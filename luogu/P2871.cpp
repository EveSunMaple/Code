#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int w[5000];
int d[5000];
int f[15000];

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        int W, D;
        scanf("%d %d", &W, &D);
        w[i] = W;
        d[i] = D;
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = M; j >= w[i]; j--)
        {
            f[j] = max(f[j], f[j - w[i]] + d[i]);
        }
    }

    printf("%d", f[M]);

    return 0;
}