#include <bits/stdc++.h>
using namespace std;

typedef long long          	ll;
typedef long long unsigned 	llu;
typedef double             	dl;
typedef pair<int,int>      	pii;
typedef pair<ll,ll>     	pll;
typedef vector<int>        	vi;
typedef map<int,int> 		mii;
typedef map<ll,ll>         	mll;
typedef map<string,int>    	msi;
typedef map<char,int>      	mci;

#define PI  		acos(-1.0)
#define S	    	second
#define F 	    	first
#define PB	    	push_back
#define MP	    	make_pair
#define zero(a) 	memset(a,0,sizeof a)
#define minus(a) 	memset(a,-1,sizeof a)
#define setinf(a) 	memset(a,126,sizeof a)
#define FR(i,x,y) 	for(int i=x;i<=y;i++)
#define FRV(i,x,y) 	for(int i=x;i>=y;i--)
#define all(v)		(v.begin(),v.end())
#define vsort(v)	sort(v.begin(),v.end())
#define nl  		puts("")
#define tcase(cs) 	printf("Case %d:",++cs)
#define endl		'\n'
#define I_O	    	ios_base::sync_with_stdio(0); cin.tie(0);

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

int sv[110][1<<18],nn,s,n,m,c[1001];
vi sb[110];

int fun(int p,int ms){
	if(ms==(1<<nn)-1) return 0;
	if(p>m) return 10000000;
	int &ret=sv[p][ms];
	if(ret!=-1) return ret;
	int tmp=ms;
	for(int i=0;i<(int)sb[p].size();i++){
		int y=sb[p][i];
		if(!check(tmp,y-1)){
			tmp=Set(tmp,y-1);
		}
		else {
			tmp=Set(tmp,y+s-1);
		}
	}
	ret=min(fun(p+1,ms),c[p]+fun(p+1,tmp));
	return ret;
}
int main()
{
	int cost,mk,x;
	string ss;
	while(cin>>s>>n>>m)
	{
		if(s+n+m==0) break;
		mk=0;
		cost=0;
		for(int i=0;i<n;i++){
			cin>>x;
			cost+=x;
			getline(cin,ss);
			stringstream sss;
			sss<<ss;
			while(sss>>x){
				if(!check(mk,x-1)){
					mk=Set(mk,x-1);
				}
				else mk=Set(mk,x+s-1);
			}
		}
		for(int i=0;i<m;i++){
			cin>>x;
			c[i]=x;
			getline(cin,ss);
			stringstream sss;
			sss<<ss;
			while(sss>>x){
				sb[i].PB(x);
			}
		}
		minus(sv);
		nn=s;
		nn*=2;	
		cout<<cost+fun(0,mk)<<endl;
		for(int i=0;i<m;i++) sb[i].clear();
	}
	return 0;
}
/*
2 2 2
10000 1
20000 2
30000 1 2
40000 1 2
* */
