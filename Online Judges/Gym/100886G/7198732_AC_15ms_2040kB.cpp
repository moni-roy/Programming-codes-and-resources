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

ll sv[22][3][3][3];
ll a,b,f[22],s[33],k;
ll go(int p,int f1,int f2,int ff){
	if(p>=k) return 1;
	ll &ret = sv[p][f1][f2][ff];
	if(ret!=-1) return ret;
	ret=0;
	int l=f[p];
	int h=s[p];
	if(f1) {
		l=0;
	}
	if(f2) h=9;
	for(int i=l;i<=h;i++){
		if(!ff && i==0)
		{
			ret = max(ret,go(p+1,f1|(i>f[p]),f2|(i<s[p]),0));
		}
		else{
			ret = max(ret,i*go(p+1,f1|(i>f[p]),f2|(i<s[p]),1));
		}
	}
	return ret;
}
void print_dp(int p,int f1,int f2,int ff){
	if(p>=k){
		cout<<endl;
		exit(0);
	 }
	int l=f[p];
	int h=s[p];
	if(f1) {
		l=0;
	}
	if(f2) h=9;
	for(int i=l;i<=h;i++){
		if(!ff && i==0)
		{
			if(go(p,f1,f2,ff)==go(p+1,f1|(i>f[p]),f2|(i<s[p]),0)) print_dp(p+1,f1|(i>f[p]),f2|(i<s[p]),0);
		}
		else{
			if(go(p,f1,f2,ff)==i*go(p+1,f1|(i>f[p]),f2|(i<s[p]),1)){
				cout<<i;
				print_dp(p+1,f1|(i>f[p]),f2|(i<s[p]),1);
			}
		}
	}
	return;
}
int main()
{
	IO;
	//~ freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	
	cin>>a>>b;
	int i=0;
	k=0;
	while(a){
		f[i++]=a%10;
		a/=10;
	}
	while(b){
		s[k++]=b%10;
		b/=10;
	}
	if(k!=i){
		for(int j=i;j<k;j++) f[j]=0;
	}
	reverse(f,f+k);
	reverse(s,s+k);
	mem(sv,-1);
	go(0,0,0,0);
	print_dp(0,0,0,0);
	return 0;
}
