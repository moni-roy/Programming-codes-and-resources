#include <bits/stdc++.h>

using namespace std;
string fst[110],snd[110],solv[110];
int dp[110][110];
int m,n,idx;
int main()
{
	while(cin>>fst[0])
	{
		memset(dp,0,sizeof dp);
		m=1,n=0;
		while(fst[m-1]!="#") cin>>fst[m++];
		while(1) 
		{
			cin>>snd[n++];
			if(snd[n-1]=="#")
			break;
		}
		m--;n--;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(fst[i-1]==snd[j-1]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		idx=0;
		while(dp[m][n]>0)
		{
			if(fst[m-1]==snd[n-1])
			{
				solv[idx++]=fst[m-1];
				m--;n--;
			}
			else if(dp[m][n-1]>dp[m-1][n])
			{
				n--;
			}
			else
			{
				m--;
			}
		}
		for(int i=idx-1;i>=0;i--)
		{
			cout<<solv[i];
			if(i!=0)
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
