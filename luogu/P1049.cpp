#include <iostream>
#include <queue>

using namespace std;

deque <int> ans;

int NUM[1002];
long long SUM[1002];
int n = 0, c = 0;
int cnt = 0; //下标

int dfs(int sum, int cnt)
{
    int myans = 0;

    for(int i = cnt; i >= 1; i--)
    {
        if(sum + SUM[i] < ans.front())
            break;
        if(sum + NUM[i] <= c)
            myans = dfs(sum + NUM[i], i - 1);
        //cout << myans << endl;
        if(myans > ans.front())
        {
            ans.push_front(myans);
        }
    }

    return sum;
}

int main()
{
    cin >> c >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> NUM[i];
        SUM[i] += SUM[i - 1] + NUM[i];
        if(NUM[i] <= c)
            cnt = i;
    }

    ans.push_front(-1);

    dfs(0, cnt);

    cout << c - ans.front();

    return 0;
}
