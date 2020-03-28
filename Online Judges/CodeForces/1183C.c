#include <stdio.h>
long long q,n,k,a,b;
long long ok(long long m){
    return ((m*a+(n-m)*b)<k);
}
void Main(){
    scanf("%lld",&q);
    while (q--){
        scanf("%lld%lld%lld%lld",&k,&n,&a,&b);
        if(n*b>=k) puts("-1");
        else{
            long long l = 0,r = n,Ans=-1;
            while(l<=r){
                long long m = (l+r)>>1;
                if(ok(m)) {
                    Ans = m;
                    l = m+1;
                }
                else r = m-1;
            }
            printf("%lld\n",r);
        }
    }
    return;
}
int main(){
    Main();
    return 0;
}