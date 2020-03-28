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

vl prm;
ll vs[100005];

void F(){
	prm.PB(2);
	for(ll i=4;i<100001;i+=2) vs[i]=1;
	for(ll i=3;i*i<100001;i+=2){
		if(!vs[i]){
			for(ll j=i+i;j<100001;j+=i){
				vs[j]=1;
			}
		}
	}
	for(ll i=3;i<100001;i+=2){
		if(!vs[i]) prm.PB(i);
	}
}

ll pi(ll n){
	if (n==1) return 0;
	ll ret=n;
	for(ll i=0;i<(ll)prm.size()&&prm[i]<=sqrt(n);i++){
		if(n%prm[i]==0){
			while(n%prm[i]==0) n/=prm[i];
			ret/=prm[i];
			ret*=(prm[i]-1);
		}
	}
	if(n>1){
		ret/=n;
		ret*=(n-1);
	}
	return ret;
}

int main()
{
	F();
	ll n;
	while(cin>>n&&n){
		ll Ans=pi(n);
		cout<<Ans<<endl;
	}
	return 0;
}
