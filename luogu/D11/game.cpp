#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    long long n;
    scanf("%lld", &n);
    printf("%lld", n * n);
    return 0;
}