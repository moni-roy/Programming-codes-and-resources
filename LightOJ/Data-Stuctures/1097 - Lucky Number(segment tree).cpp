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

#define MX 1429500
#define MD 1e9+7
int tr[3*MX+10];

void ini(int p,int l,int r){
    if(l==r){
        tr[p]=l&1;
        return ;
    }
    int md=(l+r)/2;
    ini(2*p,l,md);
    ini(2*p+1,md+1,r);
    tr[p]=tr[p*2]+tr[p*2+1];
}
void update(int p,int l,int r,int x){
    if(l==r){
        tr[p]=0;
        return ;
    }
    int md=(l+r)>>1;
    if(tr[2*p]>=x) update(2*p,l,md,x);
    else update(2*p+1,md+1,r,x-tr[2*p]);
    tr[p]=tr[p*2]+tr[p*2+1];
}
int query(int p,int l,int r,int x){
    if(l==r){
        return l;
    }
    int md=(l+r)>>1;
    if(tr[2*p]>=x) return query(2*p,l,md,x);
    return query(2*p+1,md+1,r,x-tr[2*p]);
}

int main()
{
	IO;
	freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	int ts,n,cs,Lucky[100012];
	ini(1,1,MX);
	Lucky[1]=1;
	for(int i=2;i<100010;i++){
		int t = query(1,1,MX,i);
		Lucky[i]=t;
		int j = MX/t;
		j*=t;
		for(;j>=t;j-=t){
			update(1,1,MX,j);
		}
	}
	cin>>ts;
	while(ts--){
		cin>>n;
		cout<<"Case "<<++cs<<": "<<Lucky[n]<<endl;
	}
	return 0;
}

