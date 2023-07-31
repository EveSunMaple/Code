#include <iostream>

using namespace std;

int l[102];

int solve(int a)
{
    return a * (a - 1) / 2;
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    long long ans = 0;

    for(int i = 1; i <= n; i++)
    {
        char t[102];
        int cnt = 0;
        scanf("%s", &t);
        for(int j = 0; j < n; j++)
        {
            if(t[j] == 'C')
            {
                cnt++;
                l[j]++;
            }
        }
        ans += solve(cnt);
    }
    
    for(int i = 0; i <= n; i++)
    {
        ans += solve(l[i]);
    }

    printf("%lld", ans);

    return 0;
}