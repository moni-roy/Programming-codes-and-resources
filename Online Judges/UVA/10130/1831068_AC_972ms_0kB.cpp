
#include<bits/stdc++.h>
using namespace std;
int P[1002],W[1002],dp[1002][102];
int N,MW;
int maxi(int m,int n)
{
    if(m>n) return m;
    else return n;
}
int func(int it,int we)
{
    if(it>N) return 0;
    if(dp[it][we]!=-1) return dp[it][we];
    int profit1;
    if(we+W[it]<=MW)
    {
        profit1=P[it]+func(it+1,we+W[it]);
    }
    else profit1=0;
    int profit2=func(it+1,we);
    int ret=maxi(profit1,profit2);
    return dp[it][we]=ret;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d",&P[i],&W[i]);
        }
        int G,sum=0;
        scanf("%d",&G);
        for(int k=1;k<=G;k++)
        {
            memset(dp,-1,sizeof(dp));
            scanf("%d",&MW);
            int f=func(1,0);
            sum=sum+f;
        }
        printf("%d\n",sum);
    }
    return 0;
}
