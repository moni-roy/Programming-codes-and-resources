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

struct PT {
    ll x,y;
};
PT p0;
PT nextToTop(stack<PT> &S) {
    PT p = S.top(); S.pop();
    PT res = S.top(); S.push(p);
    return res;
}
void swap(PT &p1, PT &p2) {
    PT temp = p1;
    p1 = p2;
    p2 = temp;
}
ll distSq(PT p1, PT p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
int orientation(PT p, PT q, PT r) {
    ll val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2; 
}
bool compare(PT X, PT Y){
	ll o = orientation(p0,X, Y);
	if(o==0) return (distSq(p0,X)<distSq(p0,Y));
	else if(o==2) return true;
	return false;
}
dl angle(PT p1,PT p2, PT p3){
	dl a = distSq(p1,p2)*1.0;
	dl b = distSq(p2,p3)*1.0;
	dl c = distSq(p3,p1)*1.0;
	a = sqrt(a);
	b = sqrt(b);
	c = sqrt(c);
	return acos((dl)(-b*b+c*c+a*a)/(2.0*a*c));
}
dl DEG(dl x) {
	return (180.0*x)/(pi);
}
void convexHull(PT points[], ll n) {
    ll ymin = points[0].y, mn = 0;
    for (ll i = 1; i < n; i++) {
        ll y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[mn].x))
            ymin = points[i].y, mn = i;
    }
    swap(points[0], points[mn]);
    p0 = points[0];
    sort(&points[1],&points[n],compare);
    stack<PT> S;
    S.push(points[0]);
    for (int i = 1; i < n; i++) {
        while (S.size()>1&&orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }
    vector<PT>v;
    while(!S.empty()) v.pb(S.top()),S.pop();
    if(v.size()<3){
		printf("0\n");
		return ;
	}
	dl ret = pi;
	int m=v.size();
	for(int i=0;i<m;i++){
		int j = (i+1)%m;
		int k = (i-1+m)%m;
		ret = min(ret,angle(v[i],v[j],v[k]));
	}
    printf("%.10lf\n",DEG(ret));
}

int main()
{
	//~ IO;
	//~ freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	PT a[100010];
	int ts,cs=0,n,x,y;
	I(ts);
	while(ts--){
		I(n);
		for(ll i=0;i<n;i++)
		{
			I2(x,y);
			a[i].x=x;
			a[i].y=y;
		}
		printf("Case %d: ",++cs);
		convexHull(a,n);
	}
	return 0;
}

