#include <stdio.h>
int q,n,k,a[101];
void Main(){
    scanf("%d",&q);
    while (q--){
        scanf("%d%d",&n,&k);
        int mx = 0,mn = 1e8+1,Ans = -1;
        for(int i = 0;i<n;i++) {
            scanf("%d",&a[i]);
            mx = (mx<a[i])?a[i]:mx;
            mn = (mn<a[i])?mn:a[i];
        }
        if((mx-mn)<=2*k) Ans = mn+k;
        printf("%d\n",Ans);
    }
    return;
}
int main(){
    Main();
    return 0;
}