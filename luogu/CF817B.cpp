#include <iostream>
#include <algorithm>

using namespace std;

long long IQ[100003];

int main()
{
    long long n = 0;
    scanf("%d", &n);

    for(long long i = 1; i <= n; i++)
    {
        scanf("%d", &IQ[i]);
    }

    sort(IQ + 1, IQ + n + 1);

    long long ans = 1;

    long long cnt = 0;
    for(long long i = 1; i <= n; i++)
    {
        if(IQ[i] == IQ[3])
            cnt++;
    }

    if(IQ[1] == IQ[3])
        ans = cnt * (cnt - 1) * (cnt - 2) / 6;
    else if(IQ[2] != IQ[3])
        ans = cnt;
    else
        ans = cnt * (cnt - 1) / 2;

    printf("%lld", ans);

    return 0;
}