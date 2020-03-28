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

bool vs[32769];
vector<int>prm;
void sieve()
{
    prm.push_back(2);
    for(int i=3; i<=32769; i+=2)
    {
        if(vs[i]==false)
        {
            prm.push_back(i);
            for(int j=i+i; j<=32768; j+=i)
                vs[j]=true;
        }
    }
}
vpii Ans;
int main()
{
    sieve();
    char s[10001];
    int a[10001];
    while(gets(s))
    {
        if(strcmp(s,"0")==0) break;
        stringstream ss;
        ss<<s;
        int t,k=0;
        while(ss>>t)
        {
            a[k++]=t;
        }
        long long int n=1;
        for(int i=0;i<k;i+=2)
        {
            n*=power((ll)a[i],(ll)a[i+1]);
        }
        n--;
        Ans.clear();
        for(int i=0;i<(int)prm.size() && prm[i]*prm[i]<=n;i++)
        {
            if(n%prm[i]==0)
            {
                int cnt=0;
                while(n%prm[i]==0)
                {
                    cnt++;
                    n/=prm[i];
                }
                Ans.pb({prm[i],cnt});
            }
        }
        if(n>1)
        {
            Ans.pb({n,1});
        }
        vsort(Ans);
        for(int i=Ans.size()-1;i>=0;i--){
            if(i==Ans.size()-1) cout<<Ans[i].F<<" "<<Ans[i].S;
            else cout<<" "<<Ans[i].F<<" "<<Ans[i].S;
        }
        cout<<endl;
    }
    return 0;
}
