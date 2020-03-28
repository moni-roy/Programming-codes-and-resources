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
//~ Define
#define pi                  acos(-1.0)
#define S                   second
#define F                   first
#define pb                  push_back
#define MP                  make_pair
#define P                   push
#define zero(a)             memset(a,0,sizeof a)
#define minus(a)            memset(a,-1,sizeof a)
#define setinf(a)           memset(a,126,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define I_O                 ios_base::sync_with_stdio(0); cin.tie(0);
#define gcd(a,b)            __gcd(a,b)
//~ Input                   
#define sci(a)              scanf("%d",&a)
#define scii(a,b)           scanf("%d%d",&a,&b)
#define sciii(a,b,c)        scanf("%d%d%d",&a,&b,&c)
#define scl(a)              scanf("%lld",&a)
#define scll(a,b)           scanf("%lld%lld",&a,&b)
#define sclll(a,b,c)        scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a)              scanf("%lf",&a)
//~ Output                  
#define endl                '\n'
#define nl                  puts("")
#define sp                  printf(" ");
#define tcase(cs)           printf("Case %d:",++cs)
#define pri(a)              printf("%d",a)
#define prl(a)              printf("%lld",a)
#define prd(a)              printf("%lf",a)

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2;i<=sqrt(double(a));i++){if(a%i==0){return 0;}}return 1;}
template <class T> inline T lcm(T a, T b){return (a/gcd(a,b))*b;}

#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)

//~ cout << fixed << setprecision(20) << p << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

/******************************Let's GO*********************************/
int dx[10][4]={{0,0,0,1},{0,0,0,-1},{0,0,1,0},{0,0,-1,0},
				{0,1,0,0},{0,-1,0,0},{1,0,0,0},{-1,0,0,0}};
struct st{
	int a,b,c,d;
}s,e,t;

bool vs[11][11][11][11];
int sv[11][11][11][11];

void bfs(st sr){
	sv[sr.a][sr.b][sr.c][sr.d]=0;
	vs[sr.a][sr.b][sr.c][sr.d]=1;
	queue<st>q;
	q.P(sr);
	while(!q.empty()){
		st tm=q.front();q.pop();
		if(tm.a==e.a && tm.b==e.b && tm.c==e.c && tm.d==e.d ){
					cout<<sv[tm.a][tm.b][tm.c][tm.d]<<endl;
					return ;
		}
		for(int i=0;i<8;i++){
			t.a=(tm.a+dx[i][0]+10)%10;
			t.b=(tm.b+dx[i][1]+10)%10;
			t.c=(tm.c+dx[i][2]+10)%10;
			t.d=(tm.d+dx[i][3]+10)%10;
			if(!vs[t.a][t.b][t.c][t.d]){
				sv[t.a][t.b][t.c][t.d]=1+sv[tm.a][tm.b][tm.c][tm.d];
				vs[t.a][t.b][t.c][t.d]=1;
				q.P(t);
			}
		}
	}
	cout<<-1<<endl;
}
int main()
{
	int ts,n,a,b,c,d;
	cin>>ts;
	while(ts--){
		zero(vs);
		zero(sv);
		cin>>s.a>>s.b>>s.c>>s.d;
		cin>>e.a>>e.b>>e.c>>e.d;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a>>b>>c>>d;
			vs[a][b][c][d]=1;
		}
		bfs(s);
	}
	return 0;
}
