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

bool vs[10000001];
vl prm,sv;

void F(){
	for(ll i=4;i<100001;i+=2) vs[i]=1;
	for(ll i=3;i*i<100001;i+=2){
		if(!vs[i]){
			for(ll j=i*i;j<100001;j+=i) vs[j]=1;
		}
	}
	prm.PB(2);
	for(ll i=3;i<100001;i+=2){
		if(!vs[i]) prm.PB(i);
	}
}
vector<pair<int,int> > FN(int n){
	vector<pair<int,int> > ret;
	for(int i=0;i<(int)prm.size()&&prm[i]<=sqrt(n);i++){
		int cnt=0;
		if(n%prm[i]==0){
			while(n%prm[i]==0){
				cnt++;
				n/=prm[i];
			}
			ret.PB(MP(prm[i],cnt));
		}
	}
	if(n>1) ret.PB(MP(n,1));
	return ret;
}			
int main()
{
	//F();
	ll n;
	cin>>n;
	if(n==0){
		cout<<10<<endl;
		return 0;
	}
	if(n<9){
		cout<<n<<endl;
		return 0;
	}
	vi v;
	ll nm=n;
	for(int j=9;j>=2;j--){
		if(nm%j==0){
			while(nm%j==0){
				v.PB(j);
				nm/=j;
			}
		}
	}
	if(nm>1) v.PB(nm);
	if(nm>9){
		cout<<-1<<endl;
		return 0;
	}
	vsort(v);
	for(int i=0;i<(int)v.size();i++){
		cout<<v[i];
	}
	cout<<endl;
	
	return 0;
}
