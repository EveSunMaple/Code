#include <iostream>
#include <cstring>
#include <cstdio>
#include <time.h>
#define N 20000

using namespace std;

int main()
{
    rand();
	freopen("D.in", "w", stdout);
    for (int i = 1; i <= N; i++)
    {
        if (rand() & 1) printf("1");
        else printf("0");
    }
    printf("\n");
    printf("%d\n", N);
    for (int i = 1; i <= N; i++)
    {
        printf("%d ", rand() % 3 + 1);
        int l = rand() % N;
        int r = l + (rand() % N);
        if (r > N) r = N;
        printf("%d %d\n", l, r);
    }
    return 0;
}
