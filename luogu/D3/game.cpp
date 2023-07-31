#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 100005

using namespace std;

int n;
int B[N], A[N];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &B[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    // BAD PROBLEM :(
    // I DONT LIKE GAME
    // PLEASE EXCUSE ME
    sort(A + 1, A + 1 + n);
    for (int i = 1; i <= n; i++)
        printf("%d ", A[i]);
    return 0;
}