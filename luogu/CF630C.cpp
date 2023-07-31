#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    long long cnt = 2;
    long long ans = 2;
    for(int i = 2; i <= n; i++)
    {
        cnt *= 2;
        ans += cnt;
    }
    printf("%lld", ans);

    return 0;
}