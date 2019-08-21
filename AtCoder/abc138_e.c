#include <stdio.h>
#define MXSZ 100010
char s[MXSZ],t[MXSZ];
int P[27][MXSZ],C[27];
int bSearch(int *ar,int l,int r,int v){
    int ret = -1;
    while(l<=r){
        int m = (l+r)/2;
        if(ar[m]>=v){
            ret = ar[m];
            r = m-1;
        }
        else l = m+1;
    }
    return ret;
}
void MRoy(){
    scanf("%s%s",s,t);
    long long L = 0;
    for(int i = 0;s[i]!='\0';i++){
        int T = s[i]-'a';
        P[T][C[T]++] = i;
        L++;
    }
    long long int Loop = 0;int pos = -1;
    for(int i = 0;t[i]!='\0';i++){
        int T = t[i]-'a';
        if(C[T]==0) {
            printf("-1\n");
            return;
        }
        int res = bSearch(P[T],0,C[T]-1,pos+1);
        if(res==-1) {
            Loop++;
            pos = P[T][0];
        }
        else pos = res;
    }
    printf("%lld\n",Loop*L+pos+1ll);
    return;
}
int main(){
    MRoy();
    return 0;
}