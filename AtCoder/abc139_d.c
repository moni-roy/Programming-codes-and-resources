#include <stdio.h>
long long int n;
void MRoy(){
    scanf("%lld",&n);
    long long int Ans = n*(n-1)/2;
    printf("%lld\n",Ans);
}
int main(){
    MRoy();
    return 0;
}