#include <stdio.h>
#define MX 200010
int n,a,q,mp[MX],uni[MX];
void swap(int *x,int *y){
    int c = *x;
    *x = *y;
    *y = c;
}
int minChild(int *ar,int len,int r,int x,int y){
    if(x<len && ar[x]<ar[r]) r = x;
    if(y<len && ar[y]<ar[r]) r = y;
    return r;
}
void heapify(int *ar,int len,int r){
    int c = minChild(ar,len,r,r*2+1,r*2+2);
    if(c!=r){
        swap(&ar[r],&ar[c]);
        heapify(ar,len,c);
    }
}
void heapSort(int *ar,int len){
    for(int i = (len-2)/2;i>=0;i--){
        heapify(ar,len,i);
    }
    for(int i = len-1;i>0;i--){
        swap(&ar[i],&ar[0]);
        heapify(ar,i,0);
    }
}
void Main(){
    scanf("%d",&q);
    while (q--)
    {
        int k =0;
        scanf("%d",&n);
        for(int i = 0;i<n;i++){
            scanf("%d",&a);
            if(mp[a]==0) uni[k++] = a;
            mp[a] = 1;
        }
        heapSort(uni,k);
        int Ans = uni[0];
        for(int i = 0;i<k;i++){
            for(int j = i;j<k;j++){
                if(uni[i]%uni[j]){
                    Ans = (Ans<(uni[i]+uni[j]))?uni[i]+uni[j]:Ans;
                    break;
                }
            }
        }
        n = k;
        for(int i = 0;i<n;i++){
            if(3*uni[i]<=Ans) break;
            for(int j = i;j<n;j++){
                if(uni[i]+uni[j]*2<=Ans) break;
                if(uni[i]%uni[j]==0) continue;
                for(int k = j;k<n;k++){
                    if(uni[i]+uni[j]+uni[k]<=Ans) break;
                    if(uni[i]%uni[k]== 0 || uni[j]%uni[k]==0) continue;
                    Ans = uni[i]+uni[j]+uni[k];
                }
            }
        }
        printf("%d\n",Ans);
        for(int i = 0;i<MX;i++) mp[i] = 0;
    }
    return;
}
int main(){
    Main();
    return 0;
}
