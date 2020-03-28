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

template <class T> inline T BMOD(T p,T e,T m)
{
    T ret=1;
    while(e)
    {
        if(e&1) ret=(ret*p)%m;
        p=(p*p)%m;
        e>>=1;
    }
    return (T)ret;
}
template <class T> inline T MODINV(T a,T m)
{
    return BMOD(a,m-2,m);
}
template <class T> inline T isPrime(T a)
{
    for(T i=2; i<=sqrt(double(a)); i++)
    {
        if(a%i==0)
        {
            return 0;
        }
    }
    return 1;
}
template <class T> inline T lcm(T a, T b)
{
    return (a/gcd(a,b))*b;
}
template <class T> inline T power(T a, T b)
{
    return (b==0)?1:a*power(a,b-1);
}
#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)
//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra
/******************************Let's GO*********************************/
#define inf 999999999
int f[400007],ln,n,ts,d;
vi Ans;
string pp,s,a,w,ss;
map<char,int>mp;
void kmp()
{
    int k=0;
    f[0]=0;
    int i=1;
    while(i<n)
    {
        if(pp[k]==pp[i])
        {
            f[i]=++k;
            i++;
        }
        else if(k) k=f[k-1];
        else
        {
            i++;
        }
    }
}
int kmpf()
{
    int ret=0;
    int i=0,j=0;
    while(i<ln)
    {
        if(s[i]==pp[j])
        {
            j++;
            i++;
            if(j==n)
            {
                ret++;
                j=f[j-1];
            }
        }
        else if(j) j=f[j-1];
        else i++;
    }
    return ret;
}
string fun(string t,int ii)
{
    if(ii==0) return t;
    string ret="";
    for(int i=0; i<t.size(); i++)
    {
        int tt=(mp[t[i]]-ii+d)%d;
        ret+=(a[tt]);
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>ts;
    while(ts--)
    {
        cin>>a>>w>>ss;
        pp=w;
        n=pp.size();
        kmp();
        d=a.size();
        ln=ss.size();
        for(int i=0;i<a.size();i++){
            mp[a[i]]=i;
        }
        for(int i=0; i<a.size(); i++)
        {
            string cs=fun(ss,i);
            s=cs;
//            cout<<cs<<endl;
            int ret=kmpf();
            if(ret==1){
                Ans.pb(i);
            }
        }
        if(Ans.size()==0){
            cout<<"no solution"<<endl;
        }
        else if(Ans.size()==1){
            cout<<"unique: "<<Ans[0]<<endl;
        }
        else{
            vsort(Ans);
            cout<<"ambiguous:";
            for(int i=0;i<(int)Ans.size();i++){
                cout<<" "<<Ans[i];
            }
            cout<<endl;
        }
        Ans.clear();
        mem(f,0);
    }
    return 0;
}
