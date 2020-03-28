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
typedef pair<int ,pii>      piii;
typedef vector<pii>         vpii;
typedef vector<piii>        vpiii;

#define pi                  acos(-1.0)
#define S                   second
#define F                   first
#define pb                  push_back
#define MP                  make_pair
#define mem(a,b)            memset(a,b,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define IO                  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define gcd(a,b)            __gcd(a,b)

#define I(a)                scanf("%d",&a)
#define I2(a,b)             scanf("%d%d",&a,&b)
#define L(a)                scanf("%lld",&a)
#define L2(a,b)             scanf("%lld%lld",&a,&b)
#define D(a)                scanf("%lf",&a)

#define SP                  cout<<" ";
#define PI(a)               printf("%d",a)
#define PL(a)               printf("%lld",a)
#define PD(a)               printf("%lf",a)
#define CHK                 cout<<"MK"<<endl

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2;i<=sqrt(double(a));i++){if(a%i==0){return 0;}}return 1;}
template <class T> inline T lcm(T a, T b){return (a/gcd(a,b))*b;}
template <class T> inline T power(T a, T b){return (b==0)?1:a*power(a,b-1);}
template <class T> inline string to_str(T t) { stringstream ss; ss<<t; return ss.str();}

//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

#define MX 1000010
#define MD 1e9+7


ll extendedEcluid(ll a,ll b,ll &x,ll &y){
	if(a==0){
		x = 0;
		y = 1;
		return b;
	}
	ll x1,y1;
	ll d = extendedEcluid(b%a,a,x1,y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return d;
}

int main()
{
	IO;
	//~ freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	ll n;
	while(cin>>n && n){
		ll c1,n1,c2,n2;
		cin>>c1>>n1;
		cin>>c2>>n2;
		ll x,y;
		ll gd = extendedEcluid(n1,n2,x,y);
		if(n%gd){
			cout<<"failed"<<endl;
			continue;
		}
		n /= gd;
		n1 /= gd;
		n2 /= gd;
		ll t1 = ceil(-(dl)x*n*1.0/n2);
		ll t2 = floor((dl)y*n*1.0/n1);
		if(t1>t2){
			cout<<"failed"<<endl;
			continue;
		}
		ll t;
		if(n1*c2 <= c1*n2) t = t1;
		else t = t2;
		cout<<x*n+t*n2<<" "<<y*n-t*n1<<endl;
	}
	return 0;
}


