#include <stdio.h>
long long min(long long x,long long y){return (x<y)?x:y;}
void swap(int *x,int *y){
    int t = *x;
    *x = *y;
    *y = t;
}
int maxChild(int *ar,int len,int r,int x,int y){
    if(x<len && ar[x]<ar[r]) r = x;
    if(y<len && ar[y]<ar[r]) r = y;
    return r;
}
void heapify(int *ar,int len,int r){
    int c = maxChild(ar,len,r,r*2+1,r*2+2);
    if(c!=r){
        swap(&ar[r],&ar[c]);
        heapify(ar,len,c);
    }
}
void sort(int *ar,int len){
    for(int i = (len-2)/2;i>=0;i--){
        heapify(ar,len,i);
    }
    for(int i = len-1;i>=0;i--){
        swap(&ar[i],&ar[0]);
        heapify(ar,i,0);
    }
}
void Main(){
    int q,n,a[200010],freq[200010];
    scanf("%lld",&q);
    while (q--){
        scanf("%d",&n);
        for(int i = 0;i<=n;i++) freq[i] = 0;
        for(int i = 0;i<n;i++) {
            scanf("%d",a+i);
            freq[a[i]-1]++;
        }
        sort(freq,n);
        long long int Ans = 0,last;
        last = Ans = freq[0];
        for(int i = 1;i<n;i++){
            if(last==0) break;
            Ans += min(last-1,freq[i]);
            last = min(last-1,freq[i]);
        }
        printf("%lld\n",Ans);
    }
    return;
}
int main(){
    Main();
    return 0;
}