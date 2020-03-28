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

int main()
{
	ll n,ts=0,tm,t,tc;
	while(cin>>n){
		if(n==0) break;
		if(ts) nl;
		ts++;
		int flg=0;
		for(int i=0;i<=9;i++){
			for(int j=0;j<=9;j++){
				if(i==j) continue;
				for(int k=0;k<=9;k++){
					if(k==j||k==i) continue;
					for(int l=0;l<=9;l++){
						if(k==l||l==j||l==i) continue;
						for(int m=0;m<=9;m++){
							if(m==l||m==k||m==j||m==i) continue;
							tm=m+l*10+k*100+j*1000+i*10000;
							t=tm*n;
							tc=t;
							if(t>99999) continue;
							int cnt=0,zro=0;
							if(i==0||j==0||k==0||l==0||m==0) zro=1;
							set<int>st;
							st.insert(i);
							st.insert(j);
							st.insert(k);
							st.insert(l);
							st.insert(m);
							while(t>0){
								st.insert(t%10);
								cnt++;
								if(int(t%10)==0) zro=1;
								t/=10;
				
							}
							if((st.size()==10&&cnt==5)){
								cout<<tc<<" / "<<i<<j<<k<<l<<m<<" = "<<n<<endl;
								flg=1;
							}
							else if(cnt==4&&st.size()==9&&!zro){
								cout<<0<<tc<<" / "<<i<<j<<k<<l<<m<<" = "<<n<<endl;
								flg=1;
							}
						}
					}
				}
			}
		}
		if(!flg) cout<<"There are no solutions for "<<n<<"."<<endl;
	}
	return 0;
}
