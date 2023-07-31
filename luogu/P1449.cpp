#include<iostream>
#include<queue>

#define none -100000009 
#define end -100000001 

using namespace std;

deque <int> s; 

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    
    for(; ch < '0' || ch > '9';)
    {
    	int a = 0;
    	int b = 0;
        if(ch == '+')
        {
        	a = s.front();
        	s.pop_front();
        	b = s.front();
        	s.pop_front();
        	s.push_front(b + a);
        	return none;
        }
        if(ch == '-')
        {
        	a = s.front();
        	s.pop_front();
        	b = s.front();
        	s.pop_front();
        	s.push_front(b - a);
        	return none;
        }
        if(ch == '*')
        {
        	a = s.front();
        	s.pop_front();
        	b = s.front();
        	s.pop_front();
        	s.push_front(b * a);
        	return none;
        }
        if(ch == '/')
        {
        	a = s.front();
        	s.pop_front();
        	b = s.front();
        	s.pop_front();
        	s.push_front(b / a);
        	return none;
        }
		if(ch == '@')
			return end;
        ch = getchar();
    }
    
    for(; ch >= '0' && ch <= '9';)
    {
		x = x * 10 + ch - '0';
		ch = getchar();
		if(ch == '.')
    		return x * f;
	}
	
    return x * f;
}

int main()
{
	for(; ;)
	{
		int num = read();
		if(num == end)
		{
			cout << s.front();
			return 0;
		}
		else if(num != end && num != none)
		{
			s.push_front(num);
		}
	}
} 
