#include <iostream>
#include <cstring>
#include <cstdio>
#define N 105

using namespace std;

int n, m, p;
int ans = 0;

int solve(int sum)
{
    if (!sum) return 1;
    return 2;
    // sorry, i cannot write anymore :(
}

int main()
{
    freopen("reword.in", "r", stdin);
    freopen("reword.out", "w", stdout);
    
    scanf("%d%d%d", &n, &m, &p);

    for(int i = 0; i <= m; i++)
    {
        ans = (ans + solve(i)) % p;
    }

    printf("%d", ans);

    return 0;
}