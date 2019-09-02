#include <stdio.h>
#define SZ 100010
long long min(long long a,long long b){return (a<b)?a:b;}
void MRoy(){
    long long n,a[SZ],b[SZ];
    scanf("%lld",&n);
    for(long long i = 0;i<=n;i++){
        scanf("%lld",a+i);
    }
    for(long long i = 0;i<n;i++){
        scanf("%lld",b+i);
    }
    long long Ans = 0;
    for(long long i = 0;i<n;i++){
        long long t = min(a[i],b[i]);
        Ans += t;
        b[i]-=t;
        t = min(a[i+1],b[i]);
        Ans += t;
        a[i+1]-=t;
    }
    printf("%lld\n",Ans);
    return;
}
int main(){
    MRoy();
    return 0;
}