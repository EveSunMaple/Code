#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define MAX 100005

using namespace std;

int A[MAX], B[MAX];
int map[MAX];
int DP[MAX];

int main()
{
    int N = 0;
    scanf("%d", &N);
    memset(DP, 0x3f, sizeof(DP));
    //map按A[i]遍历下去就是一个1,2,3,4...N的数列
    //等于把A[i]按位代替成一个单调递增的数列！用B[i]遍历就可以得到此时B的数列
    for(int i = 1; i <= N; i++) {scanf("%d", &A[i]); map[A[i]] = i;}
    for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
    int len = 0;
    DP[0] = 0;
    for(int i = 1; i <= N; i++)
    {
        int l = 0, r = len, mid;
        if(map[B[i]] > DP[len]) DP[++len] = map[B[i]];
        else //寻找前面可以被B[i]替换的DP
        {
            while (l < r)
            {
                mid = (l + r) / 2;
                if(DP[mid] > map[B[i]]) r = mid;
                else l = mid + 1;
            }
            DP[l] = min(DP[l], map[B[i]]);
        }
    }

    printf("%d", len);

    return 0;
}