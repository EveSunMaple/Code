#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
long long n,k;
bool prime(long long x)
{
	long long i;
	for (i = 2; i <= sqrt(x); i++)
	if (x % i == 0) return false;
	return true;
}
int main()
{
	scanf("%lld%lld", &n, &k);
    n++; k++;
	if(prime(k))
	{
		if ((n / k) == 1) printf("1");
		else printf("2");
	}
	else printf("2");

    return 0;
}