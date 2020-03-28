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
const int SIZE = 100010;

/*
 * http://www.iti.fh-flensburg.de/lang/algorithmen/pattern/kmpen.htm
 * */
int pre[2000101],sv[2000101];
void prefixFunction(string s) {
    int j=-1,i=0,ln=s.size();
    pre[i]=-1;
    while(i<ln) {
        while(j>=0 && s[i]!=s[j]) j=pre[j];
        i++,j++;
        pre[i]=j;
    }
}
void KMP(string s,string p) {
    int j=0,ln=s.size(),i=0;
    prefixFunction(p);
    while(i<ln) {
        while(j>=0 && s[i]!=p[j]) j=pre[j];
        i++,j++;
        if(j==(int)p.size()) sv[i-j]=i-j;
    }
}

/*
 * lcp return the longest common prefix legnth 
 * between two string.
 * */

const int N = (int)(1e5 + 7);
string s;
pair<pair<int,int>,int > Suffix[N],tmpSuffix[N];
int Rank[20][N],stp;
void SortSuffix(int n){
    for(int i=0; i<=n; i++){
        Suffix[i].F.F = (int)s[i];
        Suffix[i].F.S = 0;
        Suffix[i].S = i;
    }
    stp = 0;
    sort(Suffix,Suffix+n+1);
    for(int i = 0; i <= n; i++){
        if( !i ) Rank[i][Suffix[i].S] = i;
        else if ( Suffix[i].F != Suffix[i-1].F ){
            Rank[0][Suffix[i].S] = i;
        }
        else Rank[0][Suffix[i].S] = Rank[0][Suffix[i-1].S];
    }
    for(stp = 1; ; stp++){
        for(int i = 0; i <= n; i++) {
            int firstPart = Suffix[i].S;
            int secondPart = Suffix[i].S + (1 << (stp-1));
            tmpSuffix[i].F.F = Rank[stp-1][firstPart];
            if(secondPart <= n-1) tmpSuffix[i].F.S = Rank[stp-1][secondPart];
            else tmpSuffix[i].F.S = 0;
            tmpSuffix[i].S = -firstPart;
        }
        sort(tmpSuffix, tmpSuffix+n+1);
        for(int i = 0; i <= n; i++){
            Suffix[i] = tmpSuffix[i];
            Suffix[i].S *= -1;
            if( !i ) Rank[stp][Suffix[i].S] = i;
            else if(Suffix[i].F != Suffix[i-1].F) {
                Rank[stp][Suffix[i].S] = i;
            }
            else Rank[stp][Suffix[i].S] = Rank[stp][Suffix[i-1].S];
        }
        if( (1 << stp) >= n) break;
    }
}
int lcp(int x,int y,int n) {
    int ans = 0;
    if( x == y ) return n-x;
    for(int j = stp-1; j >= 0 && x < n; j--){
        if(Rank[j][x] == Rank[j][y]){
            x += (1 << j);
            y += (1 << j);
            ans += (1 << j);
        }
    }
    return ans;
}
int main()
{
	IO;
	freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	int ts,cs=0;
	cin>>ts;
	while(ts--){
		string s1,s2;
		cin>>s1>>s2;
		s=s1;
		int l = s.size();
		int l2 = s2.size();
		int Ans = 0;
		
		if(l>=l2){
			SortSuffix(l);
			
			mem(sv,-1);
			KMP(s,s2);
			//~ cout<<"OK"<<endl;
			int ln = l;
			for(int i=l-1;i>=0;i--){
				if(sv[i]==-1) sv[i]=ln;
				else ln = sv[i];
			}
			//~ cout<<l<<" "<<l<<endl;
			for(int i = 1; i <= l; i++)
			{
				int a = (i>0)?lcp(Suffix[i].S,Suffix[i-1].S,l):0;
				int k = min(l, sv[Suffix[i].S]+l2-1)-a-Suffix[i].S;
				if(k>0) Ans += k;
			}
		}
		cout<<"Case "<<++cs<<": "<<Ans<<endl;
	}
	return 0;
}

