#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#define N 100005

using namespace std;

priority_queue<int> now_min;
vector<vector<int>> g(N);
deque<int> now;
deque<int> a;
deque<int> b;
int col[N];
int n;

bool dfs(int u, int from)
{
    for(int v : g[u])
    {
        if(v == from) continue;
        if(col[v] == col[u]) return false;
        if(col[v] > 0) continue;
        col[v] = 3 - col[u];
        if(!dfs(v, u)) return false;
    }
    return true;
}

bool check()
{
    bool check_over = true;
    memset(col, 0, sizeof(col));
    for(int i = 1; i <= n ; i++)
    {
        if(!col[i])
        {
            col[i] = 1;
            check_over = check_over && dfs(i, 0);
        }
    }
    for(int i = 1; i <= n; i++)
        if(!col[i]) check_over = false;
    return check_over;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        now.push_back(num);
        now_min.push(-num);
    }
    while (!now.empty() || !a.empty() || !b.empty())
    {
        int num_a, num_b;
        bool change = true;
        bool ok_a = false;
        bool ok_b = false;
        int num = now.front();
        int fin = -now_min.top();
        if(b.empty()) { if(!now.empty()) {b.push_back(num); printf("c "); now.pop_front(); continue;} }
        else
        {
            num_b = b.back();
            if(num_b > num) ok_b = true;
            if(num_b == fin)
            {
                now_min.pop();
                b.pop_back();
                printf("d ");
                change = false;
            }
        }
        if(a.empty()) { if(!now.empty()) {a.push_back(num); printf("a "); now.pop_front(); continue;} }
        else
        {
            num_a = a.back();
            if(num_a > num) ok_a = true;
            if(num_a == fin)
            {
                now_min.pop();
                a.pop_back();
                printf("b ");
                change = false;
            }
        }
        //num_a = a.back();
        //num_b = b.back();
        
        if(!now.empty())
        {
            if(ok_a && ok_b)
            {
                if(num_a > num_b) { b.push_back(num); printf("c "); now.pop_front(); continue; }
                else { a.push_back(num); printf("a "); now.pop_front(); continue; }
            }
            else if (ok_a) { a.push_back(num); printf("a "); now.pop_front(); continue; }
            else if (ok_b) { b.push_back(num); printf("c "); now.pop_front(); continue; }
            else 
            {
                if(change)
                {
                    printf("0");
                    return 0;
                }
            }
        }
    }
    
    return 0;
}