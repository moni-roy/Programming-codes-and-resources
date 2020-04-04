/* * * * * * * * * * * * * * *
 * :Krishna (MRoy)
 * :JU
 * :mkroy.cs@gmail.com
 * * * * * * * * * * * * * * */
#include <bits/stdc++.h>
//~ c
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <climits>
//~ c++
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
#include <numeric>
#include <iterator>
#include <typeinfo>
#include <valarray>
#include <functional>

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
typedef pair<int ,pii>      piii;
typedef vector<pii>         vpii;
typedef vector<piii>        vpiii;
//~ Define
#define pi                  acos(-1.0)
#define S                   second
#define F                   first
#define pb                  push_back
#define MP                  make_pair
#define P                   push
#define zero(a)             memset(a,0,sizeof a)
#define minus(a)            memset(a,-1,sizeof a)
#define setinf(a)           memset(a,126,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define I_O                 ios_base::sync_with_stdio(0); cin.tie(0)
#define gcd(a,b)            __gcd(a,b)
//~ Input                   
#define sci(a)              scanf("%d",&a)
#define scii(a,b)           scanf("%d%d",&a,&b)
#define sciii(a,b,c)        scanf("%d%d%d",&a,&b,&c)
#define scl(a)              scanf("%lld",&a)
#define scll(a,b)           scanf("%lld%lld",&a,&b)
#define sclll(a,b,c)        scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a)              scanf("%lf",&a)
#define sc                  scanf
//~ Output                  
#define endl                '\n'
#define nl                  puts("")
#define sp                  printf(" ");
#define SP                  cout<<" ";
#define tcase(cs)           printf("Case %d:",++cs)
#define pri(a)              printf("%d",a)
#define prl(a)              printf("%lld",a)
#define prd(a)              printf("%lf",a)
#define pr                  printf

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2;i<=sqrt(double(a));i++){if(a%i==0){return 0;}}return 1;}
template <class T> inline T lcm(T a, T b){return (a/gcd(a,b))*b;}
template <class T> inline T power(T a, T b){return (b==0)?1:a*power(a,b-1);}

#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)

//~ cout << fixed << setprecision(20) << p << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

/******************************Let's GO*********************************/
ll Ans,n,cs=0,a[111][111];

ll go(int x,int y){
	ll ret=-999999999999;
	ll tm;
	//1
	if(x+3<n){
		tm=a[x][y];
		tm+=a[x+1][y];
		tm+=a[x+2][y];
		tm+=a[x+3][y];
		ret=max(ret,tm);
	}
	if(y+3<n){
		tm=a[x][y];
		tm+=a[x][y+1];
		tm+=a[x][y+2];
		tm+=a[x][y+3];
		
		ret=max(ret,tm);
	}
	//2
	if(x+1<n && y+2<n){
		tm=a[x][y];
		tm+=a[x+1][y+1];
		tm+=a[x][y+1];
		tm+=a[x+1][y+2];
		ret=max(ret,tm);
	}
	if(x+2<n && y-1>=0){
		tm=a[x][y];
		tm+=a[x+1][y];
		tm+=a[x+1][y-1];
		tm+=a[x+2][y-1];
		ret=max(ret,tm);
	}
	//3
	if(x+1<n && y+2<n){
		tm=a[x][y];
		tm+=a[x][y+1];
		tm+=a[x][y+2];
		tm+=a[x+1][y+2];
		ret=max(ret,tm);
	}
	if(x+2<n && y-1>=0){
		tm=a[x][y];
		tm+=a[x+1][y];
		tm+=a[x+2][y];
		tm+=a[x+2][y-1];
		ret=max(ret,tm);
	}
	if(x+2<n && y+1<n){
		tm=a[x][y];
		tm+=a[x][y+1];
		tm+=a[x+1][y];
		tm+=a[x+2][y];
		ret=max(ret,tm);
	}
	if(x+1<n && y+2<n){
		tm=a[x][y];
		tm+=a[x+1][y];
		tm+=a[x+1][y+1];
		tm+=a[x+1][y+2];
		ret=max(ret,tm);
	}
	//4th
	if(x+2<n && y+1<n) {
		tm=a[x][y];
		tm+=a[x+1][y];
		tm+=a[x+2][y];
		tm+=a[x+1][y+1];
		ret=max(ret,tm);
	}
	if(x+2<n && y-1>=0){
		tm=a[x][y];
		tm+=a[x+1][y-1];
		tm+=a[x+1][y];
		tm+=a[x+2][y];
		ret=max(ret,tm);
	}
	if(x+1<n && y+2<n){
		tm=a[x][y];
		tm+=a[x+1][y+1];
		tm+=a[x][y+1];
		tm+=a[x][y+2];
		ret=max(ret,tm);
	}
	if(x-1>=0 && y+2<n){
		tm=a[x][y];
		tm+=a[x-1][y+1];
		tm+=a[x][y+1];
		tm+=a[x][y+2];
		ret=max(ret,tm);
	}
	//5th
	if(x+1<n && y+1<n){
		tm=a[x][y];
		tm+=a[x+1][y];
		tm+=a[x+1][y+1];
		tm+=a[x][y+1];
		ret=max(ret,tm);
	}
	
	return ret;
}
	
int main(){
	I_O;
	while(cin>>n && n){
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin>>a[i][j];
			}
		}
		Ans=-999999999999;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				Ans=max(Ans,go(i,j));
			}
		}
		cout<<++cs<<". ";
		cout<<Ans<<endl;
	}
		
	return 0;
}