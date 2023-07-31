#include <iostream>

using namespace std;

int inv[3000006];

int main()
{
	//ios::sync_with_stdio(false);
    //cout.tie(NULL);
	int n = 0, p = 0;
	scanf("%d %d", &n, &p);
	
	inv[1] = 1;
	printf("%d\n", inv[1]);
	
    for(int i = 2; i <= n; i++)
    {
    	inv[i] = (long long) (p - p / i) * inv[p % i] % p;
    	printf("%d\n", inv[i]);
    }

	return 0;
}
