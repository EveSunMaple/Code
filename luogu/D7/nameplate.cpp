#include <iostream>
#include <cstring>
#include <cstdio>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define ll long long
#define N 100005

using namespace std;

int a[N];
int ans;

int main()
{
    fastio;
    freopen("nameplate.in", "r", stdin);
    freopen("nameplate.out", "w", stdout);
    int n, D;
    scanf("%d%d", &n, &D);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    for (int l = 1; l <= n; l++)
    {
    	//printf("\r%f%\r", ((float)l / n) * 100);
        int temp = a[l];
        for (int r = l; r <= n; r++)
        {
            temp = min(temp, a[r]);
            if ((a[l] ^ a[r]) == (D ^ temp)) ans++;
        }
    }
    //printf("\n");
    //for (int l = 1; l <= n; l++)
    //{
    //    int temp = a[l];
    //    for (int r = l; r <= n; r++)
    //    {
    //        temp = min(temp, a[r]);
    //        //ins[l][r] = temp;
    //        if (!tag[temp])
    //        {
    //            stk[++top] = temp;
    //            tag[temp] = true;
    //        }
    //        cnt[temp][a[l] ^ a[r]]++;
    //    }
    //}
    //for (int i = 1; i <= top; i++)
    //    ans += cnt[stk[i]][stk[i] ^ D];

    printf("%d", ans);
    return 0;
}
