#include <bits/stdc++.h>
using namespace std;

typedef long long          	ll;
typedef long long unsigned 	llu;
typedef double             	dl;
typedef pair<int,int>      	pii;
typedef pair<ll,ll>     	pll;
typedef vector<int>        	vi;
typedef vector<ll>        	vl;
typedef map<int,int> 		mii;
typedef map<ll,ll>         	mll;
typedef map<string,int>    	msi;
typedef map<char,int>      	mci;

#define PI          acos(-1.0)
#define S           second
#define F           first
#define PB          push_back
#define MP          make_pair
#define P           push
#define zero(a)     memset(a,0,sizeof a)
#define minus(a)    memset(a,-1,sizeof a)
#define setinf(a)   memset(a,126,sizeof a)
#define all(v)      (v.begin(),v.end())
#define vsort(v)    sort(v.begin(),v.end())
#define nl          puts("")
#define tcase(cs)   printf("Case %d:",++cs)
#define endl        '\n'
#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)
#define I_O         ios_base::sync_with_stdio(0); cin.tie(0);
#define gcd(a,b)    __gcd(a,b)
#define sci(a)      scanf("%d",&a)
#define scl(a)      scanf("%lld",&a)
#define scd(a)      scanf("%lf",&a)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2;i<=sqrt(double(a));i++){if(a%i==0){return 0;}}return 1;}
template <class T> inline T lcm(T a, T b){return (a/gcd(a,b))*b;}

#define md 1000000007ll

ll v,n,pw,a0,b0,a1,b1,c0,c1,m0,m1,Ans,ts;
ll p[111],q[111],l[111];
int main()
{
	cin>>ts;
	while(ts--){
		cin>>v>>n;
		cin>>p[0]>>p[1]>>a0>>b0>>c0>>m0;
		cin>>q[0]>>q[1]>>a1>>b1>>c1>>m1;
		
		for(int i=2;i<n;i++){
			p[i]=(((((a0*a0)%m0)*p[i-1])%m0+(b0*p[i-2])%m0)%m0+c0)%m0;
			q[i]=(((((a1*a1)%m1)*q[i-1])%m1+(b1*q[i-2])%m1)%m1+c1)%m1;
		}
		for(int i=0;i<n;i++){
			l[i]=p[i]*(m1)+q[i]+1;
		}
		pw=1;
		for(int i=0;i<n;i++){
			l[i]--;
			if(l[i]==0){
				pw=0;
				break;
			}
			if(v%md){
				l[i]%=(md-1);
				pw*=l[i];
				pw%=(md-1);
			}
		}
		if(pw==0) Ans=1;
		else if(v%md==0) Ans=0;
		else Ans=BMOD(v%md,pw,md);
		cout<<Ans<<endl;
	}
	return 0;
}
