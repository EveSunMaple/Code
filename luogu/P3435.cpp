#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 1000005

using namespace std;

char s[N];
int nxt[N];
int l;
long long ans = 0;

int main()
{
    cin >> l;
    cin >> s + 1;
    for(int i = 2, j = 0; i <= l; i++)
    {
        while(j && s[i] != s[j + 1]) j = nxt[j];
        if(s[i] == s[j + 1]) j++;
        nxt[i] = j;
    }
	for (int i = 2, j = 2; i <= l; i++, j = i)
	{
		while(nxt[j]) j = nxt[j]; 
		if(nxt[i]) nxt[i] = j; 
		ans += i - j;
	}
    printf("%lld", ans);
    return 0;
}