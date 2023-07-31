#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 2005
#define LL long long

using namespace std;

bool check(LL num)
{
    // because num = y(y - 1) = y^2 - y
    // so 4 * num + 1 = 4y^2 - 4y + 1 = (2y - 1)^2
    LL test = sqrt(4 * num + 1);
    if(test * test == 4 * num + 1) return true;
    return false; // dont -> else return false;
}

void solve()
{
    LL n; // n -> 10^18
    scanf("%lld", &n);
    // if x < y
    // because n = x(x - 1)y(y - 1) - > x > 1
    // so x^4 < n -> n -> 10^18 -> x -> 10^5
    for(LL i = 2; i <= 100000; i++)
    {
        if(n % (i * (i - 1)) == 0   // must -> n
        && check(n / (i * (i - 1))))// check if have y
        {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");
}

int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
    // n = x(x - 1)y(y - 1)
    int t;
    scanf("%d", &t);
    while (t--) solve();
    
    return 0;
}