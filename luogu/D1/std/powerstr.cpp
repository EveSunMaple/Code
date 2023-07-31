/*
题意：给定一个长度不超过N(N <= 106)的字符串，它一定是某个串重复K次得到，求这个K的最大值。
题解：假设子串T重复K次后得到串S，那么T的长度一定为L = N/K(要整除)，则T = S[1...L]，将S拆分成K份，每份长度为L，则有
S[1...L] = S[L+1...2L] = S[2L+1...3L] = ... = S[(K-1)L+1...KL]
由于要保证K最大，势必L要取最小，所以根据Next函数的定义，有Next[KL] = (K-1)L;
即Next[N] = N - L，所以L = N - Next[N];
但是得出的长度L还要保证能被N整除，所以如果不能整除说明L = N，即K = 1；而如果能整除，那么K = N / (N - Next[N]);
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[1000005];
int _next[1000005],len;
void getnext(){
    int i=0,j=-1;
    _next[0]=-1;
    while(i<len){
        if(j==-1 || a[i]==a[j]){
            i++,j++;
            _next[i]=j;
        }else j=_next[j];
    }
}
int main(){
    freopen("powerstr.in","r",stdin);
    freopen("powerstr.out","w",stdout);
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",a);
        //if(a[0]=='.') break;
        len=strlen(a);
        getnext();
        int pos=_next[len];
        if(len%(len-pos)!=0) printf("1\n");
        else printf("%d\n", len/(len-pos));
    }
    return 0;
}
