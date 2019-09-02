#include <stdio.h>
void MRoy(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    if((a+b)&1) printf("IMPOSSIBLE\n");
    else printf("%lld\n",(a+b)/2);
    return;
}
int main(){
    MRoy();
    return 0;
}