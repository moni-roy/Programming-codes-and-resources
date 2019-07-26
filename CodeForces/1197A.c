#include <stdio.h>
int min(int x,int y){return (x<y)?x:y;}
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
    int n,k,ts, id = 0,a[100010];
    scanf("%d",&ts);
    while(ts--){
        scanf("%d",&n);
        for(int i = 0;i<n;i++) scanf("%d",a+i);
        heapSort(a,n);
        int Ans = min(a[n-2]-1,n-2);
        printf("%d\n",Ans);
    }
    return;
}
int main(){
    Main();
    return 0;
}
