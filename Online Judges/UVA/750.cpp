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

int ts,a,b,x[100],cnt;

bool ok(int q,int r){
	for(int cl=1;cl<q;cl++){
		if(x[cl]==r||abs(x[cl]-r)==abs(cl-q)){
			return false;
		}
	}
	return true;
}
void FN(int q){
	for(int r=1;r<=8;r++){
		if(ok(q,r)){
			x[q]=r;
			if(q==8&&x[b]==a){
				printf("%2d     ",++cnt);
				for(int i=1;i<=8;i++){
					cout<<" "<<x[i];
				}
				nl;
			}
			else{
				FN(q+1);
			}
		}
	}
}
int main()
{
	cin>>ts;
	while(ts--){
		cin>>a>>b;
		zero(x);
		cnt=0;
		cout<<"SOLN       COLUMN"<<endl;
		cout<<" #      1 2 3 4 5 6 7 8"<<endl;
		nl;
		FN(1);
		if(ts) nl;
	}
	return 0;
}

