#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long

using namespace std;

ll lim[1005];
ll L = 0, R = 0;
bool crd[1005];
char str[1005];

ll read()
{
    ll i = 1, j = 0;
    for (; ; i++)
    {
        if(str[i - 1] == '\0')
            break;
        if(str[i - 1] != '-')
        {
            lim[i - j] = (ll)str[i - 1];
        }
        else
        {
            crd[i - j - 1] = 1;
            j++;
        }
    }

    return i - j - 1;
}

ll change(ll a, bool up)
{
    if(up)
    {
        if(a <= 'z' && a >= 'a')
            a -= 32;
    }
    else
    {
        if(a <= 'Z' && a >= 'A')
            a += 32;
    }
    return a;
}

bool check(ll a, ll b)
{
    a = change(a, 1);
    b = change(b, 1);
    if(a == -1 || b == -1 || ((a >= '0' && a <= '9') && (b >= 'A' && b <= 'Z')) || ((b >= '0' && b <= '9') && (a >= 'A' && a <= 'Z')))
        return 0;

    bool re = 0;

    if(a < b)
        re = 1;

    return re;
}

int main()
{
    ll a, b, c;
    memset(lim, -1, sizeof(lim));
    scanf("%lld %lld %lld", &a, &b, &c);
    cin >> str; 
    ll tag = read();
    for(ll i = 1; i <= tag; i++)
    {
        cout << (char)lim[i];
        if(crd[i])
        {
            ll l = lim[i], r = lim[i + 1];
            if(check(l, r))
            {
                ll up = l, down = r;
                if(c == 2)
                {
                    up = r;
                    down = l;
                }
                for(ll j = up; ;)
                {
                    if(c == 1) j++;
                    if(c == 2) j--;
                    if(j == down)
                        break;
                    for(ll t = 1; t <= b; t++)
                    {
                        if(a == 1)
                            cout << (char)change(j, 0);
                        if(a == 2)
                            cout << (char)change(j, 1);
                        if(a == 3)
                            cout << '*';
                    }
                }
            }
            else
                cout << '-';
        }
    }

    return 0;
}