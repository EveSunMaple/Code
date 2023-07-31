#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int MAX = 10003;

int unprime[MAX];
int prime[MAX];
int NUM[MAX];

int cnt = 0;

inline int gcd(int a, int b)
{
	for(int i = 2; i <= cnt; i++)
	{
		if((a % prime[i] == 0) && (b % prime[i] == 0))
		{
			return prime[i];
		}
	}
	return -1;
}

int main()
{
	for(int i = 2; i * i < MAX; i++)
	{
		for(int j = i * 2; j < MAX; j += i)
		{
			unprime[j] = 1;
		}
	}
	
	for(int i = 1; i < MAX; i++)
	{
		if(!unprime[i])
		{
			prime[++cnt] = i;
		}
	}
	
	//for(int i = 1; i <= cnt; i++)
	//	cout << prime[i] << " ";
	
	memset(NUM, 0, sizeof(NUM));
	
	int a = 0, b = 0, p = 0;
	
	scanf("%d %d %d", &a, &b, &p);
	
	int ans = b - a + 1;
	
	for(int i = a; i <= b; i++)
		NUM[i] = i;
	
	for(int l = a, r = a + 1; l <= b; r++)
	{
		//cout << "L:" << l << "  ";
		//cout << "R:" << r << endl;
		
		if(gcd(l, r) >= p && NUM[l] != NUM[r])
		{
			ans--;
			if(NUM[l] != l)
			{
				NUM[r] = NUM[l];
			}
			else if(NUM[r] != r)
			{
				NUM[l] = NUM[r];
			}
			else if(NUM[r] != r && NUM[l] != l)
			{
				for(int i = a; i <= b; i++)
					if(NUM[i] == NUM[l])
						NUM[i] = NUM[r];
			}
			else
				NUM[r] = NUM[l];
		}
		
		if(r >= b)
		{
			l++;
			r = l + 1;
		}
	}
	
	//for(int i = a; i <= b; i++)
	//{
	//	cout << i << ":";
	//	for(int j = a; j <= b; j++)
	//		if(NUM[j] == i)
	//			cout << j << ' ';
	//	cout << endl;
	//}
	
	cout << ans;
	
	return 0;
}
