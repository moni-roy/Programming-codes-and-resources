#include <stdio.h>
void swap(long long *x,long long *y){
    long long c = *x;
    *x = *y;
    *y = c;
}
long long maxChild(long long *ar,long long n,long long r,long long x,long long y){
    if(x<n && ar[x]>ar[r]) r = x;
    if(y<n && ar[y]>ar[r]) r = y;
    return r;
}
void heapify(long long *ar,long long n, long long i){
    long long j = maxChild(ar, n, i, 2*i+1, 2*i+2);
    if(i!=j){
        swap(&ar[i],&ar[j]);
        heapify(ar,n,j);
    }
}
void heapSort(long long *ar, long long n){
    long long i;
    for(i = (n-2)/2;i>=0;i--){
        heapify(ar,n,i);
    }
    for(i = n-1;i>=0;i--){
        swap(&ar[0],&ar[i]);
        heapify(ar,i,0);
    }
}
long long n,a[100010];
void Main(){
    scanf("%lld",&n);
    for(long long i = 0;i<n;i++) scanf("%lld",&a[i]);
    long long ok = 1;
    heapSort(a,n);
    for(long long i = 2;i<n;i++){
        if(a[i]==a[i-1]&&a[i-1]==a[i-2]) ok&=0;
        if(a[i]==a[i-1]&&a[i-2]+1==a[i-1]) ok&=0;
    }
    if(n>=2 && a[0]==a[1]&& a[1]==0) ok&=0;
    int sam = 0;
    for(int i = 1;i<n;i++) if(a[i]==a[i-1]) sam++;
    ok&=(sam<=1);
    long long sum = 0;
    for(long long i = 0;i<n;i++) sum+=a[i];
    if((sum-((long long)(n-1)*n/2))%2==0) ok&=0;
    printf("%s\n",(ok)?"sjfnb":"cslnb");
    return;
}
int main(){
    Main();
    return 0;
}