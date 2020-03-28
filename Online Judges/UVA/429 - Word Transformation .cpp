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

char s[202][15];
vi g[202];
int vs[202];

int BFS(int x,int y){
	zero(vs);
	queue<int>q;
	q.P(x);
	vs[x]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<(int)g[u].size();i++){
			int v=g[u][i];
			if(vs[v]==0){
				vs[v]=vs[u]+1;
				if(v==y) return vs[v];
				q.P(v);
			}
		}
	}
}
bool yes(char a[],char b[]){
	int cnt=0;
	for(int i=0;i<(int)strlen(a);i++){
		if(a[i]!=b[i]) cnt++;
	}
	if(cnt==1) return true;
	return false;
}
int main()
{
	int ts;
	char ss[50],e[15],sss[15];
	//cin>>ts;
	sci(ts);
	getchar();
	while(ts--){
		int i=0;
		map<string,int> mp;
		while(scanf("%s",s[i]))
		{
			mp[s[i]]=i;
			//cout<<mp[s[i]]<<endl;
			if(s[i][0]=='*') break;
			i++;
		}
		for(int j=0;j<i;j++)
		for(int k=j+1;k<i;k++){
			if(strlen(s[k])==strlen(s[j]))
			{
				if(yes(s[k],s[j])){
			//		cout<<k<<" "<<j<<endl;
					g[k].pb(j);
					g[j].pb(k);
				}
			}
		}
		getchar();
		while(gets(sss)){
			//cout<<mp[ss]<<" "<<mp[e]<<endl;
			if(strlen(sss)==0) break;
			
			sscanf(sss,"%s %s",ss,e);
		//	cout<<mp[ss]<<" "<<mp[e]<<endl;
			int Ans=BFS(mp[ss],mp[e]);
			//cout<<ss<<" "<<e<<" "<<Ans<<endl;
			printf("%s %s %d\n",ss,e,Ans);
		}
		if(ts) nl;
		
		for(int k=0;k<=i;k++) g[k].clear();
	}
	return 0;
}

