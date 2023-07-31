#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

string str;

void solve(int len)
{
}

int main()
{
    str.clear();
    cin >> str;
    int len = 2;
    int lim = str.length();
    for(int i = len; i <= lim - len; i += len)
    {
        string p = str.substr(i, len);
        cout << p << endl;
    }
    return 0;
}