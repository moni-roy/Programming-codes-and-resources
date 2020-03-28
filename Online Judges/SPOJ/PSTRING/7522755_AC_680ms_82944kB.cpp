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
typedef pair<int,pii>      piii;
typedef vector<pii>         vpii;
typedef vector<piii>        vpiii;
#define pi                  acos(-1.0)
#define S                   second
#define F                   first
#define pb                  push_back
#define MP                  make_pair
#define P                   push
#define mem(a,b)            memset(a,b,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define gcd(a,b)            __gcd(a,b)
#define I(a)                scanf("%d",&a)
#define I2(a,b)             scanf("%d%d",&a,&b)
#define I3(a,b,c)           scanf("%d%d%d",&a,&b,&c)
#define L(a)                scanf("%lld",&a)
#define L2(a,b)             scanf("%lld%lld",&a,&b)
#define L3(a,b,c)           scanf("%lld%lld%lld",&a,&b,&c)
#define D(a)                scanf("%lf",&a)
#define nl                  puts("")
#define sp                  printf(" ");
#define SP                  cout<<" ";
#define tcase(cs)           printf("Case %d:",++cs)
#define TC(cs)              cout<<"Case "<<++cs<<":"
#define PI(a)               printf("%d",a)
#define PL(a)               printf("%lld",a)
#define PD(a)               printf("%lf",a)
template <class T> inline T BMOD(T p,T e,T m) {T ret=1;while(e) {if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m) {return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a) {for(T i=2; i<=sqrt(double(a)); i++) {if(a%i==0) {return 0;}}return 1;}
template <class T> inline T lcm(T a, T b) {return (a/gcd(a,b))*b;}
template <class T> inline T power(T a, T b) {return (b==0)?1:a*power(a,b-1);}
#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)
//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra
/******************************Let's GO*********************************/
#define inf 999999999

int sv[10010][1010],ln,vs[10007][1007];
int pre[10101];

void Failure(string s) {
    int j=0,ln=s.size(),i=1;
    pre[0]=-1;
    while(i<ln) {
        if(j>-1 && s[i]!=s[j]) j=pre[j];
        else {
            j++,i++;
            pre[i]=j;
        }
    }
}

void prefixFunction(string s){
    int j=0,ln=s.size();
    pre[0]=-1;
    for(int i=1;i<ln;i++){
        while(j && s[i]!=s[j]) j=pre[j];
        pre[i]=j;
    }
}
void KMP(string p) {
    int ln=p.size();
//    prefixFunction(p);
    Failure(p);
    for(int i=0; i<ln; i++) {
        for(int j=0; j<26; j++) {
            int t=i;
            while(t>-1 && (p[t]-'a')!=j) t=pre[t];
            vs[i][j]=t+1;
        }
    }
}
int lp,ls;
string s,p;
int go(int x,int y) {
    if(y>=lp) return inf;
    if(x>=ls) return 0;
    int &ret = sv[x][y];
    if(ret!=-1) return ret;
    ret = 1+go(x+1,y);
    ret=min(ret,go(x+1,vs[y][s[x]-'a']));
    return ret;
}
int main()
{
    while(cin>>s>>p){
        lp = p.size();
        ls = s.size();
        KMP(p);
        memset(sv,-1,sizeof sv);
        int Ans = go(0,0);
        cout<<Ans<<endl;
    }
    return 0;
}
