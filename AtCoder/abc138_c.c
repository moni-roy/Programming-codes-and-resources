#include <stdio.h>
void swap(double *x,double *y){
    double t = *x;
    *x = *y;
    *y = t;
}
int minChild(double *ar,int len,int r,int x,int y){
    if(x<len && ar[r]>ar[x]) r = x;
    if(y<len && ar[r]>ar[y]) r = y;
    return r;
}
void heapify(double *ar,int len,int r){
    int c = minChild(ar, len, r, 2*r+1, 2*r+2);
    if(c!=r){
        swap(&ar[r],&ar[c]);
        heapify(ar,len,c);
    }
}
double getTop(double *ar,int len){
    double top = ar[0];
    ar[0]=ar[len];
    heapify(ar,len,0);
    return top;
}
void insert(double *ar,int len,double val){
    ar[len] = val;
    while (len>0 && ar[(len-1)/2]>ar[len]){
        swap(&ar[len],&ar[(len-1)/2]);
        len = (len-1)/2;
    }
}
void MRoy(){
    int N;
    double v[1001],heap[1001];
    scanf("%d",&N);
    int len = 0;
    for(int i = 0;i<N;i++){
        scanf("%lf",v+i);
        insert(heap,len,v[i]);
        len++;
    }
    while(len>1){
        double x = getTop(heap,--len);
        double y = getTop(heap,--len);
        insert(heap,len,(x+y)/2);
        len++;
    }
    printf("%.10lf\n",heap[0]);
}
int main(){
    MRoy();
    return 0;
}