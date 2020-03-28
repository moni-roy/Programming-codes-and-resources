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

//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

#define MX 1000010
#define MD 1e9+7
string s1,s2,s3;

vi SET(int p)
{
    vi v;
    if(s2[p+1]!='_' ) v.push_back(0);
    if(s2[p]!='|' && s1[p+1]!='_' && s2[p+1]!='_' && s3[p]!='|' && s3[p+1]!='_') v.push_back(1);
    if(s2[p]!='|' && s3[p+2]!='|') v.push_back(2);
    if(s2[p]!='|' && s3[p]!='|') v.push_back(3);
    if(s1[p+1]!='_' && s3[p]!='|' && s3[p+1]!='_') v.push_back(4);
    if(s2[p+2]!='|' && s3[p]!='|') v.push_back(5);
    if(s2[p+2]!='|') v.push_back(6);
    if(s2[p]!='|' && s2[p+1]!='_' && s3[p]!='|' && s3[p+1]!='_') v.push_back(7);
    if(s3[p]!='|') v.push_back(9);
    v.push_back(8);
    return v;
}
int main()
{
    int ts;
    vector<pair<int,string> > sv[1001];
    cin>>ts;
    for(int t=0;t<ts;t++){
        cin>>s1>>s2>>s3;
        vi a = SET(0);
        vi b = SET(4);
        vi c = SET(10);
        vi d = SET(14);
        for(int i=0; i<(int)a.size(); i++)
        {
            int aa = a[i];
            if(aa<6)
            for(int j=0; j<(int)b.size(); j++)
            {
                int bb = b[j];
                for(int k=0; k<(int)c.size(); k++)
                {
                    int cc = c[k];
                    if(cc<6)
                    for(int l=0; l<(int)d.size(); l++)
                    {
                        int dd = d[l];
                        int tt = (aa*10+bb)*60 + (cc*10 + dd);
                        string ss ="";
                        ss+=  (aa+'0');
                        ss+= (bb+'0');
                        ss+= ":";
                        ss += (cc+'0');
                        ss += (dd+'0');
                        sv[t].push_back({tt,ss});
                    }
                }
            }
        }
        sort(sv[t].begin(),sv[t].end());
    }
    cout<<sv[0][sv[0].size()-1].S<<endl;
    int tt = sv[0][sv[0].size()-1].F;
    for(int t = 1;t<ts;t++)
    {
        for(int j=sv[t].size()-1;j>=0; j--)
        {
            if(tt>sv[t][j].F)
            {
                cout<<sv[t][j].S<<endl;
                tt = sv[t][j].F;
                break;
            }
        }
    }
    return 0;
}
