#include <stdio.h>
#define MOD 1000000007
char s[100010];
long long dp[100010][15];
long long go(int p,int r){
    if(s[p]=='\0'){
        if(r==5) return 1;
        return 0;
    }
    if(dp[p][r]!=-1) return dp[p][r];
    long long ret = 0;
    if(s[p]=='?'){
        for(int i= 0;i<10;i++){
            int rt = r*10+i;
            rt%=13;
            ret += go(p+1,rt);
            ret%=MOD;    
        }
    }
    else {
        int rt = r*10+s[p]-'0';
        rt%=13;
        ret += go(p+1,rt);
        ret%=MOD;
    }
    return dp[p][r]=ret;

}
void MRoy(){
    for(int i = 0;i<100010;i++){
        for(int j = 0;j<15;j++) dp[i][j] = -1;
    }
    scanf("%s",s);
    long long Ans = go(0,0);
    printf("%lld\n",Ans);
    return ;
}
int main(){
    MRoy();
    return 0;
}