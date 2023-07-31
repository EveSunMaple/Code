#include<iostream>

using namespace std;

int main()
{
    int s1, s2;
    cin>>s1>>s2;
    int e1, e2;
    cin>>e1>>e2;
    int ans1 = e1 - s1;
    int ans2 = e2 - s2;
    if(e2 < s2)
    {
        ans1--;
        ans2 = e2 + 60 - s2;
    }
    cout<<ans1<<' '<<ans2;
    return 0;
}