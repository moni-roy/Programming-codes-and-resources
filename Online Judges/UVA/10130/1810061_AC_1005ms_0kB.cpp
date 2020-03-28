#include<bits/stdc++.h>
#define max_n 1000
#define max_w 100
#define ll int
using namespace std;
ll dp[max_n+1][max_w+1],g,mw,weight[max_n+1],cost[max_n+1],cap[max_w+1],n;

ll func(ll i ,ll w)
{
    if(i==n+1) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    ll profit1=0,profit2=0;
    if(w+weight[i]<=mw)
    {
        profit1=cost[i]+func(i+1,w+weight[i]);
    }
    else profit1=0;
    profit2=func(i+1,w);
    dp[i][w]=max(profit1,profit2);
    return dp[i][w];
}
int main()
{
    ll tst,result;
    cin>>tst;
    while(tst--)
    {
//        memset(dp,-1,sizeof(dp));
        result=0;
        cin>>n;
        for(ll j=1; j<=n; j++)
        {
            cin>>cost[j]>>weight[j];
        }
        cin>>g;
        for(ll j=1; j<=g; j++)
        {
            memset(dp,-1,sizeof(dp));
            cin>>cap[j];
            mw=cap[j];
            result=result+func(1,0);
        }
        cout<<result<<endl;
    }
    return 0;
}
