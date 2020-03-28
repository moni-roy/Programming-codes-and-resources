/* * * * * * * * * * * *
 * :Krishna (MRoy)     *
 * :JU                 *
 * :mkroy.cs@gmail.com *
 * * * * * * * * * * * */
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
typedef pair<int,pii>      piii;
typedef vector<pii>         vpii;
typedef vector<piii>        vpiii;
//~ Define
#define pi                  acos(-1.0)
#define S                   second
#define F                   first
#define pb                  push_back
#define MP                  make_pair
#define P                   push
#define mem(a,b)            memset(a,b,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define gcd(a,b)            __gcd(a,b)
//~ Input
#define I(a)                scanf("%d",&a)
#define I2(a,b)             scanf("%d%d",&a,&b)
#define I3(a,b,c)           scanf("%d%d%d",&a,&b,&c)
#define L(a)                scanf("%lld",&a)
#define L2(a,b)             scanf("%lld%lld",&a,&b)
#define L3(a,b,c)           scanf("%lld%lld%lld",&a,&b,&c)
#define D(a)                scanf("%lf",&a)
//~ Output
#define nl                  puts("")
#define sp                  printf(" ");
#define SP                  cout<<" ";
#define tcase(cs)           printf("Case %d:",++cs)
#define TC(cs)              cout<<"Case "<<++cs<<":"
#define PI(a)               printf("%d",a)
#define PL(a)               printf("%lld",a)
#define PD(a)               printf("%lf",a)

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2; i<=sqrt(double(a)); i++){if(a%i==0){return 0;}}return 1;}
template <class T> inline T lcm(T a, T b){return (a/gcd(a,b))*b;}
template <class T> inline T power(T a, T b){return (b==0)?1:a*power(a,b-1);}

#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)
//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra
/******************************Let's GO*********************************/


#define MX  2000007
#define MOD 1000000007
#define INF (1<<30)-1+(1<<30)
#define eps 1e-9

#define base ((1<<l)-1)
#define lft (idx<<1)
#define rgt (lft|1)
#define mid ((l+r)>>1)

/// Hashing Bases & MOD
///           0123456789
#define Base1 10000019ll
#define Base2 10000079ll
#define Base3 10000103ll
#define MOD1  1000000007ll
#define MOD2  1000000009ll
#define MOD3  1000000021ll
#define LOGX  17

string p;
int f[2000010],n,ln;
ll bs[MX>>1],h1[MX>>1],h2[MX>>1];


void kmp(){
    int i=1,j=0;
    f[0]=0;

    while(i<n){
        if(p[i]==p[j]){
            f[i++]=++j;
        }
        else if(j) j=f[j-1];
        else f[i]=0,i++;
    }
}
ll check(ll *h,int x,int y){
    ll ret=0;
    if(x<=y){
        int l=y-x+1;
        ret=(h[y]-(h[x-1]*bs[l])%MOD1)%MOD1;
        ret+=MOD1;
    }
    return ret%MOD1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    getline(cin,a);
    getline(cin,b);
    int la=a.size();
    int lb=b.size();
    if(la!=lb){

        cout<<-1<<" "<<-1<<endl;
        return 0;
    }
    p=a;
    reverse(all(p));
    p+=(char)(30);
    p+=b;
    n=p.size();
//    cout<<p<<endl;
    kmp();

    bs[0]=1ll;
    for(int i=1;i<MX/2;i++){
        bs[i]=(bs[i-1]*Base1)%MOD1;
    }
    h1[0]=0;
    for(int i=0;i<la;i++){
        int x=a[i]-'a'+1;
        h1[i+1]=(h1[i]*Base1+x)%MOD1;
    }
    h2[0]=0;
    for(int i=0;i<lb;i++){
        int x=b[i]-'a'+1;
        h2[i+1]=(h2[i]*Base1+x)%MOD1;
    }
    int x=-1,y=-1;
    for(int i=0,j=la-1;i<la-1;i++,j--){
        if(a[i]!=b[j]) break;
        int ii=la+1+j-1;
        int k=f[ii];
        int x1=0,y1=j-k-1;
        int x2=i+1,y2=i+y1+1;
//        cout<<k<<" "<<x2<<" "<<y2<<" "<<x1<<" "<<y1<<endl;
        if(check(h1,x2+1,y2+1)==check(h2,x1+1,y1+1)){
            x=x2-1;
            y=y2+1;
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
