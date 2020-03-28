///using floyd-warshll algo

#include <bits/stdc++.h>

#define ll long long
#define dl double
#define inf 100000009
#define mx 27

using namespace std;

ll dp[mx][mx];
char s[100009],f[100009];
char a[100009];

void zero()
{
	for(ll i=0;i<mx;i++)
	{
		for(ll j=0;j<mx;j++)
		{
			if(i==j) dp[i][j]=0;
			else  dp[i][j]=inf;
		}
	}
}

void floyd()
{
	for(ll k=0;k<mx;k++)
	{
		for(ll i=0;i<mx;i++)
		{
			for(ll j=0;j<mx;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}

int main()
{
	zero();
	ll n,w,ls,lf;
	scanf("%s%s",f,s);
	lf=strlen(f);
	ls=strlen(s);
	
	scanf("%lld",&n);
	for(ll i=0;i<n;i++)
	{	
		char x,y;
		scanf(" %c %c %I64d",&x,&y,&w);
		ll p=x-'a';
		ll q=y-'a';
		dp[p][q]=min(dp[p][q],w);
	}	
	
	if(lf!=ls){ cout<<"-1"<<endl; return 0;}

	floyd();
	ll sum=0,cost=0,fl=1;
	for(ll i=0;i<lf;i++)
	{
		cost=inf;
		ll m=f[i]-'a';
		ll n=s[i]-'a';
		for(ll j=0;j<mx;j++)
		{
			ll tl=dp[m][j]+dp[n][j];
			if(cost>tl)
			{
				cost=tl;
				a[i]=j+'a';
			}
		}
		if(cost>=inf)
		{
			fl=0;
			break;
		}
		
		sum+=cost;
	}
	if(fl)
	{
		cout<<sum<<endl;
		puts(a);
	}
	else puts("-1");
	
	return 0;
}
