#include<iostream>

using namespace std;

int n[40001];
int main()
{
    int N;
    cin>>N;
    for(int i = 0; i < 40001; i++)
    {
        if (cin.get() == '\n')
            break;
        cin>>n[i];
    }
    for(int i = 0, v = 0, ans = 0, sum = 0; i < 40001; i++)
    {
        if(sum >= N * N)
            break;
        else
            for(int j = 0; j < n[i]; j++)
            {
                cout<<ans % 2;
                v++;
                if(v == N)
                {
                    v = 0;
                    cout<<endl;
                }
            }
        ans++;
        sum += n[i];
    }
    return 0;
}