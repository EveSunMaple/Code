#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 200005

using namespace std;

vector<pair<long long, int>> sum;

int main()
{
    // freopen("music.in", "r", stdin);
    // freopen("music.out", "w", stdout);
    int n, k;
    long long ins = 0;
    scanf("%d%d", &n, &k);
    long long MAX = (1 << k) - 1;
    for (int i = 1; i <= n; i++)
    {
        long long temp = 0;
        string str;
        cin >> str;
        for (int j = 0; j < k; j++)
        {
            temp <<= 1;
            if (str[j] == 'A') temp++;
        }
        ins ^= temp;
        sum.push_back(make_pair(ins, i));
        sum.push_back(make_pair(ins ^ MAX, i));
    }
    int ans = 0;
    unordered_map<long long, int> hash;
    for (int i = 0; i < sum.size(); i++)
    {
        if (sum[i].first == 0) ans = max(ans, sum[i].second);
        if (hash[sum[i].first]) ans = max(ans, abs(sum[i].second - hash[sum[i].first]));
        else hash[sum[i].first] = sum[i].second;
    }
    printf("%d", ans);
    return 0;
}