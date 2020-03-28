#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<map>
#include<cstring>
#include<vector>
#include<set>

using namespace std;
string fst,snd;
int dp[1001][1001];
int func(int a,int b)
{
	if(a<0||b<0) return 0;
	if(dp[a][b]!=-1) return dp[a][b];
	if(fst[a]==snd[b])
	{
		return dp[a][b]=1+func(a-1,b-1);
	}
	return dp[a][b]=max(func(a-1,b),func(a,b-1));
	
}
int main()
{
	
	while(getline(cin,fst),getline(cin,snd))
	{
		memset(dp,-1,sizeof(dp));
		cout<<func(fst.size()-1,snd.size()-1)<<endl;
	}
	return 0;
}
