#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long unsigned llu;
typedef double dl;

#define sci(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scs(s) scanf("%s",s)
#define vi vector<int>
#define vl vector<ll>
#define zero(a) memset(a,0,sizeof a)
#define minus(a) memset(a,-1,sizeof a)
#define mii map<int,int>
#define msi map<string,int>
#define mci map<char,int>
#define sti set<int>
#define sts set<string>
#define nl puts("")
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define pru(a) printf("%llu",a)
#define prs(a) printf("%s",a)
#define CS(a) printf("Case %d: ",++a)

string s[110];
int t,n,cnt,l1,l2;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	sci(t);
	while(t--)
	{
		sci(n);
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		}
		sort(s,s+n);
		cnt=s[0].size();
		for(int i=1;i<n;i++)
		{
			l1=s[i].size();
			l2=s[i-1].size();
			
			for(int j=0;j<max(l2,l1);j++)
			{
				if(s[i][j]!=s[i-1][j])
				{
					cnt+=(s[i].size()-j);
					break;
				}
			}
		}
		cout<<cnt<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<s[i]<<endl;
		}
	}
}
