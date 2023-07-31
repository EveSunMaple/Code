#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    freopen("exam.in", "r", stdin);
    freopen("exam.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, ans = 0;
        scanf("%d", &n);
        string a;
        string b;
        cin >> a;
        cin >> b;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i]) ans += 2;
            else ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}