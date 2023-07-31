#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

long long SUM[50003];
int l[7] = {0, 50003, 50003, 50003, 50003, 50003, 50003};
int r[7];

int main()
{
//	memset(l, 0x3f, sizeof(r));
	memset(r, 0, sizeof(l));
//	memset(SUM, 0, sizeof(SUM));
//	freopen("1.txt","r",stdin);
	int n = 0;
	cin >> n;
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++)
	{
		int j = 0;
		cin >> j;
		
		SUM[i] = SUM[i - 1] + j;
		if(i < l[SUM[i] % 7])
		{
			l[SUM[i] % 7] = i;
		}
		if(i > r[SUM[i] % 7])
		{
			r[SUM[i] % 7] = i;
		}
		//cout << i << ":" << SUM[i] << endl;
	}
	
	for(int i = 0; i < 7; i++)
	{
		int num = abs(r[i] - l[i]);
		//cout << i << ':' << l[i] << ' ' << r[i] <<' '<<num<<'\n';
		if(num > ans && (((r[i] != 0 || l[i] != 50003) && i == 0) || (r[i] != 0 && l[i] != 50003)))
			ans = num;
	}
	
	cout << ans;
	
	return 0;
}
