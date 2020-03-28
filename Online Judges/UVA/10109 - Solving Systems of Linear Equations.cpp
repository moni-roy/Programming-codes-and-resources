#include <bits/stdc++.h>
using namespace std;

typedef long long          	ll;
typedef long long unsigned 	llu;
typedef double             	dl;
typedef pair<int,int>      	pii;
typedef pair<ll,ll>     	pll;
typedef vector<int>        	vi;
typedef map<int,int> 		mii;
typedef map<ll,ll>         	mll;
typedef map<string,int>    	msi;
typedef map<char,int>      	mci;

#define PI  		acos(-1.0)
#define sn	    	second
#define fs 	    	first
#define pb	    	push_back
#define mp	    	make_pair
#define zero(a) 	memset(a,0,sizeof a)
#define minus(a) 	memset(a,-1,sizeof a)
#define setinf(a) 	memset(a,126,sizeof a)
#define FR(i,x,y) 	for(int i=x;i<=y;i++)
#define FRV(i,x,y) 	for(int i=x;i>=y;i--)
#define all(v)		(v.begin(),v.end())
#define vsort(v)	sort(all(v))
#define gcd(a,b) 	__gcd(a,b)
#define nl  		puts("")
#define tcase(cs) 	printf("Case %lld:",++cs)
#define endl		'\n'
#define I_O	    	ios_base::sync_with_stdio(0); cin.tie(0);

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e>0){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}

char ss[100];

struct frac{
	
	ll a,b;
	
	frac() { a=0; b=1; }
	
	frac(ll _a, ll _b){
		a=_a; b=_b;
		reduce();
	}
	
	frac operator + (const frac &p) const{
		ll ra= a*p.b + p.a*b;
		ll rb = b*p.b;
		return frac(ra,rb);
	}
	
	frac operator - (const frac &p) const{
		ll ra= a*p.b - p.a*b;
		ll rb = b*p.b;
		return frac(ra,rb);
	}
	
	frac operator * (const frac &p) const{
		ll ra=  p.a*a;
		ll rb = b*p.b;
		return frac(ra,rb);
	}
	
	frac operator / (const frac &p) const{
		ll ra= a*p.b ;
		ll rb = b*p.a;
		return frac(ra,rb);
	}
	
	bool operator == (const frac &p) const{
		return a*p.b==p.a*b;
	}
	
	bool operator < (const frac &p) const{
		return a*p.b < p.a*b;
	}
	
	frac ABS(){
		return frac(abs(a),abs(b));
	}
	
	void print(){
		if (a==0) cout<<0;
		else if(b==1) cout<<a;
		else cout<<a<<"/"<<b;
	}
	
	void read(){
		scanf("%s",ss);
		bool flg=0;
		for(int i=0;ss[i] && !flg;i++)
		{
			if(ss[i]=='/') flg=1;
		}
		if(flg){
			sscanf(ss,"%lld/%lld",&a,&b);
		}
		else{
			sscanf(ss,"%lld",&a);
			b=1;
		}
		reduce();
	}
	
	void reduce(){
		ll g=gcd(a,b);
		a/=g;
		b/=g;
		if(a==0) b=1;
		if(b<0) a=-a,b=-b;
	}
};
const frac ZERO = frac(0,1);
int m,n,ts;

frac ar[55][55],res[55];

void fun()
{
	for(int i=1,j=1;i<=n&&j<=m;){
		int idx=i;	
		for(int k=i+1;k<=m;k++){
			if(!(ar[k][j]==ZERO)){
				idx=k;
				break;
			}
		}
		if(!(ar[idx][j]==ZERO)){
			for(int x=1;x<=n+1;x++){
				swap(ar[i][x],ar[idx][x]);
			}	
			for(int x=1;x<=m;x++){
				if(x!=i){
					for(int y=j+1;y<=n+1;y++)
					{
						ar[x][y]=ar[x][y]-ar[i][y]*(ar[x][j]/ar[i][j]);
					}
					ar[x][j]=ZERO;
				}
			}
			i++;
		}
		j++;
	}
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			ar[i][j].print();
			cout<<" ";
		}
		cout<<endl;
	}*/
	int rank=0;
	for(int i=1;i<=m;i++)
	{
		bool zr=1;
		for(int j=1;j<=n;j++)
		{
			if(!(ar[i][j]==ZERO)){
				zr=0;
				break;
			}
		}
		if(zr && !(ar[i][n+1]==ZERO))
		{
			//cout<<i<<" OK"<<endl;
			rank=-1;
			break;
		}
	}
	if(rank>=0){
		for(int i=1,j=1;i<=m&&j<=n;){
			if(!(ar[i][j]==ZERO)){
				res[j]=ar[i][n+1]/ar[i][j];
				rank++;
				i++;
			}
			j++;
		}
	}
	if(rank==-1) puts("No Solution.");
	else if(rank<n) cout<<"Infinitely many solutions containing "<<n-rank<<" arbitrary constants."<<endl;
	else
	{
		for(int i=1;i<=n;i++){
			cout<<"x["<<i<<"] = ";
			res[i].print();
			cout<<endl;
		}
	}
	return;
}
int main()
{
	int line=0;
	while(cin>>ts&&ts){
		cin>>n>>m;
		if(line) cout<<endl;
		line++;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n+1;j++){
				ar[i][j].read();
			}
		}
		cout<<"Solution for Matrix System # "<<ts<<endl;
		fun();
	}
	return 0;
}
/*
 * 1
 * 3 3
 * 9  4  1 -17
 * 1 -2 -6 14
 * 1  6  0  4
 * 2
 * 3 3
 * 2 2 2 2
 * 4 4 4 4
 * 16/1 16/1 16/1 16/1
 * 3
 * 2 3
 * 1 1 10
 * 1 1 20
 * 2 2 50
 * 4
 * 1 1
 * 3 10
* */
