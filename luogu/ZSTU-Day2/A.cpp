#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 100000005
#define ll long long
#define pal pair<ll, ll>

using namespace std;

// int calc[N];
// int prime[N], tot;
// bool not_prime[N];
vector<int> findhelp = {0, 1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260, 1680, 2520, 5040, 7560, 10080, 15120, 20160, 25200, 27720, 45360, 50400, 55440, 83160, 110880, 166320, 221760, 277200, 332640, 498960, 554400, 665280, 720720, 1081080, 1441440, 2162160, 2882880, 3603600, 4324320, 6486480, 7207200, 8648640, 10810800, 14414400, 17297280, 21621600, 32432400, 36756720, 43243200, 61261200};
vector<pal> ans = {{0, 0}, {1, 1}, {2, 2}, {4, 3}, {6, 4}, {12, 6}, {24, 8}, {36, 9}, {48, 10}, {60, 12}, {120, 16}, {180, 18}, {240, 20}, {360, 24}, {720, 30}, {840, 32}, {1260, 36}, {1680, 40}, {2520, 48}, {5040, 60}, {7560, 64}, {10080, 72}, {15120, 80}, {20160, 84}, {25200, 90}, {27720, 96}, {45360, 100}, {50400, 108}, {55440, 120}, {83160, 128}, {110880, 144}, {166320, 160}, {221760, 168}, {277200, 180}, {332640, 192}, {498960, 200}, {554400, 216}, {665280, 224}, {720720, 240}, {1081080, 256}, {1441440, 288}, {2162160, 320}, {2882880, 336}, {3603600, 360}, {4324320, 384}, {6486480, 400}, {7207200, 432}, {8648640, 448}, {10810800, 480}, {14414400, 504}, {17297280, 512}, {21621600, 576}, {32432400, 600}, {36756720, 640}, {43243200, 672}, {61261200, 720}};

int main()
{
    // freopen("ans.out", "w", stdout);
    // for (int i = 1; i < N; i++)
    //     calc[i] = 1;
    // for (int i = 2; i <= N - 1; i++)
    // {
    //     if (!not_prime[i])
    //         prime[++tot] = i;
    //     for (int j = 1; j <= N - 1 && i * prime[j] <= N - 1; j++)
    //     {
    //         not_prime[i * prime[j]] = true;
    //         if (i % prime[j] == 0)
    //             break;
    //     }
    // }
    // for (int i = 1; i <= tot; i++)
    // {
    //     for (int j = prime[i]; j < N; j += prime[i])
    //     {
    //         ll temp = j, time = 0;
    //         while (temp % prime[i] == 0)
    //         {
    //             temp /= prime[i];
    //             time++;
    //         }
    //         calc[j] = calc[j] * (time + 1);
    //     }
    // }
    // ll l = 0, r = 0;
    // ll aim = 0, val = 0;
    // for (int i = 1; i < N; i++)
    // {
    //     if (calc[i] > val)
    //     {
    //         r = i - 1;
    //         // printf("%lld %lld [%lld~%lld]\n", aim, val, l, r);
    //         // printf("%lld, ", l);
    //         printf("{%lld, %lld}, ", aim, val);
    //         val = calc[i];
    //         l = i;
    //         aim = i;
    //     }
    //     // printf("%d : %d\n", i, calc[i]);
    // }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int crd = lower_bound(findhelp.begin(), findhelp.end(), n) - findhelp.begin();
        if (!binary_search(findhelp.begin(), findhelp.end(), n)) crd--;
        printf("%lld %lld\n", ans[crd].first, ans[crd].second);    
    }
    return 0;
}