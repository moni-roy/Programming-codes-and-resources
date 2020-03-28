#include<bits/stdc++.h>

using namespace std;
int dp[10][10000],num;
int coin[]={1,5,10,25,50};
int func(int pos, int co)
{
    if(co==0) return 1;
    if(pos>=5||co<0) return 0;

    if(dp[pos][co]!=-1) return dp[pos][co];
    else return dp[pos][co]=func(pos,co-coin[pos])+func(pos+1,co);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    while(cin>>num)
    {
        if(num>0){
        cout<<func(0,num)<<endl;}
        else cout<<"0"<<endl;
    }
    return 0;
}
