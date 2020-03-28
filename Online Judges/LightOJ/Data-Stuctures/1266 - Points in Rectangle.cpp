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

#define MX 1010
#define MD 1e9+7
const int SIZE = 100010;
int BIT[MX+5][MX+5],tt=1;


void updatey(int x,int y,int val){
	while(y<=MX){
		BIT[x][y] += val;
		y += (y & -y);
	}
}
void update(int x,int y,int val){
	while(x<=MX){
		updatey(x,y,val);
		x+=(x&-x);
	}
}

int query(int x,int y){
	int ret = 0, y1;
	while(x>0){
		y1= y;
		while(y1>0){
			ret += BIT[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return ret;
}
bool vs[MX][MX];
int main()
{
	IO;
	//~ freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	int ts,n,x,y,cs=0,c;
	I(ts);
	while(ts--){
		I(n);
		memset(vs,false,sizeof vs);
		memset(BIT,0,sizeof BIT);
		printf("Case %d:\n",++cs);
		while(n--){
			I(c);
			if(c){
				int a,b;
				I2(a,b);
				I2(x,y);
				a++,b++,x++,y++;
				int Ans = query(x,y)+query(a-1,b-1)-query(a-1,y)-query(x,b-1);
				printf("%d\n",Ans);
			}
			else{
				I2(x,y);
				x++,y++;
				if(vs[x][y]){}
				else {
					update(x,y,1);
				}
				vs[x][y]=1;
			}
		}
	}
	return 0;
}

