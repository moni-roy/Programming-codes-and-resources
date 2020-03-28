/* 
 * 1235 - Coin Change (IV)
 * Category: Binary Search
 * */
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

int ts,cs = 0;
int a[1009],n,k;

void sumSet(int p,int e,int c,vector<int> &st){
	st.push_back(c);
	if(p>e) return ;
	sumSet(p+1,e,c+0,st);
	sumSet(p+1,e,c+a[p],st);
	sumSet(p+1,e,c+(a[p]*2),st);
}
int main()
{
	IO;
	//~ freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	cin>>ts;
	while(ts--){
		cin>>n>>k;
		for(int i =0;i<n;i++){
			cin>>a[i];
		}
		vector<int>st1,st2;
		sumSet(0,n/2-1,0,st1);
		sumSet(n/2,n-1,0,st2);
		sort(st2.begin(),st2.end());
		int Ans = 0;
		for(int i=0;i<(int)st1.size();i++){
			int l = 0;
			int h = st2.size()-1;
			int f= 0;
			int t = k - st1[i];
			while(!f && l<=h){
				int md = l+(h-l)/2;
				if(st2[md]==t){
					f=1;
				}
				else if(st2[md]<=t){
					l = md+1;
				}
				else h = md-1;
			}
			if(f) {
				Ans = 1;
				break;
			}
		}
		string s = (Ans==1)?"Yes":"No";
		cout<<"Case "<<++cs<<": "<<s<<endl;
	}
	return 0;
}

