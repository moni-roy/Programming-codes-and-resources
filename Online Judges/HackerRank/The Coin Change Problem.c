#include <stdio.h>

long long sv[55][255], a[55], n, m;

long long go(int p,int res){
    if(res == 0) return 1;
    if(p>m || res<0) return 0;
    long long ret = sv[p][res];
    if(ret!=-1) return ret;
    ret = go(p, res-a[p]) + go(p+1,res);
    return sv[p][res] = ret;
}

int main(){
    scanf("%lld%lld",&n,&m);    
    for(int i = 0;i<m;i++){
        scanf("%lld",&a[i]);
    }
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<m;j++) sv[j][i] = -1;
    }
    long long int Ans = go(0,n);
    printf("%lld\n",Ans);
    return 0;
}
