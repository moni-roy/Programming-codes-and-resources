#include <stdio.h>
#define MXSIZE 200010
int n,a[MXSIZE],pr[MXSIZE],pay[MXSIZE],q,c,x,p;
void Main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++) scanf("%d",a+i);
    scanf("%d",&q);
    for(int i = 1;i<=q;i++){
        scanf("%d",&c);
        if(c==1){
            scanf("%d %d",&p,&x);
            a[p] = x;
            pr[p] = i;
        }
        else scanf("%d",pay+i);
    }
    for(int i = q;i>=1;i--){
        pay[i] = (pay[i]>pay[i+1])?pay[i]:pay[i+1];
    }
    for(int i = 1;i<=n;i++){
        if(a[i]<pay[pr[i]+1]) a[i] = pay[pr[i]+1];
    }
    for(int i = 1;i<=n;i++) printf("%d ",a[i]);
}
int main(){
    Main();
    return 0;
}