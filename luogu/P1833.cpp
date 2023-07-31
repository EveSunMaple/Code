#include <iostream>
#include <cstdio>
#include <cmath>
#define MAX 100005

using namespace std;

inline int read() 
{
	char ch = getchar();
	int x = 0, cf = 1;
	while(ch < '0' || ch > '9')
    {
		if(ch == '-') cf = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') 
    {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * cf;
}

int T; // 可用的时间之和
int N; // 树的数量
int C[MAX];
int M[MAX];
int DP[MAX];
int tot;

int main()
{
    int t1 ,t2 ,t3, t4;
    t1 = read();
    t2 = read();
    t3 = read();
    t4 = read();
    T = (t3 - t1)  * 60 + t4 - t2;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        int m, c, p;
        scanf("%d%d%d", &m,  &c, &p);
        if(p == 0)
        {
            tot++;
            C[tot] = c;
            M[tot] = m;
            for(int j = M[tot]; j <= T; j++)
                DP[j] = max(DP[j - M[tot]] + C[tot], DP[j]);
        }
        else
        {
            for(int j = 1; p - j >= 0; j <<= 1 )
	  	    {
	  	  	    tot++;
	  	  	    C[tot] = c * j;
	  	  	    M[tot] = m * j;
	  	  	    p -= j;
                for(int v = T; v >= M[tot]; v--)
                    DP[v] = max(DP[v - M[tot]] + C[tot], DP[v]);
	  	    }
	  	    if(p)
	  	    {
	  	  	    tot++;
	  	  	    C[tot] = c * p;
	  	  	    M[tot] = m * p;    
                for(int j = T; j >= M[tot]; j--)
                    DP[j] = max(DP[j - M[tot]] + C[tot], DP[j]);
	  	    }
        }
    }
    printf("%d", DP[T]);
    return 0;
}