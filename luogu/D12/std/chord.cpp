#include <bits/stdc++.h>

using namespace std;

const int N = 1010;


int T,n,m,a[N],b[N];
int last[N],nxt[N];
int main(){
	freopen("chord.in","r",stdin);
	freopen("chord.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		bool flag = 1;
		scanf("%d%d",&n,&m);
		memset(last,0,sizeof(last));
		memset(nxt,0,sizeof(nxt));
		
		for (int i = 1;i <= n;i++) {
			scanf("%d",&a[i]); 
			last[a[i]] = n+1;
		}
		for (int i = n;i >= 1;i--){
			nxt[i] = last[a[i]];
			last[a[i]] = i;
		}
		
		for (int i = 1;i <= n;i++) {
			scanf("%d",&b[i]);
			a[last[b[i]]] = i;
			last[b[i]] = nxt[last[b[i]]]; 
		}
		for (int i = 1;i <= n;i++)
			if (last[b[i]] != n+1) flag = 0; 
		for (int i = 1;i <= m;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			sort(a+l,a+r+1);
		}
		for (int i = 1;i <= n;i++) 
			if (a[i] != i) flag = 0;
		if (flag) printf("TAK\n");
		else printf("NIE\n");
	}
	return 0;
}
