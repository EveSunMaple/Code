#include <unordered_map>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define ll long long

using namespace std;

const int N = 2000 + 5;
int num[N];
int p;

int main()
{
    freopen("multiplication.in", "r", stdin);
    freopen("multiplication.out", "w", stdout);
    scanf("%d", &p);
    for (int i = 1; i <= p; i++)
    {
        int tot = 0;
        bool zero = true;
        unordered_map<int, int> hash;
        for (int j = 1; j <= p; j++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (a != b) zero = false;
            if (hash.count(a)) continue;
            else { tot++; hash[a] = a; }
        }
        if (!zero) num[i] = tot;
    }
    for (int i = 1; i <= p; i++) printf("%d ", num[i]);
    return 0;
}