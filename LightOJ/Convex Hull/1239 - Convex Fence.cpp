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

struct Point {
	ll x, y;
	Point(){}
	Point(ll _x,ll _y){x=_x;y=_y;}
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};
ll cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (ll)(B.y - O.y) - (A.y - O.y) * (ll)(B.x - O.x);
}
void convex_hull(vector<Point> &P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; i++) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	} 
	H.resize(k);
	P=H;
}
ll distSq(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
dl angle(Point p1,Point p2, Point p3){
	dl a = distSq(p1,p2)*1.0;
	dl b = distSq(p2,p3)*1.0;
	dl c = distSq(p3,p1)*1.0;
	a = sqrt(a);
	b = sqrt(b);
	c = sqrt(c);
	return acos((dl)(b*b-c*c+a*a)/(2.0*a*b));
}
int main()
{
	freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	int ts,cs=0;
	ll x,y,d,n;
	I(ts);
	while(ts--){
		L2(n,d);
		vector<Point> a;
		for(ll i=0;i<n;i++)
		{
			scanf("%lld%lld\n",&x,&y);
			a.pb(Point(x,y));
		}
		printf("Case %d: ",++cs);
		convex_hull(a);
		if(a.size()>1) a.pop_back();
		int sz = a.size();
		dl Ans = 0;
		if(sz>=3){
			for(int i=0;i<sz;i++){
				x = (i+1)%sz;
				y = (i+2)%sz;
				Ans += sqrt((dl)distSq(a[i],a[i+1]));
				Ans += (1.0*d*(pi-angle(a[i],a[x],a[y])));
			}
		}
		else if(sz==2){
			Ans = 2.0*pi*d*1.0;
			Ans += 2.0*sqrt((dl)distSq(a[0],a[1]));
		}
		else{
			Ans = 2.0*pi*d*1.0;
		}
		printf("%.10lf\n",Ans);
	}
	return 0;
}

