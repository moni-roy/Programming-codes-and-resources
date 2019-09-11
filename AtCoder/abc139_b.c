#include <stdio.h>
void MRoy(){
    int a,b,Ans = 0;
    scanf("%d %d",&a,&b);
    if(b==1) {
        printf("0\n");
        return;
    }
    Ans = 1;
    int n = a;
    while(n<b){
        n+=a-1;
        Ans++;
    }
    printf("%d\n",Ans);
}
int main(){
    MRoy();
    return 0;
}