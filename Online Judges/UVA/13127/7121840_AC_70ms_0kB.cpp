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
#define INF 1e9+11

vpii g[10001];
int n,sv[1010][1100],pr[10010];
void dj(int s)
{
//    for(int i=0;i<=n;i++) for(int j=0;j<n;j++) sv[i][j]=(i==j)?0:INF;
//    cout<<"MK"<<endl;
    priority_queue<pii,vpii, greater<pii> >pq;
    pq.push({0,s});
    pr[s]=0;
    while(!pq.empty())
    {
        int u=pq.top().S;
        int w=pq.top().F;
//        cout<<u<<" "<<w<<endl;
        pq.pop();
        for(int i=0;i<(int)g[u].size();i++){
            int v = g[u][i].F;
            int c = g[u][i].S;
            if(pr[u]+c<pr[v])
            {
                pr[v]=pr[u]+c;
                pq.push({pr[v],v});
            }
        }
    }
}

int main()
{
    IO;
    int m,p,a,c,w,b,x[10001],y[10001],Ans[10010];
    while(cin>>n>>m>>b>>p)
    {
        for(int i=0;i<m;i++)
        {
            cin>>a>>c>>w;
            g[a].push_back({c,w});
            g[c].push_back({a,w});
        }
        for(int i=0; i<b; i++)
        {
            cin>>x[i];
        }
        sort(x,x+b);
        for(int i=0;i<p;i++) cin>>y[i];
        int mx=0;
        for(int i=0;i<=n;i++) Ans[i]=INF;
        for(int i=0; i<=n; i++) pr[i]=INF;
        for(int i=0;i<p;i++){
            dj(y[i]);
            for(int j=0;j<b;j++){
                Ans[x[j]] = min(Ans[x[j]],pr[x[j]]);

            }
        }

        for(int i=0;i<b;i++)
        {
            mx=max(mx,Ans[x[i]]);
        }
        int ans=0;
        for(int i=0;i<b;i++)
        {
            if(mx==Ans[x[i]]) ans++;
        }
        if(mx==INF) cout<<ans<< " *\n";
        else cout<<ans<<" "<<mx<<endl;
        int f=0;
        for(int i=0;i<b;i++)
        {
            if(mx==Ans[x[i]])
            {
                if(f) cout<<" "<<x[i];
                else cout<<x[i];
                f=1;
            }
        }
        if(ans!=0) cout<<endl;
        for(int i=0;i<=n;i++) g[i].clear();
    }
    return 0;
}
/*
5 6 2 1
0 1 5
0 2 2
1 3 6
1 4 1
2 3 4
3 4 3
1 4
2
5 4 2 1
0 1 5
0 2 2
1 3 6
2 3 4
1 4
2
5 6 2 2
0 1 5
0 2 2
1 3 6
1 4 1
2 3 4
3 4 3
1 4
2 3
*/
