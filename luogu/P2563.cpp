#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#define MAX 10005

using namespace std;

long long f[MAX];
int prime[MAX];
bool no_prime[MAX];

int init()
{
    int crd = 1;

    for(int i = 2; i <= MAX; i++)
    {
        if(no_prime[i]) continue;
        prime[crd++] = i;
        for(int j = i; j <= MAX / i; j++)
            no_prime[i * j] = true;
    }

    return crd;
}

int main()
{
    int len = init();
    int num;
    for(; cin >> num;)
    {
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for(int i = 1; i < len; i++)
        {
            for(int j = prime[i]; j <= MAX; j++) f[j] += f[j - prime[i]];
        }
        printf("%lld\n", f[num]);
    }

    return 0;
}