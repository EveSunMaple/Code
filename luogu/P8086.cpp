#include<iostream>

using namespace std;

int l[10000001];
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}

int main()
{
    int n;
    n = read();
    int a, b;
	long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        a = read();b = read();
        if(b > 1)
        {
            l[a]++;
            if(l[a] == 1)
            {
            	sum += b;
			}
        }
    }
    cout<<sum;
    return 0;
}
