#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
int dp[2001][2001];
int mini(int x, int y, int z)
{
	return min(x,min(y,z));
}
int main()
{
	string f,s;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>f>>s;
		int lf=f.size();
		int ls=s.size();
		for(int i=0;i<=lf;i++)
		{
			dp[i][0]=i;
		}
		for(int i=0;i<=ls;i++)
		{
			dp[0][i]=i;
		}
		//memset(dp,0,sizeof dp);
		dp[0][0]=0;
		for(int i=1;i<=lf;i++)
		{
			for(int j=1;j<=ls;j++)
			{
				int vl=(f[i-1]==s[j-1])? 0:1;
				dp[i][j]=mini(dp[i-1][j-1]+vl,dp[i][j-1]+1,dp[i-1][j]+1);
			}
		}
		cout<<dp[lf][ls]<<endl;
	}
	return 0;
}
