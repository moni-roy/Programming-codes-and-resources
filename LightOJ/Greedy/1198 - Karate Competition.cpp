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

#define PI          acos(-1.0)
#define S           second
#define F           first
#define PB          push_back
#define MP          make_pair
#define P           push
#define zero(a)     memset(a,0,sizeof a)
#define minus(a)    memset(a,-1,sizeof a)
#define setinf(a)   memset(a,126,sizeof a)
#define all(v)      (v.begin(),v.end())
#define vsort(v)    sort(v.begin(),v.end())
#define nl          puts("")
#define tcase(cs)   printf("Case %d:",++cs)
#define endl        '\n'
#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)
#define I_O         ios_base::sync_with_stdio(0); cin.tie(0);
#define gcd(a,b)    __gcd(a,b)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}

int a[1001],b[1001],ts,cs=0,n,cnt,vs[1001],sv[1001];

int main()
{
	cin>>ts;
	while(ts--){
		cin>>n;
		cnt=0;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		zero(vs);
		zero(sv);
		for(int i=0;i<n;i++){
			int id,flg=0;
			for(int j=0;j<n;j++){
				if(a[i]<b[j]) break;
				if(vs[i]||sv[j]) continue;
				if(b[j]<a[i]){
					flg=1;
					id=j;
				}
			}
			if(flg){
				cnt+=2;
				vs[i]=sv[id]=1;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i]<b[j]) break;
				if(vs[i]||sv[j]) continue;
				if(b[j]==a[i]){
					cnt+=1;
					vs[i]=sv[j]=1;
					break;
				}
			}
		}
		tcase(cs),cout<<" "<<cnt<<endl;
	}
	return 0;
}

