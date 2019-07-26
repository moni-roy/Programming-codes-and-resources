#include <stdio.h>
void Main(){
    int n,k=0,a[200010];
    scanf("%d",&n);
    for(int i = 0;i<n;i++) {
        scanf("%d",a+i);
        if(a[k]<a[i]) k = i;
    }
    int Ans = 1;
    for(int i = 0;i<k;i++) if(a[i]>a[i+1]) Ans = 0;
    for(int i = k;i<n;i++) if(a[i]<a[i+1]) Ans = 0;
    if(Ans) puts("YES");
    else puts("NO");
    return;
}
int main(){
    Main();
    return 0;
}
