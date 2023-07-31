#include<cstdio>
#include<cctype>
#include<vector>
#include<algorithm>

using std::lower_bound;

typedef long long LL;
typedef std::vector<int> vi;

int read(){
    int w=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    for(;isdigit(ch);ch=getchar())w=w*10+(ch^48);
    return w;
}

const int N=100005,M=1<<20;

int T,n,D;
int a[N];
int lc[N],rc[N];
int stk[N],tp;
vi bac[M];
LL ans;

void solve(int w,int l,int r){
    if(w-l<r-w){
        for(int i=l;i<=w;++i){
            int v=D^a[i]^a[w];
            ans+=lower_bound(bac[v].begin(),bac[v].end(),r+1)-lower_bound(bac[v].begin(),bac[v].end(),w);
        }
    }else{
        for(int i=w;i<=r;++i){
            int v=D^a[i]^a[w];
            ans+=lower_bound(bac[v].begin(),bac[v].end(),w+1)-lower_bound(bac[v].begin(),bac[v].end(),l);
        }
    }
    if(lc[w])solve(lc[w],l,w-1);
    if(rc[w])solve(rc[w],w+1,r);
}

int main(){
    freopen("nameplate.in","r",stdin);
    freopen("nameplate.out","w",stdout);
    //T=read();
    //while(T--){
        n=read();D=read();ans=0;
        for(int i=0;i<N;++i)bac[i].clear();
        for(int i=1;i<=n;++i){
            a[i]=read();bac[a[i]].push_back(i);
            if(!tp||a[i]>=a[stk[tp]])stk[++tp]=i;
            else{
                for(;tp&&a[i]<a[stk[tp]];--tp)rc[stk[tp-1]]=stk[tp];
                lc[i]=stk[tp+1];stk[++tp]=i;
            }
        }
        for(;tp;--tp)rc[stk[tp-1]]=stk[tp];

        solve(rc[0],1,n);
        printf("%lld\n",ans);
    //}
    fclose(stdin);fclose(stdout);
    return 0;
}