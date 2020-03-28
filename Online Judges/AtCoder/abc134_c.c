#include <stdio.h>
#define MX 200000
int a[MX], n, ln, heap[MX];
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int maxChild(int *ar, int l, int r, int x, int y) {
    if (x < l && ar[r] < ar[x]) r = x;
    if (y < l && ar[r] < ar[y]) r = y;
    return r;
}
void heapify(int *ar, int l, int r) {
    int c = maxChild(ar, l, r, 2 * r + 1, 2 * r + 2);
    if (c != r) {
        swap(&ar[c], &ar[r]);
        heapify(ar, l, c);
    }
}
int getTop(int *ar, int l) {
    int ret = ar[0];
    ar[0] = ar[l];
    heapify(ar, l, 0);
    return ret;
}
void insert(int *ar, int v, int l) {
    ar[l] = v;
    while (l > 0 && ar[(l - 1) / 2] < ar[l]) {
        swap(&ar[(l - 1) / 2], &ar[l]);
        l = (l - 1) / 2;
    }
}
void MRoy() {
    ln = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        insert(heap, a[i], ln++);
    }
    for(int i = 0;i<n;i++){
        if(heap[0]==a[i]){
            getTop(heap,--ln);
            printf("%d\n",heap[0]);
            insert(heap,a[i],ln++);
        }
        else printf("%d\n",heap[0]);
    }
}
int main() {
    MRoy();
    return 0;
}