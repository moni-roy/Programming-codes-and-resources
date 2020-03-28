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
int f[10007],n,c1,c2,r1,r2,sv[1010][1010];
string pp;
vpii v;
map<string,int>mp;

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

void kmpf(string t,int ii)
{
    int i=0,j=0;
    int ln=t.size();
    while(i<ln)
    {
        if(t[i]==pp[j])
        {
            i++;
            j++;
            if(j==pp.size())
            {
                sv[ii][i]=mp[pp];
                j=f[j-1];
            }
        }
        else if(j) j=f[j-1];
        else i++;

    }
}
void kmpff(string t,int cc)
{
    int i=0,j=0;
    int ln=t.size();
    while(i<ln)
    {
        if(t[i]==pp[j])
        {
            i++;
            j++;
            if(j==pp.size())
            {
                v.pb({i-r1+1,cc-c1+1});
                j=f[j-1];
            }
        }
        else if(j) j=f[j-1];
        else i++;

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string np,s[1001],p[1001];
    while(cin>>r1>>c1)
    {
        int id=0;
        np="";
        for(int i=0; i<r1; i++)
        {
            cin>>p[i];
            if(mp[p[i]]==0) mp[p[i]]=++id;
            np+=(mp[p[i]]+'0');
        }
        cin>>r2>>c2;
        for(int i=0; i<r2; i++)
        {
            cin>>s[i];
        }
//        cout<<"OK"<<endl;
        map<string,int>::iterator it;
        for(it=mp.begin(); it!=mp.end(); it++)
        {
            pp=it->first;
            n=pp.size();
            mem(f,0);
            kmp();
            for(int i=0; i<r2; i++)
            {
                kmpf(s[i],i);
            }
//            cout<<"OK1"<<endl;
        }
//        for(int i=0;i<=r2;i++){
//            for(int j=0;j<=c2;j++){
//                cout<<sv[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        pp=np;
        mem(f,0);
        kmp();
        for(int j=1; j<=c2; j++)
        {
            string cs="";
            for(int i=0; i<r2; i++)
            {
                cs+=(sv[i][j]+'0');
            }
            kmpff(cs,j);
        }
        vsort(v);
        for(int i=0; i<(int)v.size(); i++)
        {
            cout<<"("<<v[i].first<<","<<v[i].second<<")"<<endl;
        }
        if(v.size()==0) cout<<"NO MATCH FOUND..."<<endl;
        v.clear();
        mp.clear();
        mem(sv,0);
    }
    return 0;
}
