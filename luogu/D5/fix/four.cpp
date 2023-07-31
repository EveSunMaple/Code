#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <array>
#define ll long long

using namespace std;

int a[44];
vector<array<int, 2>> le; // left
vector<array<int, 2>> ri; // right
ll ans;
int n;

vector<array<int, 2>> init(int l, int r)
{
    vector<int> temp{0}; // init 0
    for (int i = l; i < r; i++)
    {
        vector<int> t = temp; // instead dfs
        for (int x : temp)
            t.push_back(x + a[i]);
        temp = t;
    }
    vector<array<int, 2>> ret; // first save now. second save old
    for (int x : temp)
        ret.push_back({0, x});
    return ret;
}

void reorder(vector<array<int, 2>> &str, int pw)
{
    vector<array<int, 2>> v[10];
    for (auto [_, x] : str)
    {
        int head = (x / pw) % 10; // str_head -> |*^****...|
        int val = x % (pw * 10);  // str_val -> (int)|*****...|
        v[head].push_back({val, x});
    }
    str.clear(); // remove
    for (int i = 0; i <= 9; i++)
        for (auto temp : v[i])
            str.push_back(temp);
}

ll calc(int d)
{
    int r = ri.size(); // if all
    ll temp = 0;
    for (int l = 0; l < le.size(); l++)
    {
        // cmp now > d ? check->NO : check->YES
        while (r > 0 && ri[r - 1][0] + le[l][0] > d)
            r--; // cmp fail -> r-- -> find other
        temp += r;
    }
    return temp;
}

int main()
{
    freopen("four.in", "r", stdin);
    freopen("four.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    le = init(0, n / 2); // 20 -> 2^20
    ri = init(n / 2, n); // 20 -> 2^20

    for (int i = 0, pw = 1; i <= 8; i++, pw *= 10)
    {
        reorder(le, pw); // -> reorder -> cmp now -> check
        reorder(ri, pw); // -> reorder -> cmp now -> check
        // now -> [4 * 10^pw, 5 * 10^pw - 1]
        // or: -> [14 * 10^pw, 15 * 10^pw - 1]
        ans += calc(5 * pw - 1) - calc(4 * pw - 1) + calc(15 * pw - 1) - calc(14 * pw - 1);
    }
    printf("%lld", ans);
    return 0;
}