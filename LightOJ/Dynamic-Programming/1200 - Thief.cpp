#include <bits/stdc++.h>

using namespace std;

typedef long long          	ll;
typedef long long unsigned  llu;
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
template <class T> inline string toStr(T t) { stringstream ss; ss<<t; return ss.str();}
template <class T> inline long long toLong(T t) {stringstream ss;ss<<t;long long ret;ss>>ret;return ret;}
template <class T> inline int toInt(T t) {stringstream ss;ss<<t;int ret;ss>>ret;return ret;}

//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra
/*                 _                      */
/*____________|\/||_||\||_________________*/

string buffer;
int INT(){
	getline(cin,buffer);
	return toInt(buffer);
}
int LONG(){
	getline(cin,buffer);
	return toLong(buffer);
}

#define MX 11
#define MD 1e9+7
const int SIZE = 15;
vector<pair<int,pair<int,int> > > v;
int sv[111][10010][3],n,w;
int go(int p,int r,int f){
	if(p>=n) return 0;
	if(r<0) return -99999999;
	int &ret = sv[p][r][f];
	if(ret!=-1) return ret;
	ret=-99999999;
	int a = v[p].F;
	int b = v[p].S.F;
	int c = v[p].S.S;
	if(!f){
		if(b*c<=r){
			ret = max(ret,go(p+1,r-(b*c),0));
			ret = max(ret,go(p,r-(b*c),1));
		}
	}
	else{
		if(c<=r){
			ret = max(ret,go(p,r-c,1)+a);
			ret = max(ret,go(p+1,r-c,0)+a);
		}
	}
	return ret;
}

int main()
{
	IO;
	freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	int ts,cs=0;
	cin>>ts;
	while(ts--){
		cin>>n>>w;
		v.clear();
		for(int i=0;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			v.push_back(make_pair(a,make_pair(b,c)));
		}
		mem(sv,-1);
		int Ans = go(0,w,0);
		cout<<"Case "<<++cs<<": ";
		if(Ans < 0) cout<<"Impossible"<<endl;
		else cout<<Ans<<endl;
	}
	return 0;
}


