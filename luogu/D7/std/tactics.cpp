#include<cstdio>
#include<cctype>

int read(){
    int w=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())w=w*10+(ch^48);
    return w*f;
}
int max(int x,int y){return x>y?x:y;}

const int N=105;

int T,n,dis[N],w[N][N];

int main(){
    freopen("tactics.in","r",stdin);
    freopen("tactics.out","w",stdout);
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;++i)dis[i]=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)w[i][j]=read();
        for(int t=1;t<=n;++t)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)dis[j]=max(dis[j],dis[i]+w[i][j]);
        int flag=1;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)if(dis[j]<dis[i]+w[i][j])flag=0;
        if(flag){
            int ans=0;
            for(int i=1;i<=n;++i)if(dis[i]>ans)ans=dis[i];
            printf("%d\n",ans);
        }else printf("-1\n");
    }
    fclose(stdin);fclose(stdout);
    return 0;
}