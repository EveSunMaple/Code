#include <cstdio>
#include <cstring>

char s[30010];
int i,n,ans,x;

int main()
{
    freopen("agnus.in","r",stdin);
    freopen("agnus.out","w",stdout);
    scanf("%s",s);
    n=strlen(s);
    for (i=0;i+4<n;++i)
        if (s[i]=='a'&&s[i+1]=='g'&&s[i+2]=='n'&&s[i+3]=='u'&&s[i+4]=='s')
            {ans+=(i+1-x)*(n-i-4); x=i+1;}
    printf("%d\n",ans);
    fclose(stdin); fclose(stdout);
    return 0;
}

