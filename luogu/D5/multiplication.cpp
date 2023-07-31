#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define ll long long

using namespace std;

const int N = 2000 + 5;
ll num[N], top, start;
pair<int, int> fi[N][N];
bool tag[N];
int p;

void case1(ll a, ll b)
{
    // for (ll i = 1; i <= top; i++)
    // {
    //     for (ll j = 1; j <= top; j++)
    //     {
    //         ll a = stk[i], b = stk[j];
    //         ll temp = num[a] * num[b];
    //         ll o_a = fi[a][b].first;
    //         ll o_b = fi[a][b].second;
    //         if (!tag[o_a] && tag[o_b]) 
    //             { num[o_a] = (temp - num[o_b]) / p; tag[o_a] = true; stk[++top] = o_a;}
    //         if (tag[o_a] && !tag[o_b]) 
    //             { num[o_b] = temp - num[o_a] * p; tag[o_b] = true; stk[++top] = o_b;}
    //     }
    // }
    ll temp = num[a] * num[b];
    ll o_a = fi[a][b].first;
    ll o_b = fi[a][b].second;
    // printf("[%lld](%lld) * [%lld](%lld) = [%lld](%lld) * p + [%lld](%lld)\n", a, num[a], b, num[b], o_a, num[o_a], o_b, num[o_b]);
    if (!tag[o_a] && tag[o_b]) 
        { num[o_a] = (temp - num[o_b]) / p; tag[o_a] = true; top++;/* stk[++top] = o_a;printf("[%lld](%lld) * [%lld](%lld) = [%lld](%lld) * p + [%lld](%lld)\n", a, num[a], b, num[b], o_a, num[o_a], o_b, num[o_b]);*/}
    if (tag[o_a] && !tag[o_b]) 
        { num[o_b] = temp - num[o_a] * p; tag[o_b] = true; top++;/* stk[++top] = o_b;printf("[%lld](%lld) * [%lld](%lld) = [%lld](%lld) * p + [%lld](%lld)\n", a, num[a], b, num[b], o_a, num[o_a], o_b, num[o_b]);*/}
}

void case2(ll a, ll b)
{
    ll o_a = fi[a][b].first;
    ll o_b = fi[a][b].second;
    ll temp = num[o_a] * p + num[o_b];    
    // printf("[%lld](%lld) * [%lld](%lld) = [%lld](%lld) * p + [%lld](%lld)\n", a, num[a], b, num[b], o_a, num[o_a], o_b, num[o_b]);
    if (!tag[a] && tag[b] && num[b] > 0) 
        { num[a] = temp / num[b]; tag[a] = true; top++;/* stk[++top] = o_a;printf("[%lld](%lld) * [%lld](%lld) = [%lld](%lld) * p + [%lld](%lld)\n", a, num[a], b, num[b], o_a, num[o_a], o_b, num[o_b]);*/}
    if (tag[a] && !tag[b] && num[a] > 0) 
        { num[b] = temp / num[a]; tag[b] = true; top++;/* stk[++top] = o_b;printf("[%lld](%lld) * [%lld](%lld) = [%lld](%lld) * p + [%lld](%lld)\n", a, num[a], b, num[b], o_a, num[o_a], o_b, num[o_b]);*/}
}   

void case3(ll a, ll b)
{
    ll o_a = fi[a][b].first;
    ll o_b = fi[a][b].second;
    ll temp = num[o_a] * p + num[o_b];    
    // printf("[%lld](%lld) * [%lld](%lld) = [%lld](%lld) * p + [%lld](%lld)\n", a, num[a], b, num[b], o_a, num[o_a], o_b, num[o_b]);
    if (tag[o_a] && tag[o_b]) 
        { num[a] = sqrt(temp); tag[a] = true; top++;/* stk[++top] = o_a;printf("[%lld](%lld) * [%lld](%lld) = [%lld](%lld) * p + [%lld](%lld)\n", a, num[a], b, num[b], o_a, num[o_a], o_b, num[o_b]);*/}
    if (a == o_a && tag[o_b]) 
        { num[a] = p; tag[a] = true; top++;/* stk[++top] = o_b;printf("[%lld](%lld) * [%lld](%lld) = [%lld](%lld) * p + [%lld](%lld)\n", a, num[a], b, num[b], o_a, num[o_a], o_b, num[o_b]);*/}
    if (b == o_b && tag[o_a]) 
        { num[b] = (1 + sqrt(1 + 4 * temp)) / 2; tag[b] = true; top++;/* stk[++top] = o_b;printf("[%lld](%lld) * [%lld](%lld) = [%lld](%lld) * p + [%lld](%lld)\n", a, num[a], b, num[b], o_a, num[o_a], o_b, num[o_b]);*/}
}

void solve()
{
    // printf("NOW :");
    // for (ll i = 1; i <= top; i++) printf ("%lld ", stk[i]);
    // printf("\n");
    // printf("%lld\n", top);
    for (ll i = 0; i < p; i++)
    {
        for (ll j = 0; j < p; j++)
        {
            if (tag[i] && tag[j]) case1(i, j);
            ll o_a = fi[i][j].first;
            ll o_b = fi[i][j].second;
            if (tag[o_a] && tag[o_b]) case2(i, j);
            if (i == j && !tag[i]) case3(i, j);
            // ll a = stk[i], b = stk[j];
            // ll temp = num[a] * num[b];
            // ll o_a = fi[a][b].first;
            // ll o_b = fi[a][b].second;
            // if (!tag[o_a] && tag[o_b]) 
            //     { num[o_a] = (temp - num[o_b]) / p; tag[o_a] = true; stk[++top] = o_a;}
            // if (tag[o_a] && !tag[o_b]) 
            //     { num[o_b] = temp - num[o_a] * p; tag[o_b] = true; stk[++top] = o_b;}
        }
    }
}

int main()
{
    //freopen("multiplication.in", "r", stdin);
    //freopen("multiplication.out", "w", stdout);
    scanf("%d", &p);
    // tag[1] = true; num[1] = 44, top++;
    // tag[2] = true; num[2] = 9, top++;
    // tag[3] = true; num[3] = 31, top++;
    for (ll i = 0; i < p; i++)
    {
        for (ll j = 0; j < p; j++)
        {
            ll a, b;
            scanf("%d%d", &a, &b);
            if (i == a && (a == b)) { num[i] = 0; start = i; if (!tag[i]) top++; tag[i] = true;/*stk[0] = i;*/}
            if (j == a && (a == b)) { num[j] = 0; start = j; if (!tag[j]) top++; tag[j] = true;/*stk[0] = j;*/}
            fi[i][j] = make_pair(a, b);
            if (a == start && b == i && b != start) 
            { 
                // if (!tag[j])
                //     stk[++top] = j;
                if (!tag[j]) top++;
                num[j] = 1; 
                tag[j] = true;
            }
        }
    }
    while (top < p) solve();
    for (ll i = 0; i < p; i++) printf("%lld ", num[i]);
    return 0;
}