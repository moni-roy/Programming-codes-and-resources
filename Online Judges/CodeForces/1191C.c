#include <stdio.h>
long long n,m,k,p[100010];
void Main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i = 0;i<m;i++) scanf("%lld",p+i);
    long long dis = 0,deleted=0,Ans= 0;
    while(dis<m){
        long long page = ((p[dis]-deleted-1)/k + 1)*k+deleted;
        while(dis<m && p[dis]<=page){
            dis++;
            deleted++;
        }
        Ans++;
    }
    printf("%lld\n",Ans);
    return;
}
int main(){
    Main();
    return 0;
}