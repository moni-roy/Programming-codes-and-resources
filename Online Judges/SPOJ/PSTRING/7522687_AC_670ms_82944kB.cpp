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
/*int pre[10101];
void prefixFunction(string s){
    int j=0,ln=s.size();
    for(int i=1;i<ln;i++){
        while(j && s[i]!=s[j]) j=pre[j-1];
        pre[i]=j;
    }
}
void KMP(string p) {
    int ln=p.size();
    prefixFunction(p);
    for(int i=0; i<ln; i++) {
        for(int j=1; j<=26; j++) {
            int t=i;
            while(t && (p[t]-'a'+1)!=j) t=pre[t-1];
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
    ret=min(ret,go(x+1,vs[y][s[x]-'a'+1]));
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
*/

int f[1010],n;
char s[10007],p[1007];
void kmp() {
    int i=0,j=-1;
    f[0]=-1;
    while(i<n) {
        if((j!=-1 && p[i]==p[j])||j==-1) {
            i++;
            j++;
            f[i]=j;
        } else if(j!=-1) j=f[j];
    }
}
int go(int i,int j) {
    if(j>=n) return inf;
    if(i>=ln) return 0;
    int &ret=sv[i][j];
    if(ret!=-1) return ret;
    ret=1+go(i+1,j);
    ret=min(ret,go(i+1,vs[j][s[i]-'a']));
    return ret;
}
int main() {
    while(~scanf("%s%s",s,p)) {
        n=strlen(p);
        ln=strlen(s);
        memset(sv,-1,sizeof sv);
        kmp();
        for(int i=0; i<n; i++) {
            for(int j=0; j<26; j++) {
                int t=i;
                while(t!=-1 && (p[t]-'a')!=j) t=f[t];
                vs[i][j]=t+1;
            }
        }
        int Ans=go(0,0);
        printf("%d\n",Ans);
    }
    return 0;
}

