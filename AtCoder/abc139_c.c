#include <stdio.h>
int n,a[110001];
void MRoy(){
    scanf("%d",&n);
    for (register int i = 0; i < n; i++){
        scanf("%d",a+i);
    }
    int Ans = 0, cnt = 0;
    for(register int i=n-2;i>=0;i--){
        if(a[i]>=a[i+1]) cnt++;
        else cnt = 0;
        Ans = Ans<cnt?cnt:Ans;
    }
    printf("%d\n",Ans);
}
int main(){
    MRoy();
    return 0;
}