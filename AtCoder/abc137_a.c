#include <stdio.h>
int max(int a,int b){ return (a<b)?b:a;}
void MRoy(){
    int a,b;
    scanf("%d%d",&a,&b);
    int Ans = a+b;
    Ans = max(Ans, a-b);
    Ans = max(Ans,a*b);
    printf("%d\n",Ans);
}
int main(){
    MRoy();
    return 0;
}