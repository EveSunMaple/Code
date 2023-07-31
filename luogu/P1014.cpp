#include <iostream>

using namespace std; 

int main() 
{
	int n, m = 1;
	cin >> n;

	for(; n > m;) 
    {
		n = n - m;
		m++;
	}
	if(m % 2 == 0) 
        cout << n << "/" << ( m + 1 - n );
	else 
        cout << m + 1 - n << "/" << n;

	return 0;
} 