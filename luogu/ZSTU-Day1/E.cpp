#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
int main()
{
    ll n, s;
    vector<ll> a;
    scanf("%lld%lld", &n, &s);
    for (ll i = 1; i <= n; i++)
    {
        ll temp;
        scanf("%lld", &temp);
        a.push_back(temp);
    }
    vector<ll> res(n, 0);
    ll mid = n / 2;
    vector<ll> left_sums(1 << mid);
    for (ll i = 0; i < (1 << mid); i++)
    {
        for (ll j = 0; j < mid; j++)
        {
            if (i & (1 << j))
            {
                left_sums[i] += a[j];
            }
        }
    }
    vector<ll> right_sums(1 << (n - mid));
    for (ll i = 0; i < (1 << (n - mid)); i++)
    {
        for (ll j = 0; j < n - mid; j++)
        {
            if (i & (1 << j))
            {
                right_sums[i] += a[mid + j];
                
            }
        }
    }
 
    vector<ll> right_sums_copy = right_sums;
    sort(right_sums.begin(), right_sums.end());
    for (ll i = 0; i < left_sums.size(); i++)
    {
        ll left_sum = left_sums[i];
        ll right_sum = s - left_sum;
        if (binary_search(right_sums.begin(), right_sums.end(), right_sum))
        {
            for (ll j = 0; j < mid; j++)
            {
                if (i & (1 << j))
                {
                    res[j] = 1;
                }
            }
            ll right_index = find(right_sums_copy.begin(), right_sums_copy.end(), right_sum) - right_sums_copy.begin();
            for (ll j = 0; j < n - mid; j++)
            {
                if (right_index & (1 << j))
                {
                    res[mid + j] = 1;
                }
            }
            break;
        }
    }
    for (ll i : res) printf("%lld", i);
    return 0;
}