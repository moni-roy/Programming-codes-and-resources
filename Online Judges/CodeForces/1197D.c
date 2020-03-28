#include <stdio.h>
long long int Max(long long a, long long int b){ return (a>b)?a:b;}
int n,m,k,a[300020];
long long precal[300020],best[300020];

long long Values(int l,int r){
    return (precal[r]- ((l<=0)?0:precal[l-1]));
}
void Main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0;i<n;i++){
        scanf("%d",a+i);
        precal[i] = a[i] + ((i==0)?0:precal[i-1]);
    }
    long long Ans = 0;
    for(int i = 1;i<=m && i<=n;i++){
        Ans = Max(Ans,Values(0,i-1)-k);
    }
    for(int i = 0;i<n;i++){
        if(i+1>=m){
            long long temp = Values(i-m+1,i)-k;
            if(i-m>=0) temp+=best[i-m];
            best[i] = Max(best[i],temp);
        }
        for(int j = 0;j<m && j+i<n;j++){
            Ans = Max(Ans, best[i]+Values(i+1,i+j)-k*(j>0));
        }
    }
    printf("%lld\n",Ans);
    return;
}
int main(){
    Main();
    return 0;
}