//~ 1152 - Hiding Gold
#include <bits/stdc++.h>

using namespace std;

typedef long long          	ll;
typedef long long unsigned  llu;
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

#define MX 11
#define MD 1e9+7
const int SIZE = 15;

struct PT{
	int x,y,id;
	PT(){}
	PT(int _x,int _y){x=_x;y=_y;}
	bool operator < (const PT &p) const{ return y == p.y? x<p.x:y<p.y;}
	PT operator + (const PT &p) const { return PT( x + p.x, y + p.y);}
	PT operator - (const PT &p) const { return PT( x - p.x, y - p.y);}
};
dl dot( PT p, PT q) { return p.x * q.x + p.y * q.y;}
dl cross( PT p, PT q) { return p.x * q.y - p.y * q.x;}
dl distSq( PT p, PT q) { return dot(p-q, p-q);}

PT point[2005];
PT p;

bool cmp(PT a, PT b){
	dl k = cross(a-p,b-p);
	if( k==0 ) return distSq(a,p)<distSq(b,p);
	return k>0;
}
const int M = 10010;
int n,seen[M],matchR[M];
vector<int>bpGraph[M]; 
bool bpm(int u){
    for(int v=0;v<(int)bpGraph[u].size();v++){
        int V=bpGraph[u][v];
        //~ cout<<V<<" ";
        if(!seen[V]){
            seen[V]=true;
            if(matchR[V]==-1||bpm(matchR[V])){
                matchR[V]=u;
                //~ cout<<V<<" "<<u<<endl;
                return true;
            }
        }
    }
    return false;
}
int maxBPM(){
    memset(matchR,-1, sizeof matchR);
    int result=0;
    for(int i=0;i<n;i++){
        memset(seen,0,sizeof seen);
        if(bpm(i)){
            result++;
        }
    }
    return result;
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main()
{
	IO;
	freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	int ts,cs=0,r,c;
	string s[400];
	cin>>ts;
	while(ts--){
		cin>>r>>c;
		for(int i=0;i<r;i++){
			cin>>s[i];
		}
		int tl = 0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(s[i][j]=='*'){
					tl++;
					for(int k=0;k<4;k++){
						int x = i+dx[k];
						int y = j+dy[k];
						if(x>=0 && x<r && y>=0 && y<c && s[x][y]=='*'){
							bpGraph[i*c+j].pb(x*c+y);
						}
					}
				}
			}
		}
		n = r*c;
		int Ans = maxBPM();
		//~ cout<<tl<<" "<<Ans<<endl;
		cout<<"Case "<<++cs<<": "<<tl - Ans/2<<endl;
		for(int i=0;i<n;i++) bpGraph[i].clear();
	}
	return 0;
}

