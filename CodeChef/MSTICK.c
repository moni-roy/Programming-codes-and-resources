#include <stdio.h>
#define MX 100009
int max(int x,int y){return (x>y)?x:y;}
int min(int x,int y){return (x<y)?x:y;}
int n,q,a[MX],st[2][MX][20],log[MX],K=16;
void sparseTable(){
    log[1] = 0 ;
    for(int i = 2;i<MX;i++) log[i] = log[i/2]+1;
    for(int i = 0;i<n;i++){
        st[0][i][0] = st[1][i][0] = a[i];
    }
    for(int j = 1;j<=K;j++){
        for(int i = 0;i + (1<<j)<=n;i++){
            st[0][i][j] = min(st[0][i][j-1],st[0][i+(1<<(j-1))][j-1]);
            st[1][i][j] = max(st[1][i][j-1],st[1][i+(1<<(j-1))][j-1]);
        }
    }
}
int goMin(int L,int R){
    int j = log[R-L+1];
    return min(st[0][L][j], st[0][R-(1<<j)+1][j]);
}
int goMax(int L,int R){
    int j = log[R-L+1];
    return max(st[1][L][j], st[1][R-(1<<j)+1][j]);
}
void Main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++) scanf("%d",a+i);
    sparseTable();
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        int mn = goMin(l,r);
        int mx = goMax(l,r);
        double Ans = mn + (mx-mn)/2.0+0.0;
        mx  = 0;
        if(l>0) mx = goMax(0,l-1);
        Ans = (Ans>(mn+mx))?Ans:mn+mx;
        if(r<n-1) mx = goMax(r+1,n-1);
        Ans = (Ans>(mn+mx))?Ans:mn+mx;
        printf("%0.1lf\n",Ans);
    }
    return;
}
int main(){
    Main();
    return 0;
}
