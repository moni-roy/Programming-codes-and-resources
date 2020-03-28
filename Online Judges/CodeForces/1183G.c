#include <stdio.h>
#include <stdlib.h>
#define MX_SIZE 200010

typedef struct mk{
    int cnt,fr;
}roy;
roy freq[MX_SIZE];

int q,n,a,f,*count[MX_SIZE],cnt[MX_SIZE],hop[MX_SIZE];

int min(int x,int y){
    return (x<y)?x:y;
}
void swap(int *x,int *y){
    int c = *x;
    *x = *y;
    *y = c;
}
int maxChild(int *ar,int len,int r,int x,int y){
    if(x<len && ar[x]>ar[r]) r = x;
    if(y<len && ar[y]>ar[r]) r = y;
    return r;
}
void heapify(int *ar,int len,int r){
    int c = maxChild(ar,len,r,r*2+1,r*2+2);
    if(c!=r){
        swap(&ar[r],&ar[c]);
        heapify(ar,len,c);
    }
}
void heapSort(int *ar,int len){
    for(int i = (len-2)/2;i>=0;i--){
        heapify(ar,len,i);
    }
}
void init(){
    for(int i = 0;i<=n+1;i++){
        freq[i].cnt = 0;
        freq[i].fr = 0;
        cnt[i] = 0;
    }
}
void Main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        init();
        for(int i = 0;i<n;i++){
            scanf("%d%d",&a,&f);
            freq[a].cnt++;
            freq[a].fr += f;
        }
        for(int i = 1;i<=n;i++){
            int t = freq[i].cnt;
           if(t) cnt[t]++;
        }
        for(int i = 1;i<=n;i++){
            if(cnt[i]) count[i] = (int *)malloc(sizeof(int)*(cnt[i]+1));
            cnt[i] = 0;
        }
        for(int i = 1;i<=n;i++){
            int t = freq[i].cnt;
            if(t) count[t][cnt[t]++] = freq[i].fr;
        }
        int AnsX = 0, AnsY = 0,id = 0;
        for(int i = n;i>0;i--){
            for(int j = 0;j<cnt[i];j++) {
                hop[id++] = count[i][j];
            }
            if(id>0){
                heapSort(hop,id);
                AnsX += i;
                AnsY += min(hop[0],i);
                swap(&hop[0],&hop[id-1]);
                id--;
            }
        }
        printf("%d %d\n",AnsX,AnsY);
    }
    return;
}
int main(){
    Main();
    return 0;
}
