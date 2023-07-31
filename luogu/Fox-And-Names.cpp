#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> g(27);
string ch[105];
bool no = false;
bool he[27];
int deg[27];
int q[27];
int l, r;
int n = 0;

struct node
{
    char a, b;
    node(char i, char j)
    {
        a = i;
        b = j;
    }
};


void init()
{
    for(int i = 1; i <= 25; i++)
        if(!he[i])
        {
            g[i].push_back(i + 1);
            deg[i + 1]++;
        }
}

node del(string a, string b)
{
    for(int i = 0; i < min(a.length(), b.length()); i++)
    {
        if(a[i] == b[i]) continue;
        else return node(a[i], b[i]);
    }
    if(a.length() <= b.length()) return node('+', '+');
    return node('-', '-');
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        cin >> ch[i];
    }
    for(int i = 1; i < n; i++)
    {
        char u = ch[i][0], v = ch[i + 1][0];
        if(ch[i][0] == ch[i + 1][0])
        {
            node t = del(ch[i], ch[i + 1]);
            u = t.a; v = t.b;
            if(u == '+' && v == '+') continue;
            else if(u == '-' && v == '-') no = true;
            else
            {
                g[(int)u - 96].push_back((int)v - 96);
                deg[(int)v - 96]++; 
                he[(int)u - 96] = true;
                he[(int)v - 96] = true; 
            }
            continue;
        }
        g[(int)u - 96].push_back((int)v - 96);
        deg[(int)v - 96]++; 
        he[(int)u - 96] = true;
        he[(int)v - 96] = true;
    }
    init();
    for(int i = 1; i <= 26; i++)
    {
        if(deg[i] == 0)
            q[++r] = i;
    }

    while(l < r)
    {
        for(int i = l; i <= r; i++)
        {
            int u = q[++l];
            for(int v : g[u])
            {
                if(--deg[v] == 0) q[++r] = v;
            }
        }
    }

    if(no || l - 1 != 26) printf("Impossible");
    else
    {
        for(int i = 1; i <= 26; i++)
            printf("%c", (char)(q[i] + 96));
    }
    return 0;
}