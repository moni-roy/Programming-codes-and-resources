#include <stdio.h>
int N,A[1001],LCM;
int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
void MRoy(){
    scanf("%d",&N);
    for(int i = 0;i<N;i++) {
        scanf("%d",A+i);
        if(i == 0) LCM = A[i];
        LCM = lcm(LCM, A[i]);
    }
    double SUM = 0;
    for(int i = 0;i<N;i++){
        SUM += (LCM/A[i]);
    }
    printf("%.10lf\n",(1.0*LCM/SUM));
}
int main(){
    MRoy();
    return 0;
}