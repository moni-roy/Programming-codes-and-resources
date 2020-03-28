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

#define MX 100010
#define MD 1e9+7

int par[MX],ran[MX];
struct unionFind{
	unionFind(int n){
		for(int i=0;i<=n;i++){
			par[i]=i;
			ran[i]=1;
		}
	}
	int root(int x){
		return (x==par[x])?x:par[x]=root(par[x]);
	}
	int comSize(int x){
		int y = root(x);
		return ran[y];
	}
	void connect(int x,int y){
		int xx = root(x);
		int yy = root(y);
		if(xx==yy) return;
		int rx = ran[xx];
		int ry = ran[yy];
		if(rx>=ry) par[yy]=xx,ran[xx]+=ran[yy];
		else par[xx]=yy,ran[yy]+=ran[xx];
	}
};



int vs[MX],com[MX],sv[MX];
vi g[MX];

bool lucky(int x){
	while(x>0){
		int t = x%10;
		if(t==4 || t==7) {}
		else return false;
		x/=10;
	}
	return true;
}
void dfs(int u,int k){
	com[k]++;
	vs[u]=k;
	for(auto v:g[u]){
		if(!vs[v]){
			dfs(v,k);
		}
	}
}

int main()
{
	IO;
	//~ freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	//~ cout<<"Ready to go!"<<endl;
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(!lucky(c))
		{
			g[a].pb(b);
			g[b].pb(a);
		}
	}
	int k=1;
	mem(vs,0);
	for(int i=1;i<=n;i++){
		if(!vs[i]) dfs(i,k++);
	}
	for(int i=1;i<=n;i++){
		sv[i]=com[vs[i]];
	}
	ll Ans = 0;
	for(int i=1;i<=n;i++){
		ll t = n-sv[i];
		Ans += (t*(t-1));
	}
	cout<<Ans<<endl;
	return 0;
}
