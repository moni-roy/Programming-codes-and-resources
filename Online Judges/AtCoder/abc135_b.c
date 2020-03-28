#include <stdio.h>
int a[55];
int check(int n){
    int ret = 1;
    for(int i = 1;i<n;i++) if(a[i-1]>a[i]) ret =0;
    return ret;
}
void swap(int i,int j){
    int c = a[i];
    a[i] = a[j];
    a[j] = c;
}
void MRoy(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++) scanf("%d",a+i);
    int t = check(n);
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            swap(i,j);
            t |= check(n);
            swap(i,j);
        }
    }
    if(t) printf("YES\n");
    else printf("NO\n");
    return;
}
int main(){
    MRoy();
    return 0;
}