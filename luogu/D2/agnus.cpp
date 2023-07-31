#include <iostream>
#include <cstring>
#include <cstdio>
#define N 30005

using namespace std;

int sit[N]; 
string target;
string a = "agnus";
int len;
int crd;

//void getnext()
//{
//    int i = 0,j = -1;
//    nxt[0] = -1;
//    while(i < len)
//	{
//        if(j == -1 || a[i] == a[j]) nxt[++i] = ++j;
//		else j = nxt[j];
//    }
//}

void find()
{
	int temp = 0;
	for (int i = 0; i < len; i++)
	{
		if (target[i] != a[temp]) { temp = 0; continue; }		
		else
		{
			temp++;
			if (temp == 5) 
			{
				sit[++crd] = i - 3;
				temp = 0;
			}
			if ((target[i + 1] != a[temp])) temp = 0;
		}
	}
}

int main()
{
	freopen("agnus.in", "r", stdin);
	freopen("agnus.out", "w", stdout);
	cin >> target;
	len = target.length();
	find();
	long long ans = 0;
	for (int i = 1; i <= crd; i++)// cout << sit[i] << endl;
	{
		int l = sit[i];
		int r = l + 4;
		ans += (long long)(l * (len - r + 1)); 
	}
	if (crd > 1)
	{
		for (int i = 1; i <= crd; i++)
		{
			for (int j = i + 1; j <= crd; j++)
			{
				int l = sit[i];
				int r = sit[j] + 4;
				ans -= (long long)(l * (len - r + 1)); 
			}
		}
	}
	printf("%lld", ans);
	return 0;	
} 
