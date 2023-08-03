#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix multiply(matrix a, matrix b, ll mod)
{
    ll n = a.size();
    matrix c(n, vector<ll>(n));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            for (ll k = 0; k < n; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
    return c;
}

matrix matrix_pow(matrix a, ll n, ll mod)
{
    ll m = a.size();
    matrix res(m, vector<ll>(m));
    for (ll i = 0; i < m; i++)
        res[i][i] = 1;
    while (n)
    {
        if (n & 1)
            res = multiply(res, a, mod);
        a = multiply(a, a, mod);
        n >>= 1;
    }
    return res;
}

int main()
{
    matrix a = {{1, 0, 1, 1},
                {1, 0, 0, 0},
                {0, 1, 0, 0},
                {0, 0, 1, 0}}; // 转移矩阵
    ll n;
    scanf("%lld", &n); // 2, 4, 6, 9
    matrix ans = matrix_pow(a, n - 4, 10007);
    printf("%lld", (ll)(2 * ans[0][3] + 4 * ans[0][2] + 6 * ans[0][1] + 9 * ans[0][0]) % 10007);
    return 0;
}