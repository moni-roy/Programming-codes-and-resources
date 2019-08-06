#include <stdio.h>
int digit(int n){
    int ret = 0;
    while (n>0)
    {
        n/=10;
        ret++;
    }
    return ret;
}
int main(){
    int n,Ans = 0;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        if(digit(i)&1) Ans++;
    }
    printf("%d\n",Ans);
    return 0;
}