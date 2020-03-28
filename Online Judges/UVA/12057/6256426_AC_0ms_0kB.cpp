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
typedef pair<int,pii>       piii;
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

#define READ(input)    freopen(input,"r",stdin)
#define WRITE(output)  freopen(output,"w",stdout)
//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra
/******************************Let's GO*********************************/

dl x[101],res[101][101];
int mid[101][101],l,k;
bool vs[101][101];

dl Cost(int l,int r)
{
    return x[r]-x[l-1];
}

void go(int s,int e)
{
    if(s>e) return ;
    if(s==e){
        res[s][e]=0;
        mid[s][s]=s;
        return ;
    }
    if(vs[s][e]) return;
    vs[s][e]=1;
    go(s,e-1);
    go(s+1,e);
    dl ret=1000000007.0;
    int id=-1;
    for(int i=mid[s][e-1];i<=mid[s+1][e];i++){
        dl tp=res[s][i]+res[i+1][e]+Cost(s,e);
        if(ret>tp+1e-10){
            ret=tp;
            id=i;
        }
    }
    res[s][e]=ret;
    mid[s][e]=id;
    return;
}
void print(int s,int e,string S)
{
    if(s==e){
        cout<<S<<endl;
        return;
    }
    int id=mid[s][e];
    print(s,id,S+"0");
    print(id+1,e,S+"1");
    return ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cs=0;
    while(cin>>l)
    {
        if(l==0) break ;
        if(cs) cout<<endl;
        cs++;
        for(int i=1; i<=l; i++)
        {
            cin>>x[i];
            x[i]+=x[i-1];
        }
        mem(vs,0);
        go(1,l);
        cout<<fixed<<setprecision(4)<<res[1][l]<<endl;
        print(1,l,"");
    }
    return 0;
}
