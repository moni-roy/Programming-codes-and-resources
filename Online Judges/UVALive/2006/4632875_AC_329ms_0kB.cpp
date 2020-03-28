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
template <class T> inline T power(T a, T b){return (b==0)?1:a*power(a,b-1);}

#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)

//~ cout << fixed << setprecision(20) << p << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

/******************************Let's GO*********************************/

vector<string> v;
vi vv;
map<string,int> mp;
string s;

int main()
{
	while(1){
		int wr=0,mx=0;
		string sss;
		while(getline(cin,s)){
			//~ cout<<s<<endl;
			if(s=="#") break;
			string ss="";
			s+='!';
			for(int i=0;i<(int)s.size();i++){
				if(!isalpha(s[i])){
					if(ss!=""){
						 mp[ss]++;
						if(mp[ss]==1) v.pb(ss);
					}
					if(mx<mp[ss]){
						mx=mp[ss];
						sss=ss;
					}
					ss="";
				}
				else  {
					wr=1;
					s[i]=tolower(s[i]);
					ss+=s[i];
				}
			}
		}
		if(wr==0){
			break;
		}
		//~ for(int i=0;i<(int)v.size();i++){
			//~ vv.pb(mp[v[i]]);
			//~ cout<<mp[v[i]]<<" "<<v[i]<<endl;
		//~ }
		//~ vsort(vv);
		//~ for(int i=0;i<(int)v.size();i++){
			//~ if(mp[v[i]]==vv[vv.size()-1]){
				//~ cout<<mp[v[i]]<<" "<<v[i]<<endl;
				//~ break;
			//~ }
		//~ }					
		//~ cout<<mx<<" "<<sss<<endl;
		printf("%4d ",mx);
		cout<<sss<<endl;
		mp.clear();
		v.clear();
		vv.clear();
	}
	return 0;
}
/*
This is a simple file of test data, which should
not cause your program any trouble. Do note that
it contains several punctuation characters. Of course,
this is not really a problem, because such characters
are treated in the same way as spaces.
#
* 
   2 of
   2 t
   3 abc
* */
