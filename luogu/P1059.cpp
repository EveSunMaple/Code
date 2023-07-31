#include<iostream>

using namespace std;

int M[10001];
int main()
{
    int N;
    cin>>N;
    for(int i = 0; i < N; i++)
    {
    	cin>>M[i];
	}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if(M[i] == M[j] && i != j)
			{
				for(int l = j; l < N; l++)
					M[l] = M[l + 1];
				N--;
			}
	for(;;)
	{
		bool re = true;
		for(int i = 0; i < N; i++)
			if(M[i] > M[i + 1] && M[i + 1] != 0)
			{
				int v = M[i];
				M[i] = M[i + 1];
				M[i + 1] = v;
				re = false;
			}
		if(re)
			break;
	}
	cout<<N<<endl;
	for(int i = 0; i < N; i++)
	{
		cout<<M[i]<<' ';
	}
    return 0;
}
