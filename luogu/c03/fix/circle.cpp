#include <unordered_map>
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 200005

using namespace std;

// int num[N];
// int add[N];

void solve()
{
    int len, ans = 0;
    int temp, sum = 0;
    scanf("%d", &len);
    // bool l = false, r = false;
    // memset(num, 0, sizeof(num));
    // memset(add, 0, sizeof(add));
    unordered_map<int, int> hash;
    for (int i = 1; i <= len; i++)
    {
        scanf("%d", &temp);
        sum += temp;
        hash[sum]++; // 在相同的前缀和标记加一
        ans = max(ans, hash[sum]); // 找到现在有几个标记，如果比ans高就替代
    }
    // for (int i = 1; i <= len; i++)
    // {
    //     scanf("%d", &num[i]);
    //     add[i] = add[i - 1] + num[i];
    // }
    // for (int i = 0; i <= len; i++)
    // {
    //     if (hash.count(add[i]))
    //     {
    //         ans++;
    //         if (hash[add[i]] == 0) l = true;
    //         if (i == len) r = true;
    //         hash.clear();
    //     }
    //     else
    //         hash[add[i]] = i;
    // }
    // if (!l || !r) ans++; // !l && !r
    printf("%d\n", ans);
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) solve();
    return 0;
}