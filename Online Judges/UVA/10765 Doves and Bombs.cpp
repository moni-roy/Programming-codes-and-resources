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
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

int ts,cs=0,nd,ans,n,q,b,m,a,ds[10010],lw[10010],pr[10010],vs[10010],Ans[10010],ch[10010];
vi adj[10010];
int cnt=0;

void dfs(int u){
    vs[u]=1;
    ds[u]=lw[u]=++cnt;
    int cn=0;
    for(int i=0;i<(int)adj[u].size();i++){
        int v=adj[u][i];

        if(!vs[v]){
            pr[v]=u;
            cn++;
            dfs(v);
            lw[u]=min(lw[u],lw[v]);
            if(pr[u]==-1 && cn>1) {
                    Ans[u]=1;
                    ch[u]++;
            }
            if(lw[v]>=ds[u] && pr[u]!=-1){
                Ans[u]=1;
                ch[u]++;
            }
        }
        else if(v!=pr[u]){
            lw[u]=min(lw[u],ds[v]);
        }
    }
}
int tot;
void bridge(){
    mem(pr,-1);
    mem(vs,0);
    mem(lw,0);
    mem(ds,0);
    mem(Ans,0);
    mem(ch,0);
    tot=0;
    for(int i=0;i<n;i++){
        if(!vs[i]){
            cnt=0;
            tot++;
            dfs(i);
        }
    }
}
struct st
{
    int ii,pg;
    bool operator<(const st &p) const
    {
        if(pg==p.pg) return ii<p.ii;
        return pg>p.pg;
    }
}v[10010];
int main()
{
    while(I2(n,m)==2)
    {
        if(n==0 && m==0 ) break;
        int a,b;
        while(I2(a,b)==2)
        {
            if(a == -1 && b == -1) break;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        bridge();
        ans=0;
        int k=0;
        for(int i=0; i<n; i++)
        {
                v[k].ii=i;
                v[k].pg=tot+ch[i];
                k++;
        }
        sort(v,v+n);
        for(int i=0;i<m;i++)
        {
            printf("%d %d\n",v[i].ii,v[i].pg);
        }
        nl;
        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}
