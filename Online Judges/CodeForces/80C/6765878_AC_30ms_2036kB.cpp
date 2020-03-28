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

#define MX 100010
#define MD 1e9+7

int a[5],Ans,ans,nm[10],sv[10][10];
msi mp;

void cal()
{
	int bl[5];
	bl[0]=bl[1]=bl[2]=bl[3]=0;
	
	for(int i=1;i<=7;i++) bl[nm[i]] = 1;
	if(bl[0]==0 || bl[1] == 0 || bl[2] == 0) return ;
	
	int cn[5];
	cn[0]=cn[1]=cn[2]=cn[3]=0;
	
	for(int i=1;i<=7;i++){
		cn[nm[i]]++;
	}
	
	int mn = INT_MAX, mx = INT_MIN;
	for(int i=0;i<3;i++){
		int df = a[i]/cn[i];
		mn = min(mn,df);
		mx = max(mx,df);
	}
	
	int tl = 0;
	for(int i=1;i<=7;i++){
		for(int j=1;j<=7;j++){
			if(nm[i]==nm[j]) tl += sv[i][j];
		}
	}
	
	if(mx-mn<Ans || ( mx-mn == Ans && tl>ans)){
		Ans = mx-mn;
		ans = tl;
	}
}

void go(int x){
	if(x>7){
		cal();
		return ;
	}
	for(int i=0;i<3;i++){
		nm[x]=i;
		go(x+1);
	}
	return ;
}

int main()
{
	IO;
	//~ freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	int n; cin>>n;
	int k=0;
	for(int i=0;i<n;i++){
		string s,ss,t;
		cin>>s>>t>>ss;
		if(mp[s]==0) mp[s]=++k;
		if(mp[ss]==0) mp[ss]=++k;
		sv[mp[s]][mp[ss]]=1;
	}
	cin>>a[0]>>a[1]>>a[2];
	Ans = INT_MAX;
	ans = INT_MIN;
	go(1);
	cout<<Ans<<" "<<ans<<endl;
	return 0;
}
