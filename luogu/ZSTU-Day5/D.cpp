#pragma GCC optimize ("O2")
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 1005
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)

using namespace std;

int nxt[N];
string a[N];

void getnext(string tmp)
{
    int i = 0, j = -1;
    nxt[0] = -1;
    while (i < tmp.size())
    {
        if (j == -1 || tmp[i] == tmp[j])
        {
            i++, j++;
            nxt[i] = j;
        }
        else
            j = nxt[j];
    }
}

int getans(string tmp, string aim)
{
    int ans = 0;
    int i = 0, j = 0;
    while (j < aim.size())
    {
        // for (int t = 1; t <= j; t++) cout << " ";
        // cout << "v\n"; cout << aim << endl;
        // for (int t = 1; t <= i; t++) printf(" ");
        // cout << "v\n"; cout << tmp << endl;
        // cout << "CMP:  " << tmp[i] << " & " << aim[j] << endl;
        // cout << "J : " << j << endl;
        if (tmp[i] == aim[j]) 
        {
            i++, j++;
            if (i == tmp.size())
            {
                ans++;
                i = 0;
            }
        }
        else
        {
            if (i == 0) j++;
            i = nxt[i];
            if (i == -1) i++;
        }
    }
    return ans;
}

int main()
{
    fastio;
    int n, q;
    cin >> n >> q;
    string S;
    cin >> S;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        string tmp = S.substr(l - 1, r - l + 1);
        vector<int> ans;
        for (int i = 1; i <= n; i++) ans.push_back(getans(tmp, a[i]));
        sort(ans.begin(), ans.end());
        cout << ans[k - 1] << endl;
    }
    return 0;
}