/*
 * randPivot requires rand() function
 */
void swap(int *x,int *y){
    int c = *x;
    *x = *y;
    *y = c;
}
int randPivot(int *a,int l,int r){
    int p = l+rand()%(r-l+1);
    swap(&a[p],&a[r]);
    int i = l-1;
    for(int j = l;j<=r;j++){
        if(a[j]<=a[r]){
            swap(&a[++i],&a[j]);
        }
    }
    return i;
}
int pivot(int *a,int l,int r){
    int i = l-1;
    for(int j = l;j<=r;j++){
        if(a[j]<=a[r]){
            swap(&a[++i],&a[j]);
        }
    }
    return i;
}
void quickSort(int *a,int l, int r){
    if(l<r){
        int p = pivot(a,l,r);
        // int p = randPivot(a,l,r);
        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}
