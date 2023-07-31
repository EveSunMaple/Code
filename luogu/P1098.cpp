#include <iostream>
#include <cstring>

using namespace std;

string ch;

int change(int a, bool up)
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

bool check(int a, int b)
{
    a = change(a, 1);
    b = change(b, 1);
    if(a == '-' || b == '-' || ((a >= '0' && a <= '9') && (b >= 'A' && b <= 'Z')) || ((b >= '0' && b <= '9') && (a >= 'A' && a <= 'Z')))
        return 0;

    bool re = 0;

    if(a < b)
        re = 1;

    return re;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cin >> ch;

    cout << ch[0];

    for(int i = 1; i < ch.length(); i++)
    {
        if(ch[i] == '-')
        {
            int l = ch[i - 1], r = ch[i + 1];
            if(check(l, r))
            {
                int up = l, down = r;
                if(c == 2)
                {
                    up = r;
                    down = l;
                }
                for(int j = up; ;)
                {
                    if(c == 1) j++;
                    if(c == 2) j--;
                    if(j == down)
                        break;
                    for(int t = 1; t <= b; t++)
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
        else
            cout << ch[i];
    }
    return 0;
}