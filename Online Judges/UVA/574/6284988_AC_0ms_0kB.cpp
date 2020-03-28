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

int vs[100],a[100],n;
set<string>st;
string ck(int n)
{
    string ret="";
    while(n>0)
    {
        ret+=(n%10+'0');
        n/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
void go(int p,int r,vector<int> v)
{
    if(r==0)
    {
        int i;
        string s="";
        s=ck(a[v[0]]);
        for(i=1;i<(int)v.size();i++)
        {
            s+="+";
            s+=ck(a[v[i]]);
        }
        st.insert(s);
        return;
    }
    if(p<0) return;
    if(vs[p]) return;
    vs[p]=1;
    go(p-1,r,v);
    if(r>=a[p])
    {
        vector<int>V=v;
        V.push_back(p);
        go(p-1,r-a[p],V);
    }
    vs[p]=0;
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    while(cin>>k>>n && k && n)
    {
        st.clear();
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        vector<int>v;
        mem(vs,0);
        go(n-1,k,v);
        cout<<"Sums of "<<k<<":"<<endl;
        for(set<string>::reverse_iterator it=st.rbegin();it!=st.rend();it++)
        {
            cout<<*it<<endl;
        }
        if(st.size()==0) cout<<"NONE"<<endl;
    }
    return 0;
}
