#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <tuple>
#define N 100005

using namespace std;

struct Node
{
    int len;
    vector<int> num;
    Node() { len = 0; num.clear(); }
    Node(int a, vector<int> b)
    { len = a, num = b; }
};

int tot = -1;

bool cmp(Node a, Node b)
{
	if (a.num[0] == 1e9 && a.len > 0) a.len = tot--;
	if (b.num[0] == 1e9 && b.len > 0) b.len = tot--;
    if (a.len == b.len)
        return a.num[0] < b.num[0];
    return a.len > b.len;
}

int ans;
int a[N];
bool tag[N];
vector<Node> range;

void solve()
{
    sort(range.begin(), range.end(), cmp);
    int aim = (range[0].len) >> 1;
    if ((range[0].len) % 2 == 0) aim--;
    ans = range[0].num[aim];
    range[0].num[aim] = 1e9;
	if (aim < range[0].len - 1)
	{
		vector<int> temp;
	    for (int i = aim + 1; i < range[0].len; i++)
	    {
	        temp.push_back(range[0].num[i]);
	        range[0].num[i] = 1e9;
	    }
	    range.push_back(Node(temp.size(), temp));
	}
	if (aim == 0) aim = tot--;
    range[0].len = aim;
    sort(range[0].num.begin(), range[0].num.end());
}

int main()
{
    int m, n, q;
    scanf("%d%d%d", &m, &n, &q);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        tag[temp] = true;
        a[i] = temp;
    }
    vector<int> temp;
    for (int i = 1; i <= m; i++)
    {
        if (tag[i] && !temp.empty())
        {
            range.push_back(Node(temp.size(), temp));
            temp.clear(); continue;
        }
        temp.push_back(i);
    }
    if (!temp.empty())
    {
        range.push_back(Node(temp.size(), temp));
        temp.clear();
    }
    int last = n;
    for (int i = 1; i <= q; i++)
    {
        int ti;
        scanf("%d", &ti);
        if (ti <= n) { ans = a[ti]; goto out; }
        for (int i = last + 1; i <= ti; i++) solve();
        last = ti;
        out: printf("%d\n", ans); 
    }
    return 0;
}