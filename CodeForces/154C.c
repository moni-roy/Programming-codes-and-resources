#include <stdio.h>

#define MXSIZE 1000009
const unsigned long long Base = 31;
unsigned long long base[MXSIZE],hash[MXSIZE];
int v[MXSIZE],u[MXSIZE];
void init(){
    base[0] = 1ULL;
    hash[0]=0;
    for(int i = 1;i<MXSIZE;i++){
        base[i] = base[i-1] * Base;
        hash[i] = 0;
    }
}
void swap(unsigned long long *x, unsigned long long *y){
    unsigned long long copy = *x;
    *x = *y;
    *y = copy;
}
int findMaxChild(unsigned long long *array, int length,int root,int left,int right){
    if(left<length && array[root]<array[left]) root = left;
    if(right<length && array[root]<array[right]) root = right;
    return root;
}
void heapify(unsigned long long *array,int length, int root){
    int child  = findMaxChild(array, length, root, root*2+1, root*2+2);
    if(child!=root){
        swap(&array[child],&array[root]);
        heapify(array,length,child);
    }
}
void sort(unsigned long long *array,int length){
    for(int i = (length-2)/2;i>=0;i--){
        heapify(array, length, i);
    }
    for(int i = length-1;i>0;i--){
        swap(&array[i],&array[0]);
        heapify(array,i,0);
    }
}
void Main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i<m;i++){
        scanf("%d%d",&v[i],&u[i]);
        v[i]--;
        u[i]--;
        hash[v[i]]+=base[u[i]];
        hash[u[i]]+=base[v[i]];
    }
    long long Answer = 0;
    for(int i = 0;i<m;i++){
        unsigned long long  x = hash[v[i]]-base[u[i]];
        unsigned long long  y = hash[u[i]]-base[v[i]];
        if(x==y) Answer++;
    }
    sort(hash,n);
    long long count = 0;
    for(int i = 0;i<n-1;i++){
        if(hash[i]==hash[i+1]) count++;
        else {
            Answer += ((count * (count+1))>>1);
            count= 0;
        }
    }
    Answer += (count * (count+1)/2);
    printf("%lld\n",Answer);
}
int main(){
    init();
    Main();
    return 0;
}