#include <iostream>
#include <cstring>
#include <cstdio>
#define pir pair<int, int>
#define N 200005

using namespace std;

int c[N];
bool tag[N];
int range[N][2];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        memset(c, 0, sizeof(c));
        memset(tag, 0, sizeof(tag));
        memset(range, 0, sizeof(range));
        for (int i = 1; i <= n; i++)
        {
            int col;
            scanf("%d", &col);
            int temp = i - c[col] - 1;
            if (temp == range[col][1]) tag[col] = true;
            else if (temp > range[col][1])
            {
                tag[col] = false;
                range[col][0] = range[col][1];
                range[col][1] = temp;
            }
            else if (temp > range[col][0]) range[col][0] = temp;
            // if (temp == range[col][1].first) range[col][1].second++; 
            // else if (temp > range[col][1].first)
            // {
            //     range[col][0] = range[col][1];
            //     range[col][1] = make_pair(temp, 1);
            // }
            // else if (temp > range[col][0].first)
            //     range[col][0] = make_pair(temp, 1);
            // //printf("Col:  %d , MAX: %d , Time: %d\n", col, range[col][1].first,  range[col][1].second);
            // //printf("Col:  %d , Oth: %d , Time: %d\n", col, range[col][0].first,  range[col][0].second);
            c[col] = i;
        }
        int ans = 1e9;
        for (int i = 1; i <= k; i++)
        {
            int temp = n - c[i];
            if (c[i] == 0) continue;
            if (temp == range[i][1]) tag[i] = true;
            else if (temp > range[i][1])
            {
                tag[i] = false;
                range[i][0] = range[i][1];
                range[i][1] = temp;
            }
            else if (temp > range[i][0]) range[i][0] = temp;
            if (!tag[i]) ans = min(ans, max(range[i][1] / 2, range[i][0]));
            else ans = min(ans, range[i][1]);
            // int temp = n - c[i];
            // if (temp == range[i][1].first) range[i][1].second++; 
            // else if (temp > range[i][1].first)
            // {
            //     range[i][0] = range[i][1];
            //     range[i][1] = make_pair(temp, 1);
            // }
            // else if (temp > range[i][0].first)
            //     range[i][0] = make_pair(temp, 1);
            // //printf("Col:  %d , MAX: %d , Time: %d\n", i, range[i][1].first,  range[i][1].second);
            // //printf("Col:  %d , Oth: %d , Time: %d\n", i, range[i][0].first,  range[i][0].second);
            // 
            // if (c[i] == 0) continue;
            // if (range[i][1].second == 1/* && range[i][1].first / 2 >= range[i][0].second*/)
            // {
            //     ans = min(ans, max(range[i][1].first / 2, range[i][0].first));
            // }
            // else ans = min(ans, range[i][1].first);
        }
        printf("%d\n", ans);
    }
    return 0;
}