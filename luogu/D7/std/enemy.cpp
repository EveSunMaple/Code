#include<cstdio>

typedef long long LL;

int main(){
    freopen("enemy.in","r",stdin);
    freopen("enemy.out","w",stdout);
    int a,b;
    scanf("%d %d",&a,&b);
    int m=0,n=1,m1=1,n1=0,m2=1,n2=1;
    while(1LL*a*n2!=1LL*b*m2){
        
        if(1LL*a*n2<1LL*b*m2){
            printf("L");
            m1=m2;n1=n2;
        }else{
            printf("R");
            m=m2;n=n2;
        }
        m2=m+m1,n2=n+n1;
    }
    printf("\n");
    fclose(stdin);fclose(stdout);
    return 0;
}
