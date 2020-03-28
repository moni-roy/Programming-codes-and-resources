#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
typedef double dl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef pair<int,pii> piii;
typedef vector<pii> vii;
typedef vector<piii> viii;

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
template <class T> inline string to_str(T t)
{
    stringstream ss;
    ss<<t;
    return ss.str();
}
///-------------------------------------

const int MX = 1e5+20;
int n,one[MX],two[MX],on[MX],tw[MX],a;
int main()
{
    ios_base::sync_with_stdio(0);
    int i1=0,i2=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a;
        if(a==1) one[++i1]=i;
        else two[++i2]=i;
        on[i]=i1;
        tw[i]=i2;
    }
    vii ans;
    int tt;
    for(int i=1; i<=n; i++)
    {
        int fs = 0;
        int ss = 0;
        int t = i,ii=0,id1=0,id2=0;
        int f = 0;
        while(ii<=n)
        {
            int t1,t2;
            if(id1+t<=i1) t1 = one[id1+t];
            else t1=n+10;
            if(id2+t<=i2) t2 = two[id2+t];
            else t2=n+10;
            int c = min(t1,t2);
//            cout<<c<<endl;
//            cout<<c<<"++++"<<n<<endl;
            if(c>n)
            {
                f=1;
                break;
            }
            id1 = on[c];
            id2 = tw[c];
//            cout<<t<<"--> " <<id1<<" "<<id2<<" "<<c<<endl;
            if(t1<t2)
            {
                fs++;
            }
            else ss++;
            if(c==n)
            {
                if(fs>ss && t2<t1) f=1;
                if(ss>fs && t1<t2) f=1;
                if(ss==fs) f=1;
//                cout<<f<<" "<<fs<<" "<<ss<<endl;
                break;
            }
            if(f) break;
            ii = c;
        }
        if(!f)
        {
            ans.push_back({max(fs,ss),i});
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto x: ans)
    {
        cout<<x.F<<" "<<x.S<<endl;
    }
    return 0;
}
/*
7
1 1 1 2 2 1 1

3
1 5
2 2
5 1

8
1 2 1 2 2 1 2 1

1
2 2



*/

