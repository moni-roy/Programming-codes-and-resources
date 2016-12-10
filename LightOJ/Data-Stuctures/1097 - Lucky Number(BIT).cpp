/* 
 * 1097 - Lucky Number
 * Category: Binary Search Tree, Segment Tree, Interval Tree.
 * */
#include <bits/stdc++.h>

using namespace std;

//~ typedef long long          	ll;
typedef long long unsigned 	ll;
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

const int MX = 2097152; // Not sure size should this(other give WA)
#define MD 1e9+7
int tr[(MX+5)];

void update(int p,int x){
   while(p<=MX){
	   tr[p]+=x;
	   p += (p&(-p));
   }
}
int query(int p){
	int ret = 0;
    while(p>0){
		ret+=tr[p];
		p -= (p&(-p));
	}
	return ret;
}
int find(int cumFre){
    int idx = 0;
    int bitMask = MX;
    cumFre--;
    while ((bitMask > 0) && (idx <= MX)){
        int tIdx = idx + bitMask;
        if ( tIdx<=MX && cumFre >= tr[tIdx]){ 
            idx = tIdx;
            cumFre -= tr[tIdx]; 
        }
        bitMask >>= 1;
    }
     return idx+1;
}
int ts,n,cs,Lucky[100012];
int main()
{
	//~ freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	for(int i=1;i<=MX;i+=2) update(i,1);
	Lucky[1]=1;
	int id =2,pr = 1;
	for(int i=3;i<=1429433;i+=2){
		
		int t = query(i);
		int k = t - pr;
		if(k){
			Lucky[id++]=i;
			int j = (1429500/i)*i;
			while(j>=i){
				int tt = find(j);
				update(tt,-1);
				j-=i;
			}
			pr = t;
		}
	}
	I(ts);
	while(ts--){
		I(n);
		printf("Case %d: %d\n",++cs,Lucky[n]);
	}
	return 0;
}
