#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cmath>
#define N 100005

using namespace std;

//deque<int> list;
int tot = 0;
int prime[N / 10];
int brnum[N];
int brall[N];
bool no_prime[N];
bool find_in[N];
int n;

void init_prime()
{
    for(int i = 2; i <= N; i++)
    {
        if(no_prime[i]) continue;
        else
        {
            prime[++tot] = i;
            for(int j = i; j <= N; j += i)
                no_prime[j] = true;
        }
    }
    //printf("%d\n", tot); 9753
    //for(int i = 1; i <= tot; i++)
    //    printf("%d\n", prime[i]);
}

void run_time(int num)
{
    memset(brnum, 0, sizeof(brnum));
    memset(brall, 0, sizeof(brall));
    memset(find_in, 0, sizeof(find_in));
    //list.push_back(1);
    brall[0] = 1;
    int other = num;
    int t = 0;
    bool check = false;
    for(int i = 1; i <= tot; i++)
    {
        for(; ;)
        {
            if(num % prime[i] == 0)
            {
                num /= prime[i]; //printf("%d ", prime[i]);
                //list.push_back(prime[i]);
                brnum[++t] = prime[i];
                brall[t] = brall[t - 1] * brnum[t];
                int now = brall[t] + other / brall[t];
                find_in[now] = true;
                if(find_in[now - 1] || find_in[now + 1] || now == n || now == n + 2) check = true;
            }
            else break;
        }
    }
    //list.push_back(other);
    //brnum[++t] = other;
    //printf("\n");
    if(check) printf("Yes\n");
    else printf("No\n");
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    init_prime();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        run_time(num);
    }
    return 0;
}