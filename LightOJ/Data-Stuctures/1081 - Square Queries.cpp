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
/*                 _                      */
/*____________|\/||_||\||_________________*/

int ts,n,cs=0,a,b,c,q;
int tr[1700][1700];
void update(int *tre,int p,int l,int r,int x,int y){
	if(l>x || r<x) return;
	if(l==r && l==x){
		tre[p]=y;
		return ;
	}
	int md = (l+r)/2;
	update(tre,p*2,l,md,x,y);
	update(tre,p*2+1,md+1,r,x,y);
	tre[p]=max(tre[p*2],tre[p*2+1]);
}

int query(int *tre,int p,int l,int r,int x,int y){
	if(l>=x && r<=y) return tre[p];
	int md = (l+r)/2;
	int ret = -1;
	if(md>=x) ret =max(ret, query(tre,p*2,l,md,x,y));
	if(md<y) ret =max(ret, query(tre,p*2+1,md+1,r,x,y));
	return ret;
}
int main()
{
	//~ IO;
	//~ freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	I(ts);
	while(ts--){
		mem(tr,-1);
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&a);
				update(tr[i],1,1,n,j,a);
			}
		}
		printf("Case %d:\n",++cs);
		while(q--){
			scanf("%d%d%d",&a,&b,&c);
			int x,y;
			x = a+c-1;
			y = b+c-1;
			int Ans = -1;
			for(int i=a;i<=x;i++){
				Ans = max(Ans,query(tr[i],1,1,n,b,y));
			}
			printf("%d\n",Ans);
		}
	}	
	return 0;
}

