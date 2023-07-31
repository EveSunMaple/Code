#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

string a;
long long ans, last = -1;

int main()
{
    freopen("agnus.in", "r", stdin);
    freopen("agnus.out", "w", stdout);
    cin >> a;
    int len = a.length();

    for (int i = 0; i < len; i++)
    {
        if (a[i] == 'a' && a[i + 1] == 'g' && a[i + 2] == 'n' && a[i + 3] == 'u' && a[i + 4] == 's')
        {
            ans += (i - last) * (len - i - 4);
            last = i;
        }
    }

    cout << ans;
    
    return 0;
}