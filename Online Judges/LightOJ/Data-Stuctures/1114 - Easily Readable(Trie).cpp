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
template <class T> inline string toStr(T t) { stringstream ss; ss<<t; return ss.str();}
template <class T> inline long long toLong(T t) {stringstream ss;ss<<t;long long ret;ss>>ret;return ret;}
template <class T> inline int toInt(T t) {stringstream ss;ss<<t;int ret;ss>>ret;return ret;}

//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra
/*                 _                      */
/*____________|\/||_||\||_________________*/



string buffer;
int INT(){
	getline(cin,buffer);
	return toInt(buffer);
}
int LONG(){
	getline(cin,buffer);
	return toLong(buffer);
}

#define MX 1000010
#define MD 1e9+7

int ID(char c){
	if(c>='A' && c<='Z') return c-'A';
	return (c-'a'+26);
}

struct trie{
	struct node{
		int cnt;
		int nd[55];
	};
	node nod[100010];
	int nid;
	void Clear(){
		nod[nid].cnt=0;	
		mem(nod[nid].nd,-1);
		nid++;
	}
	void init(){
		nid = 0;
		Clear();
	}
	int build(const string &s,int ok= 0){
		int id = 0;
		for (int i = 0; i < (int)s.size(); i += 1){
			int p = ID(s[i]);
			if(nod[id].nd[p]==-1){
				if(ok) return 0;
				nod[id].nd[p]=nid;
				Clear();
			}
			id = nod[id].nd[p];
		}
		if(!ok) nod[id].cnt++;
		return nod[id].cnt;
	}
};
trie tree;
int main()
{
	IO;
	//~ freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	int ts,cs=0,n,q;
	string s;
	ts=INT();
	while(ts--){
		n=INT();
		int Ans=1;
		tree.init();
		for(int i=0;i<n;i++){
			getline(cin,s);
			if(s.size()>2) sort(s.begin()+1,s.end()-1);
			tree.build(s);
		}
		printf("Case %d:\n",++cs);
		q=INT();
		while(q--){
			getline(cin,s);
			Ans = 1;
			stringstream ss(s);
			string a;
			while(ss>>a){
				if(a.size()>2) sort(a.begin()+1,a.end()-1);
				Ans *= tree.build(a,1);
			}
			printf("%d\n",Ans);
		}
	}
	return 0;
}

