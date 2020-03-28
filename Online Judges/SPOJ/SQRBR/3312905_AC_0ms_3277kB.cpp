#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long unsigned llu;
typedef double dl;

#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define vi vector<int>
#define vl vector<ll>
#define zero(a) memset(a,0,sizeof a)
#define minus(a) memset(a,-1,sizeof a)
#define mii map<int,int>
#define msi map<string,int>
#define mci map<char,int>
#define sti set<int>sti
#define sts set<string>sts
#define nl puts("")

int main()
{
	int ts,n,k,sv[100][100],a[100];
	si(ts);
	while(ts--)
	{
		zero(sv);
		mii mp;
		si(n),si(k);
		for(int i=0;i<k;i++)
		{
			si(a[i]);
			mp[a[i]]++;
		}
		n*=2;
		sv[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				
				if(mp[i]>=1) {
					if(j>0) sv[i][j]+=sv[i-1][j-1];
					}
				else
				{
					if(j>0) sv[i][j]+=sv[i-1][j-1];
					if(j<n) sv[i][j]+=sv[i-1][j+1];
				}
				//cout<<sv[i][j]<<"++";
			}
			//nl;
		}
		cout<<sv[n-1][1]<<endl;
	}
}
