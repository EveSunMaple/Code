#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;
const int maxn=3E5+5;
int n,m;
int state[maxn*2];
namespace IO
{
    const int len=1<<10;
    bool flag;
    char ch,ibuf[len],wbuf[len];
    int il=len,wl=0,g,G[55];
    inline void in()
    {
        int x=fread(ibuf,1,len,stdin);
        il=0;
    }
    inline void out()
    {
        int x=fwrite(wbuf,1,wl,stdout);
        wl=0;
    }
    inline void gc(char&c)
    {
        if(il==len)
            in();
        c=ibuf[il++];
    }
    inline void wc(char c)
    {
        if(wl==len)
            out();
        wbuf[wl++]=c;
    }
    template<typename T>void read(T&x)
    {
        flag=0;gc(ch);
        if(ch=='-')flag=1;
        while(!isdigit(ch)){if(ch=='-')flag=1;gc(ch);}
        x=ch-'0';gc(ch);
        while(isdigit(ch)){x=x*10+ch-'0';gc(ch);}
        x=flag?-x:x;
    }
    template<typename T>void write(T x)
    {
        if(x<0)wc('-'),x=-x;
        g=0;
        do{G[++g]=x%10;x/=10;}while(x);
        for(int i=g;i>=1;--i)wc(G[i]+'0');
        wc('\n');
    }
}
struct query
{
	int x,y,id;
}Q[maxn];
struct matrix
{
	ll a[4][4];
	inline matrix operator*(const matrix&A)const
	{
		matrix B;
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j)
				B.a[i][j]=(a[i][0]*A.a[0][j]+a[i][1]*A.a[1][j]+a[i][2]*A.a[2][j]+a[i][3]*A.a[3][j])%mod;
		return B;
	}
	void out()
	{
		for(int i=0;i<4;++i,cout<<endl)
			for(int j=0;j<4;++j)
				cout<<a[i][j]<<" ";cout<<endl;
	}
}pre[maxn*2];
namespace SEGMENT
{
	int len;
	matrix t[maxn*4*2];// M1:same M2:not same
	inline void update(int num)
	{
		t[num]=t[num<<1]*t[num<<1|1];
	}
	void change(int l,int r,int pos,int num,const matrix&A)
	{
		if(l==r)
		{
			t[num]=A;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid)
			change(l,mid,pos,num<<1,A);
		else
			change(mid+1,r,pos,num<<1|1,A);
		update(num);
	}
	matrix ask(int L,int R,int l,int r,int num)
	{
		if(L<=l&&r<=R)
			return t[num];
		int mid=(l+r)>>1;
		if(R<=mid)
			return ask(L,R,l,mid,num<<1);
		else if(mid<L)
			return ask(L,R,mid+1,r,num<<1|1);
		return ask(L,R,l,mid,num<<1)*ask(L,R,mid+1,r,num<<1|1);
	}
	void build(int l,int r,int num)
	{
		if(l==r)
		{
			t[num]=pre[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);
		build(mid+1,r,num<<1|1);
		update(num);
	}
	void init(int L)
	{
		build(1,L,1);
	}
	void pointOut(int l,int r,int pos,int num)
	{
		if(l==r)
		{
			cout<<"POS "<<pos<<endl;
			t[num].out();
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid)
			pointOut(l,mid,pos,num<<1);
		else
			pointOut(mid+1,r,pos,num<<1|1);
	}
}
namespace TREE
{
	int root;
	int D[maxn*2],son[maxn*2][2],fa[maxn*2],dep[maxn*2],back[maxn*2];
	int heavySon[maxn*2],sum[maxn*2],top[maxn*2],dfn[maxn*2],L[maxn*2],R[maxn*2],down[maxn*2];
	int leftMost[maxn*2],rightMost[maxn*2];
	int num[maxn*2],tot;// tot : number of nodes in the tree
	vector<int>wait[maxn];
	inline void push(int u,int fa)
	{
		wait[fa].push_back(u);
		if(leftMost[fa]==0)
			leftMost[fa]=u;
		rightMost[fa]=u;
	}
	void build(int R)
	{
		root=R;
		tot=m;
		for(int u=0;u<=m;++u)
		{
			if(wait[u].size()==0)
				D[u]=0;
			else if(wait[u].size()==1)
				son[u][0]=wait[u][0],D[u]=1;
			else
			{
				D[u]=1;
				son[u][0]=tot+1;
				for(int i=2;i<wait[u].size();++i)
					son[tot+i/2][i%2]=tot+i;
				int pos=0;
				int bg=1;
				while(bg*2<=wait[u].size())
					bg*=2;
				for(int i=bg;i<wait[u].size();++i)
				{
					D[tot+i]=2;
					int vL=i*2,vR=i*2+1;
					if(vL>=wait[u].size())
						son[tot+i][0]=wait[u][pos++];
					if(vR>=wait[u].size())
						son[tot+i][1]=wait[u][pos++];
					assert(pos<=wait[u].size());
				}
				for(int i=1;i<bg;++i)
				{
					D[tot+i]=2;
					int vL=i*2,vR=i*2+1;
					if(vL>=wait[u].size())
						son[tot+i][0]=wait[u][pos++];
					if(vR>=wait[u].size())
						son[tot+i][1]=wait[u][pos++];
					assert(pos<=wait[u].size());
				}
				tot+=wait[u].size()-1;
			}
		}
	}
	void dfs0(int u,int F,int d)
	{
		sum[u]=1;
		dep[u]=d;
		fa[u]=F;
		heavySon[u]=-1;
		for(int i=0;i<D[u];++i)
		{
			dfs0(son[u][i],u,d+1);
			sum[u]+=sum[son[u][i]];
			if(heavySon[u]==-1||sum[son[u][i]]>sum[heavySon[u]]) // !!!!!!!
				heavySon[u]=son[u][i];
		}
	}
	int TI=0;
	void dfs1(int u,int F)
	{
		dfn[u]=++TI;
		L[u]=R[u]=TI;
		back[TI]=u;
		if(heavySon[F]!=u)// correct for node 0
			top[u]=u;
		else
			top[u]=top[F];
		if(heavySon[u]==-1)
		{
			down[u]=u;
			goto end;
		}
		else
		{
			dfs1(heavySon[u],u);
			R[u]=R[heavySon[u]];
			down[u]=down[heavySon[u]];
		}
		for(int i=0;i<D[u];++i)
		{
			if(son[u][i]==heavySon[u])
				continue;
			dfs1(son[u][i],u);
			R[u]=R[son[u][i]];
		}
		if(u>m)
		{
			if(son[u][0]<=m)
				leftMost[u]=son[u][0];
			else
				leftMost[u]=leftMost[son[u][0]];
			if(son[u][1]<=m)
				rightMost[u]=son[u][1];
			else
				rightMost[u]=rightMost[son[u][1]];
		}
		end:;
		int d=dfn[u];
		if(u<=m)
		{
			int x=leftMost[u];
			int y=rightMost[u];
			if(heavySon[u]==-1)
				x=y=u;
			memset(pre[d].a,0,sizeof(pre[d].a));
			if((Q[x].x-Q[u].x)%2==0&&(Q[u].y-Q[y].y)%2==0)
			{
				pre[d].a[0][0]=pre[d].a[1][1]=pre[d].a[2][2]=pre[d].a[3][3]=1;
				state[u]=0;
			}
			else if((Q[x].x-Q[u].x)%2==0&&(Q[u].y-Q[y].y)%2==1)
			{ 
				pre[d].a[0][1]=pre[d].a[1][0]=pre[d].a[2][3]=pre[d].a[3][2]=1;
				state[u]=1;
			}
			else if((Q[x].x-Q[u].x)%2==1&&(Q[u].y-Q[y].y)%2==0)
			{
				pre[d].a[0][2]=pre[d].a[1][3]=pre[d].a[2][0]=pre[d].a[3][1]=1;
				state[u]=2;
			}
			else
			{
				pre[d].a[0][3]=pre[d].a[1][2]=pre[d].a[2][1]=pre[d].a[3][0]=1;
				state[u]=3;
			}
		}
		else
		{
			assert(D[u]==2);
			int x=rightMost[son[u][0]];
			int y=leftMost[son[u][1]];
			if(son[u][0]<=m)
				x=son[u][0];
			if(son[u][1]<=m)// NOT SAME !!!!!!!
				y=son[u][1];
//			cout<<"? "<<u<<" "<<x<<" "<<y<<" "<<Q[y].x<<" "<<Q[x].y<<endl;
			assert(Q[x].y<Q[y].x);
			if((Q[y].x-Q[x].y)%2==1)
			{
				if(son[u][0]==heavySon[u])
				{
					int len=Q[rightMost[son[u][1]]].y-Q[leftMost[son[u][1]]].x;
					if(son[u][1]<=m)
						len=Q[son[u][1]].y-Q[son[u][1]].x;
					pre[d].a[0][0]=pre[d].a[2][2]=len&1;
					pre[d].a[1][1]=pre[d].a[3][3]=len&1;
					pre[d].a[0][1]=pre[d].a[2][3]=(len&1)^1;
					pre[d].a[1][0]=pre[d].a[3][2]=(len&1)^1;
				}
				else
				{
					int len=Q[rightMost[son[u][0]]].y-Q[leftMost[son[u][0]]].x;
					if(son[u][0]<=m)
						len=Q[son[u][0]].y-Q[son[u][0]].x;
					pre[d].a[0][0]=pre[d].a[1][1]=len&1;
					pre[d].a[2][2]=pre[d].a[3][3]=len&1;
					pre[d].a[0][2]=pre[d].a[1][3]=(len&1)^1;
					pre[d].a[2][0]=pre[d].a[3][1]=(len&1)^1;
				}
			}
			else
			{
				if(son[u][0]==heavySon[u])
				{
					int len=Q[rightMost[son[u][1]]].y-Q[leftMost[son[u][1]]].x;
					if(son[u][1]<=m)
						len=Q[son[u][1]].y-Q[son[u][1]].x;
					pre[d].a[0][1]=pre[d].a[2][3]=len&1;
					pre[d].a[1][0]=pre[d].a[3][2]=len&1;
					pre[d].a[0][0]=pre[d].a[2][2]=(len&1)^1;
					pre[d].a[1][1]=pre[d].a[3][3]=(len&1)^1;
				}
				else
				{
					int len=Q[rightMost[son[u][0]]].y-Q[leftMost[son[u][0]]].x;
					if(son[u][0]<=m)
						len=Q[son[u][0]].y-Q[son[u][0]].x;
					pre[d].a[0][2]=pre[d].a[1][3]=len&1;
					pre[d].a[2][0]=pre[d].a[3][1]=len&1;
					pre[d].a[0][0]=pre[d].a[1][1]=(len&1)^1;
					pre[d].a[2][2]=pre[d].a[3][3]=(len&1)^1;
				}
			}
		}
	}
	void init()
	{
		dfs0(root,root,0);
		dfs1(root,root);
		assert(TI==R[root]);
		SEGMENT::init(TI);
	}
	inline matrix askChain(int u)
	{
		return SEGMENT::ask(dfn[top[u]],dfn[down[u]],1,TI,1);
	}
	inline void changeChain(int u,const matrix&M)
	{
		SEGMENT::change(1,TI,dfn[u],1,M);
		while(top[u]!=root)
		{
			int up=top[u];
			int F=fa[up];
			matrix A=askChain(u),B;
			
			ll _00=A.a[0][0]+A.a[0][3],_01=A.a[1][0]+A.a[1][3],_10=A.a[2][0]+A.a[2][3],_11=A.a[3][0]+A.a[3][3];
			_00%=mod;
			_01%=mod;
			_10%=mod;
			_11%=mod; 
			memset(B.a,0,sizeof(B));
			
			int x=rightMost[son[F][0]];
			int y=leftMost[son[F][1]];
			if(son[F][0]<=m)
				x=son[F][0];
			if(son[F][1]<=m)// be careful !
				y=son[F][1];
			if((Q[y].x-Q[x].y)&1)
			{
				if(son[F][0]==heavySon[F])
				{
					B.a[0][0]=B.a[2][2]=_00;
					B.a[1][1]=B.a[3][3]=_11;
					B.a[0][1]=B.a[2][3]=_10;
					B.a[1][0]=B.a[3][2]=_01;
				}
				else
				{
					B.a[0][0]=B.a[1][1]=_00;
					B.a[2][2]=B.a[3][3]=_11;
					B.a[0][2]=B.a[1][3]=_01;
					B.a[2][0]=B.a[3][1]=_10;
				}
			}
			else
			{
				if(son[F][0]==heavySon[F])
				{
					B.a[0][1]=B.a[2][3]=_00;
					B.a[1][0]=B.a[3][2]=_11;
					B.a[0][0]=B.a[2][2]=_10;
					B.a[1][1]=B.a[3][3]=_01;
				}
				else
				{
					B.a[0][2]=B.a[1][3]=_00;
					B.a[2][0]=B.a[3][1]=_11;
					B.a[0][0]=B.a[1][1]=_01;
					B.a[2][2]=B.a[3][3]=_10;
				}
			}
			SEGMENT::change(1,TI,dfn[F],1,B);
			u=F;
		}
	}
	inline void addEdge(int id)
	{
		matrix M;
		memset(M.a,0,sizeof(M.a));
		if(state[id]==0)
			M.a[0][0]=M.a[1][1]=M.a[2][2]=M.a[3][3]=M.a[3][0]=1;
		else if(state[id]==1)
			M.a[0][1]=M.a[1][0]=M.a[2][3]=M.a[3][2]=M.a[3][1]=1;
		else if(state[id]==2)
			M.a[0][2]=M.a[1][3]=M.a[2][0]=M.a[3][1]=M.a[3][2]=1;
		else
			M.a[0][3]=M.a[1][2]=M.a[2][1]=M.a[3][0]=M.a[3][3]=1;
			
		changeChain(id,M);
	}
	void out()
	{
		cout<<tot<<" "<<root<<endl;
		for(int i=0;i<=tot;++i)
			if(1)
				cout<<i<<" : "<<D[i]<<" "<<son[i][0]<<" "<<son[i][1]<<" "<<sum[i]<<" "<<heavySon[i]<<" "<<top[i]<<" "<<down[i]<<" "<<dfn[i]<<endl;
	}
}
struct pt
{
	int x,id,type;
	bool operator<(const pt&A)const
	{
		return x<A.x;
	}
};
int bucket[maxn];
void build()
{
	vector<pt>A;
	Q[0].x=0,Q[0].y=n+1;
	for(int i=0;i<=m;++i)
	{
		if((Q[i].y-Q[i].x)%2==0)
			continue;
		A.push_back((pt){Q[i].x,i,1}),A.push_back((pt){Q[i].y,i,0});
	}
	sort(A.begin(),A.end());
	int top=0;
	int g=0;
	for(int i=0;i<A.size();++i)
	{
		int id=A[i].id;
		if(A[i].type==1)
		{
			bucket[++top]=id;
			if(top!=1)
				TREE::push(id,bucket[top-1]);
		}
		else
			--top;
		g=max(g,top);
	}
	TREE::build(0);
	TREE::init();
}
map<int,bool>vis;
int main()
{
	freopen("qiqi.in","r",stdin);
	freopen("qiqi.out","w",stdout);
	ios::sync_with_stdio(false);
	IO::in();
	IO::read(n);
	assert(n%2==0);
	IO::read(m); 
	for(int i=1;i<=m;++i)
	{
		IO::read(Q[i].x);
		IO::read(Q[i].y);
		assert(vis[Q[i].x]==0);
		assert(vis[Q[i].y]==0);
		vis[Q[i].x]=vis[Q[i].y]=1;
		if(Q[i].x>Q[i].y)
			swap(Q[i].x,Q[i].y);
		if(abs(Q[i].x-Q[i].y)<=1||Q[i].x==1&&Q[i].y==n)
			assert(0);
		Q[i].id=i;
	}
	build();
	ll ans=2;
	for(int i=1;i<=m;++i)
	{
		if((Q[i].y-Q[i].x)%2==1)
		{
			TREE::addEdge(i);
			matrix M=TREE::askChain(0);
			ans=(M.a[0][0]+M.a[0][3]+M.a[1][0]+M.a[1][3]+M.a[2][0]+M.a[2][3]+M.a[3][0]+M.a[3][3])%mod;
		}
		ans=(ans%mod+mod)%mod;
		IO::write(ans);
	}
//	cerr<<TREE::TI<<endl;
	IO::out();
	return 0;
}
/*
12 3
3 12
8 11
4 7

12 3
4 1
5 8
9 12

24 6
1 4
11 14
21 18
15 22
5 10
6 9
*/

