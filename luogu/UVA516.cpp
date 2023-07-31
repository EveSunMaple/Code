#include<iostream>
#include<cstdio>
#include<queue>
#include <typeinfo>

using namespace std;

deque <int> ans; 
bool fin = true;
//const int maxn = 300003;
bool NUM[300003];
int prime[30003];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    
    for(; ch < '0' || ch > '9';)
    {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    
    for(; ch >= '0' && ch <= '9';)
    {
		x = x * 10 + ch - '0';
		ch = getchar();
		if(ch == '\n')
			fin = false;
	}
	
    return x * f;
}

int main()
{
	int cnt = 0;
	
	for(int i = 2; i * i < 300003; i++)
	{
		for(int j = i * 2; j < 300003; j += i)
		{
			NUM[j] = 1;
		}
	}
	
	for(int i = 1; i < 300003; i++)
	{
		if(!NUM[i])
		{
			prime[++cnt] = i;
		}
	}
	
	for(; ;)
	{
		fin = true;
		int num = 1;
		
		for(;fin ;)
		{
			int a = 0, b = 0;
			a = read();
			if(a == 0) return 0;
			b = read();
			
			
			for(int i = 1; i <= b; i++)
			{
				num *= a;
			} 
		}
		
		num--;
		
		for(int i = cnt; i > 0; i--)
		{
			bool yes = false;
			int c = 0;
			for(; ;)
			{
				if((num % prime[i] == 0) && num >= prime[i] && num != 1)
				{
					yes = true;
					num = num / prime[i];
					c++;
				}
				else
					break;
			}
			
			if(yes)
			{
				cout << prime[i] << ' ' << c << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}