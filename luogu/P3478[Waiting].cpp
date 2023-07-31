#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 1000005

using namespace std;

vector<vector<int>> son(MAX);
int leh[MAX];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n ; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        son[u].push_back(v);
        son[v].push_back(u);
    }
    return 0;
}