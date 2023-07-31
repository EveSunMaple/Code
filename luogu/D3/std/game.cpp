#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int S[N << 2];
int L[N << 2], R[N << 2];

void push_up(int u, int l, int r)
{
    int d = min(L[r], R[l]);
    S[u] = S[l] + S[r] + d;
    L[u] = L[l] + L[r] - d;
    R[u] = R[l] + R[r] - d;
}

void modify(int u, int l, int r, int p, int x, int y)
{
    if (l == r)
    {
        L[u] += x;
        R[u] += y;
        return;
    }

    int mid = (l + r) >> 1;
    if (p <= mid)
        modify(u << 1, l, mid, p, x, y);
    else
        modify(u << 1 | 1, mid + 1, r, p, x, y);

    push_up(u, u << 1, u << 1 | 1);
}

int n;
multiset<int> B;
int a[N + 5], b[N + 5];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i), modify(1, 1, N, a[i], 0, 1);
    for (int i = 0; i < n; ++i)
        scanf("%d", b + i), modify(1, 1, N, b[i], 1, 0), B.insert(b[i]);

    int ans = S[1];
    for (int i = 0; i < n; ++i)
    {
        modify(1, 1, N, a[i], 0, -1);

        int l = a[i] + 1, r = *B.rbegin();
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            modify(1, 1, N, mid, -1, 0);

            if (1 + S[1] == ans)
                l = mid;
            else
                r = mid - 1;
            modify(1, 1, N, mid, +1, 0);
        }

        modify(1, 1, N, l, -1, 0);
        if (l <= r && 1 + S[1] == ans)
        {
            --ans;
            printf("%d ", l);
            B.erase(B.find(l));
        }
        else
        {
            modify(1, 1, N, l, +1, 0);

            l = 1, r = a[i];
            while (l < r)
            {
                int mid = (l + r + 1) >> 1;
                modify(1, 1, N, mid, -1, 0);

                if (S[1] == ans)
                    l = mid;
                else
                    r = mid - 1;
                modify(1, 1, N, mid, +1, 0);
            }
            modify(1, 1, N, l, -1, 0);

            printf("%d ", l);
            B.erase(B.find(l));
        }
    }
    return 0;
}
