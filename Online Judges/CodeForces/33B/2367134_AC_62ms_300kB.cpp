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
	///cout<<"STRING "<<f<<' '<<s<<endl;
	lf=strlen(f);
	ls=strlen(s);
	
	///cout<<"STRING "<<f<<' '<<s<<endl;
	scanf("%lld",&n);
	///cout<<"STRING "<<f<<' '<<s<<endl;
	for(ll i=0;i<n;i++)
	{	
		char x,y;
		scanf(" %c %c %lld",&x,&y,&w);
		ll p=x-'a';
		ll q=y-'a';
		dp[p][q]=min(dp[p][q],w);
	}	
	
	///cout<<ls<<' '<<lf<<endl;
	if(lf!=ls){ cout<<"-1"<<endl; return 0;}

	floyd();
	///cout<<"STRING "<<f<<' '<<s<<endl;
	ll sum=0,cost=0,fl=1;
	///cout<<"INF "<<inf<<endl;
	for(ll i=0;i<lf;i++)
	{
		cost=inf;
		ll m=f[i]-'a';
		ll n=s[i]-'a';
		///cout<<"CHAR "<<f[i]<<' '<<s[i]<<endl;
		///cout<<m<<' '<<n<<endl;
		for(ll j=0;j<mx;j++)
		{
			ll tl=dp[m][j]+dp[n][j];
			///cout<<tl<<" "<<dp[m][j]<<" "<<dp[n][j]<<' ' <<j<<endl;
			if(cost>tl)
			{
				cost=tl;
				a[i]=j+'a';
				///cout<<a<<' '<<cost<<endl;
			}
		}
		if(cost>=inf)
		{
			fl=0;
			break;
		}
		
		sum+=cost;
	}
	///cout<<ls<<' '<<lf<<endl;
	if(fl)
	{
		//a[lf]='\0';
		cout<<sum<<endl;
		puts(a);
	}
	else puts("-1");
	
	return 0;
}
