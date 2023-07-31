#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

const int N = 3 * 1e5 + 1;
int ans[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        vector<pair<int, int>> p;
        int n, sum = 0; 
        scanf("%d", &n);
        pair<int, int> rank = make_pair(0, -1);
        for (int i = 1; i <= n; i++)
        {
            int temp = 0;
            scanf("%d", &temp);
            if (temp < 0)
            {
                if (rank.second == -1)
                {
                    rank.second = sum;
                }
                rank.first -= temp;
            }
            else 
            {
                if (rank.second != -1)
                {
                    for (int i = 0; i < p.size(); i++)
                    {
                        //printf("<%d, %d> cmp <%d, %d>\n", rank.second, rank.first, p[i].second, p[i].first);
                        int up = rank.second - rank.first;
                        up = p[i].second - up - p[i].first;
                        if (up) p[i].first += up;
                    }
                    for (int i = 0; i < rank.first; i++)
                    {
                        p.push_back(make_pair(rank.first - i, rank.second - i));
                    }
                    rank = make_pair(0, -1);
                }
            }
            sum += temp;
        }
        int ans = 0;
        int temp = 0;
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i].first > temp)
            {
                temp = p[i].first;
                ans = p[i].second;
            }
        }
        printf("%d\n", ans);
        // pair<int, int> rank = make_pair(-1, -1);
        // for (int i = 1; i <= n; i++)
        // {
        //     int temp = 0;
        //     scanf("%d", &temp);
        //     if (temp < 0)
        //     {
        //         if (rank.second == -1)
        //         {
        //             rank.second = sum;
        //         }
        //         rank.first -= temp;
        //     }
        //     else 
        //     {
        //         if (rank.second != -1)
        //         {
        //             p.push(rank);
        //             rank = make_pair(-1, -1);
        //         }
        //     }
        //     sum += temp;
        // }
        // if (rank.second != -1)
        //     p.push(rank);
        // if (!p.empty())
        //     printf("%d\n", p.top().second);
        // else printf("%d\n", n);
    }
    return 0;
}