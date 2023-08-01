#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            string temp;
            cin >> temp;
            if (temp[0] == 'b' && temp[1] == 'n' && temp[2] == 'u'
             && temp[3] == '1' && temp[4] == '6' && temp[5] == '-')
            {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}