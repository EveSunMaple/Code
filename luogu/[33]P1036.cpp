#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int num[23], ans[23];
bool N[23];
int sum[1001];
int n = 0, k = 0;
int l = 1;
int out = 0;

void dfs(int node, int step)
{
    for(int i = 1; i <= n; i++)
    {
        if(!N[i])
        {
            ans[step] = num[i];
            N[i] = 1;
            dfs(i, step + 1);
        }
        else
            continue;
    }

    N[node] = 0;

    if(step == n)
    {
        sum[l] = 0;

        for(int i = 1; i <= k; i++)
        {
            sum[l] += ans[i];
        }

        for(int i = 1; i < l; i++)
        {
            if(sum[l] == sum[i] && sum[l] != 0)
                return;
        }
        
        l++;

        if(sum[l - 1] <= 1)
        {
		    return;
	    }

        for (int i = 2; i <= sqrt(sum[l - 1]); i++)
        {
            if ((sum[l - 1] % i) == 0)
            {
               return;
            }
        }
        
        out++;
    }

    return;
}

int main()
{
    memset(ans, 0, sizeof(ans));
    memset(N, 0, sizeof(N));

    cin>> n >> k;
    
    for(int i = 1; i <= n; i++)
    {
        cin>> num[i];
    }

    dfs(0, 1);
    cout<< out;
    
    return 0;
}