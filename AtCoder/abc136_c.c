#include <stdio.h>
int n,a[100020];
int main(){
    scanf("%d",&n);
    for(int i =0;i<n;i++) scanf("%d",a+i);
    int flag = 1;
    a[0]--;
    for(int i = 1;i<n;i++){
        if(a[i]>a[i-1]) a[i]--;
        if(a[i]<a[i-1]) {
            flag = 0;
            break;
        }
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}