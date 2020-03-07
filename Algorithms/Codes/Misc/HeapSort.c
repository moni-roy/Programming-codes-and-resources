int max(int x, int y){return (x<y)?x:y;}
void swap(int *x,int *y){
    int c = *x;
    *x = *y;
    *y = c;
}
int maxChild(int *a,int n,int r,int x,int y){
    if(x<n && a[x]>a[r]) r = x;
    if(y<n && a[y]>a[r]) r = y;
    return r;
}
int minChild(int *a,int n,int r,int x,int y){
    if(x<n && a[x]<a[r]) r = x;
    if(y<n && a[y]<a[r]) r = y;
    return r;
}
void heapify(int *a,int n, int i){
    
    // int j = maxChild(a, n, i, 2*i+1, 2*i+2); // for Max Heap
    int j = minChild(a, n, i, 2*i+1, 2*i+2); // for Min heap
    if(i!=j){
        swap(&a[i],&a[j]);
        heapify(a,n,j);
    }
}
void heapSort(int *a, int n){
    int i;
    for(i = (n-2)/2;i>=0;i--){
        heapify(a,n,i);
    }
    for(i = n-1;i>=0;i--){
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}
