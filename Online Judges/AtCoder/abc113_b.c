#include <stdio.h>
double fabs(double a){return (a<0)?-a:a;}
double a,t,h;
int n;
void Main(){
    scanf("%d",&n);
    scanf("%lf%lf",&t,&a);
    double d = 1e10;
    int Ans = 0;
    for(int i = 1;i<=n;i++){
        scanf("%lf",&h);
        double tp = t-(h*0.006);
        if(d>fabs(a-tp)){
            Ans = i;
            d = fabs(a-tp);
        }
    }
    printf("%d\n",Ans);
}
int main(){
    Main();
    return 0;
}
