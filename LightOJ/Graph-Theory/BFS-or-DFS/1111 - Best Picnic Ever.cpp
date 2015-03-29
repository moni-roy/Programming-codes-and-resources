#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef long long unsigned 	llu;
typedef double 			dl;
typedef pair<int,int> 		pii;
typedef pair<ll,ll> 		pll;
typedef vector<int> 		vi;
typedef map<int,int> 		mii;
typedef map<ll,ll>		mll;
typedef map<string,int> 	msi;
typedef map<char,int> 		mci;

#define PI		acos(-1.0)
#define sn 		second
#define fs		first
#define pb		push_back
#define mp		make_pair
#define zero(a) 	memset(a,0,sizeof a)
#define minus(a) 	memset(a,-1,sizeof a)
#define setinf(a) 	memset(a,126,sizeof a)
#define FR(i,x,y) 	for(int i=x;i<=y;i++)
#define FRV(i,x,y) 	for(int i=x;i>=y;i--)
#define all(v)		(v.begin(),v.end())
#define vsort(v)	sort(all(v))
#define nl 		puts("")
#define endl		'\n'
#define I_O		ios_base::sync_with_stdio(0); cin.tie(0);

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}

int t,cs=0,k,n,m,sum,pl[10001],vs[100010],u,v,x,y,ans,pp[10001];
int grp[1001][1001];
void fun(int a)
{
	FR(i,1,n)
	{
		if(i==a) continue;
		if(grp[a][i]==1&&vs[i]==0)
		{
			vs[i]=1;
			pl[i]++;
			fun(i);
		}
	}
}
int main()
{
	//I_O;
	cin>>t;
	while(t--)
	{
		cin>>k>>n>>m;
		zero(pl);
		zero(grp);
		sum=0;
		FR(i,1,k)
		{
			cin>>pp[i];
		}
		FR(i,1,m){
			cin>>x>>y;
			grp[x][y]=1;
		}
		FR(i,1,k)
		{
			zero(vs);
			vs[pp[i]]=1;
			pl[pp[i]]++;
			fun(pp[i]);
		}
		ans=0;
		FR(i,1,n)
		{
			if(pl[i]==k) ans++;
		}
		cout<<"Case "<<++cs<<": "<<ans<<endl;
	}
}
