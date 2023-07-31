#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

// vector<int> init(int num)
// {
//     vector<int> temp;
//     while (num)
//     {
//         temp.push_back(num % 3);
//         num /= 3;
//     }
//     return temp;
// }

int main()
{
    freopen("tor.in", "r", stdin);
    freopen("tor.out", "w", stdout);
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a, c;
        int mul = 1, ans = 0;
        scanf("%d%d", &a, &c);
        // // if (a < b) swap(a, b); // a >= b
        // vector<int> tor_a = init(a);
        // vector<int> tor_c = init(c);
        // while (tor_a.size() < tor_c.size()) tor_a.push_back(0);
        // while (tor_c.size() < tor_a.size()) tor_c.push_back(0);
        // int len = tor_a.size();
        // for (int i = 0; i < len; i++)
        // {
        //     int temp = (tor_c[i] - tor_a[i] + 3) % 3;
        //     ans += temp * mul;
        //     mul *= 3;
        // }
        while (a > 0 || c > 0)
        {
            int temp_a = a % 3;
            int temp_c = c % 3;
            a /= 3; c/= 3;
            int temp = (temp_c - temp_a + 3) % 3;
            ans += temp * mul;
            mul *= 3;
        }
        // for (int i = 0; i < tor_a.size(); i++)
        // {
        //     int temp = tor_a[i] + 3;
        //     int other = 0;
        //     if (i < tor_b.size()) other = tor_b[i];
        //     printf("ans += (%d - %d)[%d]* %d\n", temp - 3, other, (temp - other) % 3, mul);
        //     temp = (temp - other) % 3;
        //     ans += temp * mul;
        //     mul *= 3;
        // }
        printf("%d\n", ans);
    }
    
    return 0;
}