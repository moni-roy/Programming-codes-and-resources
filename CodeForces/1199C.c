#include <stdio.h>
#define MXSIZE 400010
long long n,I,a[MXSIZE],pr[MXSIZE];
void swap(long long *x,long long *y){
    int c = *x;
    *x = *y;
    *y = c;
}
int maxChild(long long *ar,int len,int r,int x,int y){
    if(x<len && ar[x]>ar[r]) r = x;
    if(y<len && ar[y]>ar[r]) r = y;
    return r;
}
void heapify(long long *ar,int len,int r){
    int c = maxChild(ar,len,r,2*r+1,2*r+2);
    if(c!=r){
        swap(&ar[c],&ar[r]);
        heapify(ar,len,c);
    }
}
void sort(long long *ar,int len){
    for(int i = (len-2)/2;i>=0;i--){
        heapify(ar,len,i);
    }
    for(int i = n-1;i>=0;i--){
        swap(&ar[0],&ar[i]);
        heapify(ar,i,0);
    }
}
long long power(long long x,long long p){
    long long ret = 1;
    while(p){
        if(p&1) ret *= x;
        p>>=1;
        x*= x;
        if(ret>=MXSIZE) return MXSIZE;
    }
    return ret;
}
void Main(){
    scanf("%lld%lld",&n,&I);
    for(int i = 0;i<n;i++) scanf("%lld",a+i);
    sort(a,n);
    I = 8ll*I/n;
    if(I>=30){
        puts("0");
        return;
    }
    long long k = 1<<I;
    long long count = 1;
    pr[0] = 1;
    for(int i = 1;i<n;i++) 
    {
        if(a[i]!=a[i-1]) {
            count++;
            pr[i] = pr[i-1]+1;
        }
        else pr[i] = pr[i-1];
    }
    if(count<=k) puts("0");
    else{
        int i;
        for(i = 0;i<n;i++) if(pr[i]>k) break;
        long long Ans = (n-i);
        int j = 0;
        long long tl = k;
        while(i<n){
            while(j<n && k<=(pr[i] - pr[j])) {
                j++;
            }
            while(i<n && k>=pr[i]-pr[j-1]) {
                i++;
            }
            Ans = (Ans<(n-i+j))?Ans:n-i+j;
        }
        printf("%lld\n",Ans);
    }
}
int main(){
    Main();
    return 0;
}