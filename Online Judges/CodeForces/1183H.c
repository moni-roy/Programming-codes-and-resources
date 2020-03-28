#include <stdio.h>

long long min(long long x,long long y){return (x<y?x:y);}
int n,prev;
char s[111];
long long k,store[111][111];

void Main(){
    scanf("%d %lld",&n,&k);
    scanf("%s",s);
    store[0][0] = 1;
    for(int i = 0;i<n;i++){
        prev = -1;
        for(int j = 0;j<i;j++) if(s[i]==s[j]) prev = j;
        for(int j = n;j>=1;j--){
            for(int k = prev;k<i;k++){
                store[j][i+1] += store[j-1][k+1];
                store[j][i+1] = min(store[j][i+1],1000000000000ll);
            }
        }
    }
    long long Ans = 0,total = 0;
    for(int i = n;i>=0;i--){
        total = 0;
        for(int j = 0;j<=n;j++) total += store[i][j];
        if(total<k){
            k-=total;
            Ans+=(n-i)*total;
        }
        else{
            
            Ans += (n-i)*k;
            k = 0;
            break;
        }
    }
    if(k==0) printf("%lld\n",Ans);
    else puts("-1");
    return;
}
int main(){
    Main();
    return 0;
}
