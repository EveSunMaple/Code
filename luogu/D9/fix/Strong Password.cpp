#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

bool vis[11];
string l, r;
string str;
int m;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int j = 0;
        cin >> str;
        scanf("%d", &m);
        cin >> l;
        cin >> r;
        bool flag = true;
        for (int i = 0; i < m; i++)
        {
            memset(vis, false, sizeof(vis));
            int MIN = l[i] - '0';
            int MAX = r[i] - '0';
            int cnt = 0;
            while (j < str.size() && cnt < MAX - MIN + 1)
            {
                int temp = str[j] - '0';
                if (!vis[temp] && temp <= MAX && temp >= MIN)
                {
                    cnt++;
                    vis[temp] = true;
                }
                j++;
            }
            if (j == str.size() && cnt != MAX - MIN + 1)
            {
                flag = false;
                printf("YES\n");
                break;
            }
        }
        if (flag)
            printf("NO\n");
    }
    return 0;
}