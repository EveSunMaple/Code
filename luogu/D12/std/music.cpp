#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
const int N = 200010;


vector<pair<ll, int> > vec;

int main()
{
    freopen("music.in", "r", stdin);
    freopen("music.out", "w", stdout);
    int n, k;
    cin >> n >> k;

    ll base = ((1LL) << k) - 1;

    string t;
    getline(cin, t);
    ll s = 0;
    vec.push_back(make_pair(s, 0));
    vec.push_back(make_pair(s ^ base, 0));
    for (int i = 1; i <= n; i++)
    {
        getline(cin, t);
        ll now = 0;

        for (int j = 0; j < k; j++)
        {
            if (t[j] == 'A') now = now * 2 + 1;
            else now = now * 2;
        }
        s ^= now;
        vec.push_back(make_pair(s, i));
        vec.push_back(make_pair(s ^ base, i));
    }

    sort(vec.begin(), vec.end());

    int las = 0, m = vec.size();
    int ans = 0;
    for (int i = 0; i < m; i = las)
    {
        for (las = i; las < m && vec[i].first == vec[las].first; las++);
        ans = max(ans, vec[las - 1].second - vec[i].second);
    }

    cout << ans << endl;
    return 0;
}

    
    
    
