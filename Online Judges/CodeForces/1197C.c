#include <stdio.h>
void swap(int *x,int *y){
    int t = *x;
    *x = *y;
    *y = t;
}
int childMax(int *a,int n,int r,int x,int y){
    if(x<n && a[x]>a[r]) r = x;
    if(y<n && a[y]>a[r]) r = y;
    return r;
}
void heapify(int *a,int n,int r){
    int c = childMax(a,n,r,r*2+1,r*2+2);
    if(r!=c){
        swap(&a[r],&a[c]);
        heapify(a,n,c);
    }
}
void heapSort(int *a,int n){
    for(int i = (n-2)/2;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i = n-1;i>=0;i--){
        swap(&a[i],&a[0]);
        heapify(a,i,0);
    }
}
void Main(){
    int n,k,id = 0,a[300010],t[300010];
    scanf("%d%d",&n,&k);
    for(int i = 0;i<n;i++) scanf("%d",a+i);
    for(int i = 1;i<n;i++){
        t[id++] = a[i-1] - a[i];
    }
    heapSort(t,id);
    long long int Ans = a[n-1]-a[0];
    for(int i = 0;i<k-1;i++) Ans+=t[i];
    printf("%lld\n",Ans);
    return;
}
int main(){
    Main();
    return 0;
}
