#include <stdio.h>
#define SIZE 100006
typedef struct mk{
    int b;
    struct mk *next;
}data;
data *input[SIZE],node[SIZE];
int id = 0;
data *New(int b){
    data *tm = &node[id++];
    tm->b = b;
    tm->next = NULL;
    return tm;
}
data *insert(data *root, int b){
    if(root==NULL) return New(b);
    data *tm = New(b);
    tm->next = root;
    return tm;
}
int len = 0,heap[SIZE];
void swap(int *x,int *y){
    int t = *x;
    *x = *y;
    *y = t;
}
int minChild(int *ar,int len,int r,int lf,int rt){
    if(lf<len && ar[r]<ar[lf]) r = lf;
    if(rt<len && ar[r]<ar[rt]) r = rt;
    return r;
}
void heapify(int *ar, int len,int r){
    int c = minChild(ar,len,r,r*2+1,r*2+2);
    if(c!=r){
        swap(&ar[r],&ar[c]);
        heapify(ar,len,c);
    }
}
int getTop(int len){
    int ret = heap[0];
    heap[0] = heap[len];
    heapify(heap,len, 0);
    return ret;
}
void Insert(int v,int len){
    heap[len]=v;
    while(len>0 && heap[(len-1)/2]<heap[len]){
        swap(&heap[len],&heap[(len-1)/2]);
        len = (len-1)/2;
    }
}
void MRoy(){
    int n,m,a,b,length = 0;
    for(int i = 0;i<SIZE;i++) input[i] = NULL;
    scanf("%d%d",&n,&m);
    for(int i = 0;i<n;i++){
        scanf("%d %d",&a,&b);
        input[a] = insert(input[a],b);
    }
    int Ans = 0;
    for(int i = 0;i<m;i++){
        data *tm = input[i+1];
        while(tm!=NULL){
            Insert(tm->b,length);
            length++;
            tm=tm->next;
        }
        if(length){
            Ans += getTop(--length);
        }
    }
    printf("%d\n",Ans);
    return;
}
int main(){
    MRoy();
    return 0;
}