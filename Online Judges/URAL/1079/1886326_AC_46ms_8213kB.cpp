#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
long long dp[1000000];
int func(int num)
{
	dp[0]=0;dp[1]=1;dp[2]=1;
	int mx=1;
   for(int x=3;x<=num;x++)
   {
	   if(x%2==0)
	   {
		   dp[x]=dp[x/2];
		   mx=max(mx,dp[x]);
	   }
	   else
	   {
		   dp[x]=dp[x/2]+dp[x/2+1];
		   mx=max(mx,dp[x]);
	   }
   }
   return mx;
}
int main()
{
	long long num;
	while(cin>>num&&num)
	{
		memset(dp,0,sizeof(dp));
		int ans=func(num);
		cout<<ans<<endl;
	}
	return 0;
}
