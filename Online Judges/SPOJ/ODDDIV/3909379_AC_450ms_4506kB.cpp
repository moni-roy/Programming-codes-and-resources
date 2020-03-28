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

bool vs[10001];
vl prm,sv[100010];

void F(){
	for(int i=4;i<1001;i+=2) vs[i]=1;
	for(int i=3;i*i<1001;i+=2){
		if(!vs[i]){
			for(int j=i*i;j<1001;j+=i) vs[j]=1;
		}
	}
	prm.PB(2);
	for(int i=3;i<1001;i+=2){
		if(!vs[i]) prm.PB(i);
	}
	for(ll i=2;i<100010;i++){
		ll t=i;
		ll dv=1;
		for(int j=0;j<(int)prm.size()&&prm[j]<=sqrt(t);j++){
			if(t%prm[j]==0){
				int cnt=0;
				while(t%prm[j]==0){
					cnt++;
					t/=prm[j];
				}
				dv*=((cnt*2ll)+1ll);
			}
		}
		if(t>1) dv*=3ll;
		sv[dv/2].PB(ll(i*i));
	}
}
int main()
{
	F();
	int ts;
	ll k,l,h,Ans;
	cin>>ts;
	while(ts--){
		cin>>k>>l>>h;
		k/=2;
		//cout<<k<<endl;
		ll p=upper_bound(sv[k].begin(),sv[k].end(),h)-sv[k].begin();
		ll w=lower_bound(sv[k].begin(),sv[k].end(),l)-sv[k].begin();
		Ans=p-w;
		cout<<Ans<<endl;
	}
	return 0;
}

//~ 3
//~ 3 2 49
//~ 9 1 100
//~ 5 55 235
