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
string s[MX];
pair<int,int> A,B,C;
int sv[MX][MX][MX][MX][MX][MX];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
int n;

struct st{
	int ax,ay,bx,by,cx,cy,val;
	st(){}
	st(int ax_,int ay_,int bx_,int by_,int cx_,int cy_,int val_){
		ax=ax_,ay=ay_,bx=bx_,by=by_,cx=cx_,cy=cy_,val=val_;
	}
}nd;

int check(int x,int y){
	if(x>=0 && y>=0 && x<n && y<n) return 0;
	return 1;
}
int ok(int x1,int y1,int x2,int y2,int x3,int y3,int x,int y,int z){
	if( x && !y && x1==x2 && y2==y1) return 1;
	if( x && !z && x1==x3 && y3==y1) return 1;
	return 0;
}
int BFS()
{
	queue<st>q;
	q.push(st(A.F,A.S,B.F,B.S,C.F,C.S,0));
	sv[A.F][A.S][B.F][B.S][C.F][C.S]=0;
	while(!q.empty()){
		nd = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int axx = nd.ax+dx[i];
			int bxx = nd.bx+dx[i];
			int cxx = nd.cx+dx[i];
			int ayy = nd.ay+dy[i];
			int byy = nd.by+dy[i];
			int cyy = nd.cy+dy[i];
			int ma=1,mb=1,mc=1;
			if(check(axx,ayy) || s[axx][ayy]=='#'){
				ma= 0;
				axx=nd.ax;
				ayy=nd.ay;
			}
			if(check(bxx,byy) || s[bxx][byy]=='#'){
				mb= 0;
				bxx=nd.bx;
				byy=nd.by;
			}
			if(check(cxx,cyy) || s[cxx][cyy]=='#'){
				mc= 0;
				cxx=nd.cx;
				cyy=nd.cy;
			}
			for(int j=0;j<2;j++){
				if(ok(axx,ayy,bxx,byy,cxx,cyy,ma,mb,mc)){
					axx = nd.ax;
					ayy = nd.ay;
					ma= 0;
				}
				if(ok(bxx,byy,axx,ayy,cxx,cyy,mb,ma,mc)){
					bxx = nd.bx;
					byy = nd.by;
					mb= 0;
				}
				if(ok(cxx,cyy,axx,ayy,bxx,byy,mc,ma,mb)){
					cxx = nd.cx;
					cyy = nd.cy;
					mc= 0;
				}
			}
			int d = sv[axx][ayy][bxx][byy][cxx][cyy];
			if(d ==0 || d>nd.val+1){
				if(s[axx][ayy]=='X' && s[bxx][byy]=='X' && s[cxx][cyy]=='X'){
					return nd.val+1;
				}
				sv[axx][ayy][bxx][byy][cxx][cyy]=nd.val+1;
				q.push(st(axx,ayy,bxx,byy,cxx,cyy,nd.val+1));
			}
		}
	}
	return -1;
}

int main()
{
	IO;
	freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	int ts,cs=0;
	cin>>ts;
	while(ts--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i];
			for(int j=0;j<n;j++){
				if(s[i][j]=='A'){
					A.F = i;
					A.S = j;
				}
				if(s[i][j]=='B'){
					B.F = i;
					B.S = j;
				}
				if(s[i][j]=='C'){
					C.F = i;
					C.S = j;
				}
			}
		}
		memset(sv,0,sizeof sv);
		int Ans = BFS();
		cout<<"Case "<<++cs<<": ";
		if(Ans==-1) cout<<"trapped"<<endl;
		else cout<<Ans<<endl;
	}
	return 0;
}

