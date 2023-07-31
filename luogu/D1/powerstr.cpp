#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

string str;
bool have;

bool solve(int len, int lim)
{
    if (lim % len) return false;
    string p = str.substr(0, len);
    for (int i = len; i <= lim - len; i += len)
    {
        string q = str.substr(i, len);
        if (p == q) continue;
        else return false;
    }
    printf("%d\n", lim / len);
    return true;
}

int main()
{
    freopen("powerstr.in", "r", stdin);
    freopen("powerstr.out", "w", stdout);
    int n;
    scanf("%d", &n);
    while (n--)
    {
        have = false;
        str.clear();
        cin >> str;
        char p = str[0];
        int len = 0, r = -1;
        int lim = str.length();
        for (int i = 1; i < lim; i++)
        {
            len = r + 1;
            if (p == str[i]) r = i - 1;
            if (len && solve(len, lim)) 
                { have = true; break; }
            else continue;
        }
        if (!have) printf("1\n");
    }
    return 0;
}