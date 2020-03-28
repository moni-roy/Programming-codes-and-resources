
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

#define MX 300003
const ll MD = 1e9+7;

int mn[4*MX],a[MX],ar[MX],lz[4*MX];

void build(int p,int s,int e)
{
    if(s==e){
        mn[p]=a[s];
        return ;
    }
    int m = (s+e)>>1;
    int l = 2*p;
    int r = l+1;
    build(l,s,m);
    build(r,m+1,e);
    mn[p]=min(mn[l],mn[r]);
}
inline void lazy(int p,int s,int e)
{
    mn[s]+=lz[p];
    mn[e]+=lz[p];
    lz[s]+=lz[p];
    lz[e]+=lz[p];
    lz[p]=0;
}
void update(int p,int s,int e,int x,int y,int c)
{
    if(s==x && y==e)
    {
        mn[p]+=c;
        lz[p]+=c;
        return ;
    }
    int m = (s+e)>>1;
    int l = 2*p;
    int r = l+1;
    lazy(p,l,r);
    if(y<=m) update(l,s,m,x,y,c);
    else if(x>m) update(r,m+1,e,x,y,c);
    else{
        update(l,s,m,x,m,c);
        update(r,m+1,e,m+1,y,c);
    }
    mn[p]=min(mn[l],mn[r]);
}
int query(int p,int s,int e,int x,int y)
{
    if(s==x && e==y){
        return mn[p];
    }
    int m = (s+e)>>1;
    int l = 2*p;
    int r = l+1;
    lazy(p,l,r);
    if(m>=y) return query(l,s,m,x,y);
    else if(m<x) return query(r,m+1,e,x,y);
    else{
        return min(query(l,s,m,x,m),query(r,m+1,e,m+1,y));
    }
    mn[p]=min(mn[l],mn[r]);
}
int main()
{
    IO;
    int n,q,x;
    string s;
    cin>>n>>q;
    cin>>s;
    set<int>st;
    for(int i=1; i<=n; i++)
    {
        ar[i]=(s[i-1]=='(')?1:-1;
    }
    for(int i=1; i<=n; ++i) a[i]=ar[i]+a[i-1];
    build(1,1,n);
    while(q--){
        cin>>x;
//        cout<<s[x-1]<<endl;
        if(x==1 || x==n)
        {
            cout<<x<<endl;
            continue;
        }
        if(s[x-1]=='(')
        {
            s[x-1]=')';
            update(1,1,n,x,n,-2);
            int l = 1;
            int r = x;
            int id = 1;
            while(l<=r)
            {
                int m = (l+r)/2;
                int ret = query(1,1,n,m,m);
                if(ret==m)
                {
                    l = m+1;
                    id = m;
                }
                else r = m-1;
            }
            cout<<id+1<<endl;
            s[id]='(';
            update(1,1,n,id+1,n,2);
        }
        else{
            s[x-1]='(';
            update(1,1,n,x,n,2);
            int l = 1;
            int r = n;
            int id = 1;
            while(l<=r)
            {
                int m = (l+r)/2;
                int ret = query(1,1,n,m,n);
                if(ret>=2)
                {
                    r = m-1;
                    id = m;
                }
                else l = m+1;
            }
            cout<<id<<endl;
            update(1,1,n,id,n,-2);
            s[id-1]=')';
        }
    }
    return 0;
}
