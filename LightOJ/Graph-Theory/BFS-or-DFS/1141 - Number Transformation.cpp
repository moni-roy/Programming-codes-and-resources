#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef long long unsigned 		llu;
typedef double 		dl;
typedef pair<int,int> 		pii;
typedef pair<ll,ll> 		pll;
typedef vector<int> 		vi;
typedef map<int,int> 		mii;
typedef map<ll,ll> 		mll;
typedef map<string,int> 		msi;
typedef map<char,int> 		mci;

#define PI		acos(-1.0)
#define sn	 	second
#define fs 		first
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
#define tcase(cs) 	printf("Case %d:",++cs)
#define endl		'\n'
#define I_O		ios_base::sync_with_stdio(0); cin.tie(0);

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}

int t,cs=0,x,y,vs[10001],cp;
vi grp[10001];

int bfs(int st)
{
	minus(vs);
	queue<int>q;
	vs[st]=0;
	q.push(st);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=0;i<(int)grp[u].size();i++)
		{
			int v=u+grp[u][i];
			if(vs[v]==-1&&v<=y)
			{
				vs[v]=vs[u]+1;
				if(v==y) return vs[v];
				q.push(v);
			}
		}
	}
	return -1;
}

void fun()
{
	for(int i=2;i<=1001;i++)
	{
		cp=i;
		for(int j=2;j*j<=cp;j++)
		{
			if(cp%j==0)
			{
				grp[i].pb(j);
				while(cp%j==0) cp/=j;
			}
		}
		if(cp!=1&&cp!=i) grp[i].pb(cp);
	}
}
int main()
{
	fun();
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		tcase(cs);
		if(x==y) cout<<" 0"<<endl;
		else cout<<" "<<bfs(x)<<endl;
	}
}

