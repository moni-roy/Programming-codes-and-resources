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
	I_O;
	int a,b,c,d,x,y,z,ta,tb,tc,td,tx,ty,tz;
	cin>>a>>b>>c>>d>>x>>y>>z;
	if(x==(b+c+d)%2 && y==(a+c+d)%2 && z==(a+b+d)%2){
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<x<<" "<<y<<" "<<z<<endl;
	}
	else{
		ta=(a+1)%2;
		tb=(b+1)%2;
		tc=(c+1)%2;
		td=(d+1)%2;
		tx=(x+1)%2;
		ty=(y+1)%2;
		tz=(z+1)%2;
		
		if(x==(b+c+d)%2 && y==(ta+c+d)%2 && z==(ta+b+d)%2){
			cout<<ta<<" "<<b<<" "<<c<<" "<<d<<" "<<x<<" "<<y<<" "<<z<<endl;
		}
		
		else if(x==(tb+c+d)%2 && y==(a+c+d)%2 && z==(a+tb+d)%2){
			cout<<a<<" "<<tb<<" "<<c<<" "<<d<<" "<<x<<" "<<y<<" "<<z<<endl;
		}
		
		else if(x==(b+tc+d)%2 && y==(a+tc+d)%2 && z==(a+b+d)%2){
			cout<<a<<" "<<b<<" "<<tc<<" "<<d<<" "<<x<<" "<<y<<" "<<z<<endl;
		}
		
		else if(x==(b+c+td)%2 && y==(a+c+td)%2 && z==(a+b+td)%2){
			cout<<a<<" "<<b<<" "<<c<<" "<<td<<" "<<x<<" "<<y<<" "<<z<<endl;
		}
		
		else if(tx==(b+c+d)%2 && y==(a+c+d)%2 && z==(a+b+d)%2){
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<tx<<" "<<y<<" "<<z<<endl;
		}
		
		else if(x==(b+c+d)%2 && ty==(a+c+d)%2 && z==(a+b+d)%2){
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<x<<" "<<ty<<" "<<z<<endl;
		}
		
		else if(x==(b+c+d)%2 && y==(a+c+d)%2 && tz==(a+b+d)%2){
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<x<<" "<<y<<" "<<tz<<endl;
		}
	}
	return 0;
}
