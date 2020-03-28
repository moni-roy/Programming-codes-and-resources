#include <stdio.h>
#define MX 50009
int max(int x,int y){return (x>y)?x:y;}
int n,a[MX],l,r,q,log[MX],K=16;
void init(){
    log[1] = 0;
    for (int i = 2; i < MX; i++)
        log[i] = log[i/2] + 1;
}
int st[MX][18];
void SparseTable(){
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}
int go(int L,int R){
    int j = log[R - L + 1];
    int maximum = max(st[L][j], st[R - (1 << j) + 1][j]);
    return maximum;
}
void swap(int *x,int *y){
    int c = *x;
    *x = *y;
    *y = c;
}
void Main(){
    init();
    scanf("%d%d",&n,&q);
    for(int i = 0;i<n;i++) scanf("%d",a+i);
    SparseTable();
    int Ans = 0;
    while(q--){
        scanf("%d%d",&l,&r);
        l--;
        r--;
        if(l>r) swap(&l,&r);
        Ans += (go(l,r-1)<=a[l]);
    }
    printf("%d\n",Ans);
    return;
}
int main(){
    Main();
    return 0;
}
