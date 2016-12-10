/* 
 * 1070 - Algebraic Problem
 * Category: Matrix Expo
 * */
#include <bits/stdc++.h>

using namespace std;

//~ typedef long long          	ll;
typedef long long unsigned 	ll;
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
template <class T> inline string to_str(T t) { stringstream ss; ss<<t; return ss.str();}

//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

#define MX 1000010
const int mSize=2;

struct matrix{
    ll mat[mSize][mSize];
    void zero(){
        memset(mat,0,sizeof mat);
    }
    void identity(){
        for(int i=0; i<mSize; i++){
            for(int k=0; k<mSize; k++){
                mat[i][k]=(i==k);
            }
        }
    }
    friend matrix operator *(matrix a, matrix b){
        matrix result;
        result.zero();
        for(int i=0; i<mSize; i++){
            for(int k=0; k<mSize; k++){
                if(a.mat[i][k]){
                    for(int j=0; j<mSize; j++){
                        result.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
                    }
                }
            }
        }
        return result;
    }
    friend matrix operator^(matrix a,ll x){
        matrix result;
        result.identity();
        while(x){
            if(x&1) result=result*a;
            a=a*a;
            x/=2;
        }
        return result;
    }
};

int main()
{
	int ts,cs=0,n,p,q;
	matrix m,base;
	ll Ans;
	scanf("%d",&ts);
	while(ts--){
		scanf("%d%d%d",&p,&q,&n);
		base.mat[0][0]=p;
		base.mat[0][1]=-q;
		base.mat[1][0]=1;
		base.mat[1][1]=0;
		m = base^(n-1);
		Ans = m.mat[0][0]*p + m.mat[0][1]*(ll)2;
		if(n==0) Ans = 2;
		printf("Case %d: %llu\n",++cs,Ans);
	}
	return 0;
}

