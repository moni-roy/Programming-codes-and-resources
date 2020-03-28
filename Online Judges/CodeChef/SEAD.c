#include <stdio.h>
#define MX 100009
int n,a[MX],q,t,d,st[MX][22],K = 17,log[MX];
int findLast(){
    int l = 1,r = n-1,ret = 0;
    while (l<=r)
    {
        int m = (l+r)>>1;
        if(a[m]<=t) {
            ret = m;
            l = m+1;
        }
        else r = m-1;
    }
    return ret;
}
int Max(int x,int y){return (x>y)?x:y;}
int findMax(int L,int R){
    int j = log[R-L+1];
    return Max(st[L][j],st[R-(1<<j)+1][j]);
}
int findMin(){
    int r = findLast();
    int l = 0, ret = r, R = r-1;
    r = r-1;
    while(l<=r){
        int m = (l+r)>>1;
        if(findMax(m,R)<=d) {
            ret  = m;
            r = m-1; 
        }
        else l = m+1;
    }
    return ret;
}
void sparseTable(){
    log[1] = 0;
    for(int i = 0;i<n-1;i++){
        st[i][0] = a[i+1]-a[i];
        log[i+2]  = log[(i+2)/2]+1;
    }
    for(int j = 1;j<=K;j++){
        for(int i = 0; i+(1<<j)<=n-1;i++){
            st[i][j] = Max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}
void Main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++) scanf("%d",a+i);
    sparseTable();
    scanf("%d",&q);
    while (q--){
        scanf("%d%d",&t,&d);
        printf("%d\n",findMin()+1);
    }
    return;
}
int main(){
    Main();
    return 0;
}
