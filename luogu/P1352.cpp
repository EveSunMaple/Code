#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#define MAX 10000

using namespace std;

int h[MAX];
vector <int>son[MAX];
int sum[MAX][2];
int ans = 0;

void solve(int crd)
{
    sum[crd][0] = 0;
    sum[crd][1] = h[crd];
    for(int i = 1; i <= son[crd].size(); i++)
    {
        int s = son[crd][son[crd].size() - i];
        solve(s);
        sum[crd][0] += max(sum[s][0], sum[s][1]);
        sum[crd][1] += sum[s][0];
        ans = max(sum[crd][0], sum[crd][1]);
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &h[i]);

    for(int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        son[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++) solve(i);

    cout << ans;

    return 0;
}