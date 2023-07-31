#include <iostream>
#include <cstdio>
#include <cmath>
#define N 200005

using namespace std;

int num[N];
int ans;
int n;

void dfs(int crd, int A, int B)
{
    A ^= num[crd]; //printf("A:%d  ", A);
    B &= num[crd]; //printf("B:%d\n", B);
    if(A == B) ans++;
    if(crd < n) dfs(crd + 1, A, B);
}

int main()
{
    freopen("forward.in", "r", stdin);
    freopen("forward.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
    for(int i = 2; i <= n; i++) dfs(i, num[i - 1], num[i - 1]);
    printf("%d", ans + n);
    return 0;
}