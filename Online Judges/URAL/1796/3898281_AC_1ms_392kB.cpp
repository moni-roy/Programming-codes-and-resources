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

int main()
{
	//10, 50, 100, 500, 1000, and 5000
	ll sv[]={10, 50, 100, 500, 1000,5000};
	ll tl,c[10],tm,cnt,fs;
	for(ll i=0;i<6;i++) cin>>c[i];
	cin>>tm;
	tl=0;
	ll mn=0,flg=0;
	for(int i=0;i<6;i++){
		tl+=(c[i]*sv[i]);
		if(c[i]&&flg==0)
		{
			mn=sv[i];
			flg=1;
		}
	}
	fs=tl/tm;
	cnt=(tl-mn)/tm;
	//for(ll i=fs-1;i>0;i--){
	//	ll t=i*tm;
	//	ll d=tl-t;
	//	ll flg=0;
	//	for(ll j=0;j<5;j++){
	//		if(c[j]>0){
	//			if(d>=sv[j]){
	//				flg=1;
	//				break;
	//			}
	//		}
	//	}
	//	if(flg) break;
	//	cnt++;
	//}
	cout<<fs-cnt<<endl;
	for(ll i=cnt+1;i<=fs;i++){
		if(i!=fs) cout<<i<<" ";
		else cout<<i<<endl;
	}
	return 0;
}
