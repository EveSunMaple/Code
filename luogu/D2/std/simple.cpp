#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct atom{
	int l,r;
}b[210000];
int n,m,pd[101000],len;
int compare(atom k1,atom k2){
	return k1.r<k2.r;
}
int main(){
	// freopen("simple.in","r",stdin);
	// freopen("simple.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(pd,0x00,sizeof pd); len=0;
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); if (k1>k2) swap(k1,k2);
		if (k2==k1+1&&pd[k1]==0){pd[k1]=1; continue;}
		len++; b[len]=(atom){k1,k2};
	}
	sort(b+1,b+len+1,compare); int r=0,ans=n-1;
	for (int i=1;i<=len;i++)
		if (b[i].l>=r){ans++; r=b[i].r;}
	cout<<ans<<endl; return 0;
}
	
