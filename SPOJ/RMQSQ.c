#include <stdio.h>
#define MX 100009
int min(int x,int y){return (x<y)?x:y;}
int n,a[MX],l,r,q,log[MX],K=17;
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
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}
int go(int L,int R){
    int j = log[R - L + 1];
    int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
    return minimum;
}
void Main(){
    init();
    scanf("%d",&n);
    for(int i = 0;i<n;i++) scanf("%d",a+i);
    SparseTable();
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        printf("%d\n",go(l,r));
    }
    return;
}
int main(){
    Main();
    return 0;
}
