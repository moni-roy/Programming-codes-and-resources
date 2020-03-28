#include <stdio.h>
#include <stdlib.h>
#define MXSIZE 200010
long long n,k,a[MXSIZE];
void swap(long long *x,long long *y){
    long long t = *x;
    *x = *y;
    *y = t;
}
long long maxChild(long long *array, long long length, long long root,long long left,long long right){
    if(left < length && array[root] < array[left]) root = left;
    if(right < length && array[root] < array[right]) root = right;
    return root;
}
void heapify(long long *array, long long length, long long root){
    long long child = maxChild(array, length, root, 2*root+1, 2*root+2);
    if(child != root){
        swap(&array[root],&array[child]);
        heapify(array, length, child);
    }
}
void sort(long long *array,long long length){
    for(long long i  = (length-2)/2;i>=0;i--){
        heapify(array, length, i);
    }
    for(long long i = length - 1; i > 0; i--){
        swap(&array[i],&array[0]);
        heapify(array, i, 0);
    }
}
long long max(long long x,long long y){
    return (x>y)?x:y;
}
long long check(long long mid){
    long long ret =0;
    for(long long i = n/2;i<n;i++){
        ret += max(0,mid-a[i]);
        if(ret>k) return 0;
    }
    return ret<=k;
}
void Main(){
    scanf("%lld%lld",&n,&k);
    for(long long i = 0;i<n;i++) scanf("%lld",a+i);
    if(n==1){
        printf("%lld\n",a[0]+k);
        return ;
    }
    sort(a,n);
    long long left = a[n/2], right = a[n/2]+k, Ans;
    while (left<=right)
    {
        long long mid = (left+right)>>1;
        if(check(mid)){
            Ans = mid;
            left = mid+1;
        }
        else right = mid - 1;
    }
    printf("%lld\n",Ans);
}
int main(){
    Main();
    return 0;
}