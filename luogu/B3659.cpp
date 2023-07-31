#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int k, n, ans = 0;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x == k) ans++;
    }

    cout << ans;

    return 0;
}