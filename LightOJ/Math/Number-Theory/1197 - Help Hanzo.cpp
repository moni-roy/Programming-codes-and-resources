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

#define MX 1000010
#define MD 1e9+7

const int N = 100000;
const int SIZE = 100010;
int lp[N+1];
vector<int> prm;
void sieve(){
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			prm.push_back (i);
		}
		for (int j=0; j<(int)prm.size() && prm[j]<=lp[i] && i*prm[j]<=N; ++j)
			lp[i * prm[j]] = prm[j];
	}
}
/*
 * Firstly, generate all primes less than √N
 */
int arr[SIZE];
///Returns number of primes between segment [a,b]
int segmentedSieve ( ll a, ll b ) {
    if ( a == 1 ) a++;
    int sqrtn = sqrt ( b );
    memset ( arr, 0, sizeof arr ); ///Make all index of arr 0.
    for ( int i = 0; i < (int)prm.size() && prm[i] <= sqrtn; i++ ) {
        int p = prm[i];
        ll j = p * p;
        ///If j is smaller than a, then shift it inside of segment [a,b]
        if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;
        for ( ; j <= b; j += p ) {
            arr[j-a] = 1; ///mark them as not prime
        }
    }
    int res = 0;
    for ( ll i = a; i <= b; i++ ) {
        ///If it is not marked, then it is a prime
        if ( arr[i-a] == 0 ) res++;
    }
    return res;
}


int main()
{
	IO;
	freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	sieve();
	int ts,cs=0;
	ll a,b;
	cin>>ts;
	while(ts--){
		cin>>a>>b;
		int Ans = segmentedSieve(a,b);
		cout<<"Case "<<++cs<<": "<<Ans<<endl;
	}
	return 0;
}
//~ http://blog.forthright48.com/2015/09/segmented-sieve-of-eratosthenes.html
	

