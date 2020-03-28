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

int n,vs[100][100][100];
vi v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0; i<=20; i++)
    {
        v.pb(i);
        v.pb(i*2);
        v.pb(i*3);
    }
    v.pb(50);
    vsort(v);
    v.erase(unique(v.begin(),v.end()),v.end());
    while(cin>>n)
    {
        if(n<=0) break;
        int l=v.size();
        int c=0,p=0;
        mem(vs,0);
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<l;j++)
            {
                for(int k=0;k<l;k++)
                {
                    int t=v[i]+v[j]+v[k];
                    if(t==n)
                    {
                        p++;
                        if(vs[v[i]][v[j]][v[k]]==0)
                        {
                            c++;
                            vs[v[j]][v[i]][v[k]]=1;
                            vs[v[j]][v[k]][v[i]]=1;
                            vs[v[k]][v[j]][v[i]]=1;
                            vs[v[k]][v[i]][v[j]]=1;
                            vs[v[i]][v[j]][v[k]]=1;
                            vs[v[i]][v[k]][v[j]]=1;
                        }
                    }
                }
            }
        }
        if(!c && !p)
        {
            cout<<"THE SCORE OF "<<n<<" CANNOT BE MADE WITH THREE DARTS."<<endl;
        }
        else{
            cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<n<<" IS "<<c<<"."<<endl;
            cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<n<<" IS "<<p<<"."<<endl;
        }
        cout<<"**********************************************************************"<<endl;
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
