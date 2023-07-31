#include <iostream>
#include <cstring>
#include <cmath>
#define ll long long
#define MAX 10002

using namespace std;

ll readytree[MAX];
ll lim = 1;
ll n = 0, maxline = 0;
char ans[MAX][MAX * 10];

//定义节点
class node
{
public:
    ll sum, line, level;
    bool tag = 0;
}tree[MAX];

int check(int num)
{
	int cnt = 0;
    if(num == 0)
        return 1;
	for (; num > 0;)
    {
		num = num / 10;
		cnt++;
	}
	return cnt;
}

void change(ll t, ll cnt)
{
    ll r = t;
    for(int i = t + 1; i <= n; i++)
    {
        if(ans[i][cnt] == '\0')
            break;
        if(ans[i][cnt] == '.' || ans[i][cnt] == '|')
        {
            r++;
            if(ans[i][cnt] == '|')
            {
                for(int j = t; j <= r; j++)
                {
                    ans[j][cnt] = '|';
                }
                break;
            }
        }
    }
    r = t;
    for(int i = t - 1; i >= 1; i--)
    {
        if(ans[i][cnt] == '\0')
            break;
        if(ans[i][cnt] == '.' || ans[i][cnt] == '|')
        {
            r--;
            if(ans[i][cnt] == '\0')
                break;
            if(ans[i][cnt] == '|')
            {
                for(int j = r; j <= t; j++)
                {
                    ans[j][cnt] = '|';
                }
                break;
            }
        }
    }
}

void insert(ll num, ll crd)
{
	if (readytree[crd] == -1e9)
    {
		readytree[crd] = num;
		return;
	}
	if (num >= readytree[crd])
		insert(num, crd * 2);
	else
		insert(num, crd * 2 + 1);
	return;
}

ll build(ll crd, ll sum, ll line, ll level, ll note)
{
    maxline = max(maxline, line);

    if(note <= lim)
    {
        note = lim;
    }
    lim = max(lim, note);

    if(readytree[crd * 2] != -1e9) //UP 
    {
        note = build(crd * 2, readytree[crd * 2], line + 3 + check(sum), level + 1, note - 1) + 1;
        tree[note].tag = 1;
    }

    tree[note].sum = sum;
    tree[note].line = line;
    tree[note].level = level;

    if(readytree[crd * 2 + 1] != -1e9) //DOWN 
    {
        tree[note].tag = 1;
        lim = max(lim, build(crd * 2 + 1, readytree[crd * 2 + 1], line + 3 + check(sum), level + 1, note + 1));
    }
    else
        lim = max(lim, note);

    return lim;
}

int main()
{
    ll num;
	//memset(readytree, -1, sizeof(readytree));
    for(int i = 0; i < MAX; i++)
        readytree[i] = -1e9;
    while (cin >> num)
    {
    	n++;
    	insert(num, 1);
	}

    build(1, readytree[1], 0, 1, 0);     //建树

    for(int i = 1; i <= n; i++)
    {
        ll cnt = 1;
        for(int j = 1; j <= tree[i].line - 1; j++)
        {
            if(j <= tree[i].line - 2)
                ans[i][cnt++] = '.';
            else
            {
                ans[i][cnt++] = '|';
                ans[i][cnt++] = '-';
            }
            
        }

        char num[6];
        ll l = check(tree[i].sum);

	    for (int j = l; j >= 1; j--)
        {
            num[j] = (char)(tree[i].sum % 10 + '0');
		    tree[i].sum /= 10;
	    }
	    for (int j = 1; j <= l; j++)
        {
            ans[i][cnt++] = num[j];
	    }

        if(tree[i].tag)
        {
                ans[i][cnt++] = '-';
                ans[i][cnt++] = '|';
        }
    }

    for(int i = 1; i <= n; i++)
        change(i, tree[i].line - 1);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= maxline + 6; j++)
        {
            if(ans[i][j] == '\0')
                break;
            cout << ans[i][j];
        }
        printf("\n");
    }

    return 0;
}