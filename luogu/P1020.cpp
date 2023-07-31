#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAX 100005
#define INF 1e9

using namespace std;

int A[MAX]; //存数字
int G[MAX];	//我们亲爱的G数组
int tot = 1;

int main()
{
	int N = 0; //长度 
	while(~scanf("%d",&A[++N])); --N;

	G[1] = A[1]; //我们开始的起点

	for(int i = 2; i <= N; i++)
	{
		if(A[i] <= G[tot]) //只要能插入，就先插入
			G[++tot] = A[i]; //初始化最后一个元素值
		else
		{
	        int l = 1, r = tot, mid;
	        while (l < r)//获得下标，注意这里G数组递减
	        {
	        	//基础二分查找
	        	mid = (l + r) >> 1;
	        	if(G[mid] >= A[i]) l = mid + 1;
	        	else r = mid;
	        }
			G[l] = max(G[l], A[i]); //赋值，加MAX保险
		}
	}

	printf("%d\n", tot); //输出答案一

	//重置数据
	tot = 1;
	memset(G, INF, sizeof(G));
	G[1] = A[1]; 

	for(int i = 2; i <= N; i++)
	{
	    int l = 1, r = tot, mid;
	    while (l < r)//获得下标，当然也可能没有
	    {
	    	//基础二分查找
	    	mid = (l + r) >> 1;
	    	if(G[mid] >= A[i]) r = mid;
	    	else l = mid + 1;
	    }
		if(G[l] >= A[i]) G[l] = A[i]; //如果找得到，赋值
		else G[++tot] = A[i]; //如果找不到，初始化一个新的系统
	}

	printf("%d\n", tot); //输出答案二

	return 0;
}