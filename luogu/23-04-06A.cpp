#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

//char ans[4];
//n == 110; 0 == 48;
string name[1100];
int num[1100];
int turl = 1;
bool err = 0;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    
    for(; ch < '0' || ch > '9';)
    {
        if(ch == '-')
            f = -1;
        if(ch == 'n')
            return 1e9;
        ch = getchar();
    }
    
    for(; ch >= '0' && ch <= '9';)
    {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	
    return x * f;
}

void sp(int n)
{
	for(int i = 1; i <= n; i++)
	{
		char a;
		cin >> a;
		if(a == 'F')
		{
			cin >> a;
			cin >> a;
			cin >> a;
			continue;
		} 
		else
			continue;
	}
}

string coding(int cnt, string ans, int lim, int n_cnt)
{
    //cout << "cnt" << cnt << endl;
    //cout << "lim" << lim << endl;
    //cout << "turl" << turl << endl;
    char ju;
    scanf("%s", &ju);
    
    if(ju == 'F')
    {
	    int start;
    	cin >> name[cnt];
    	start = read();
    	num[cnt] = read();
    	//cout << "变量名： " << name[cnt];
        //printf("初始化：%d 阈值：%d\n", start, num[cnt]);
        
        for(int i = 1; i <= cnt; i++)
        {
        	if(name[cnt] == name[i] && i != cnt)
        		err = 1;
		}
        
        if(num[cnt] == 1e9)
        {
        	n_cnt++;
            ans.assign("O(n^");
            ans.append(to_string(n_cnt));
        }

        if(turl + 1 <= lim)
        {
        	string now = ans;
        	if(cnt + 1 <= lim / 2 && turl + 1 <= lim)
        	{
        		turl++;
            	ans = coding(cnt + 1, ans, lim, n_cnt);
			}
        	if(ans == "O" && turl + 1 <= lim)
        	{
        		ans = now;
        		turl++;
        		if(n_cnt > 0)
        			n_cnt--;
            	ans = coding(cnt, ans, lim, n_cnt);
			}
			else if(ans[2] != 'n' && now[2] == 'n') 
				ans = now; 
		}
		if(turl >= lim)
			return ans;
		
        if(start > num[cnt])
        {
            ans.assign("O(");
		}
    }
    else if(ju == 'E' && cnt != 1)
    {
        return "O";
    }
    else
    {
        err = 1;
    }
    
    //cout << ans;
    scanf("%s", &ju);
    if(ju == 'E')
        return ans;

    return 0;
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
    	err = 0;
    	turl = 1;
        int t;
        string com;
        scanf("%d", &t);
        cin >> com;
        if(t % 2 == 1)
        {
        	sp(t);
            printf("ERR\n");
            continue;
        }
        else
        {
            string ans = coding(1, "O(", t, 0);
            if(ans[ans.size() - 1] == '^' || ans[ans.size() - 1] == '(')
            	ans.append("1");
            ans.append(")");
            //cout << "答案：" << ans << endl; 
            if(err)
            {
                printf("ERR\n");
            	continue;
			}
            
            if(com == ans)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}