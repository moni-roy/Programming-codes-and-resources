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
#define IO                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define gcd(a,b)            __gcd(a,b)
//~ Input                   
#define I(a)                scanf("%d",&a)
#define I2(a,b)             scanf("%d%d",&a,&b)
#define I3(a,b,c)           scanf("%d%d%d",&a,&b,&c)
#define L(a)                scanf("%lld",&a)
#define L2(a,b)             scanf("%lld%lld",&a,&b)
#define L3(a,b,c)           scanf("%lld%lld%lld",&a,&b,&c)
#define D(a)                scanf("%lf",&a)
#define sc                  scanf
//~ Output                  
#define nl                  puts("")
#define sp                  printf(" ");
#define SP                  cout<<" ";
#define tcase(cs)           printf("Case %d:",++cs)
#define TC(cs)              cout<<"Case "<<++cs<<":"
#define PI(a)               printf("%d",a)
#define PL(a)               printf("%lld",a)
#define PD(a)               printf("%lf",a)
#define pr                  printf

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2;i<=sqrt(double(a));i++){if(a%i==0){return 0;}}return 1;}
template <class T> inline T lcm(T a, T b){return (a/gcd(a,b))*b;}
template <class T> inline T power(T a, T b){return (b==0)?1:a*power(a,b-1);}

#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)

//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

/******************************Let's GO*********************************/
int ld,rd;
ll l,r,Ans;
map<ll,int>mp;

ll digit(ll n){
	ll ret=0;
	while(n>0){
		ret++;
		n/=2;
	}
	return ret;
}
ll num(string s){
	ll ret=0;
	for(int i=(int)s.size()-1,j=0;i>=0;i--,j++){
		ret+=((s[i]-'0')*power((ll)2,(ll)j));
	}
	return ret;
}
int check(int m,int n,int k){
	int ret=0;
	ll pw;
	string s="";
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			s+='1';
		}
		for(int j=0;j<m;j++){
			s+='0';
		}
	}
	pw=num(s);
	if(mp[pw]==0 && pw>=l && pw<=r) ret++;
	mp[pw]++;
	
	s="";
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			s+='1';
		}
		for(int j=0;j<m;j++){
			s+='0';
		}
	}
	for(int j=0;j<n;j++){
		s+='1';
	}
	pw=num(s);
	if(mp[pw]==0 && pw>=l && pw<=r) ret++;
	mp[pw]++;
	
	return ret;
}
int main()
{
	I_O;
	while(cin>>l>>r){
		ld=digit(l);
		rd=digit(r);
		//~ cout<<ld<<" "<<rd<<endl;
		mp.clear();
		Ans=0;
		for(int i=1;i<64;i++){
			for(int j=0;j<64;j++){
				int mn=i+j;
				if(mn>rd) continue;
				for(int k=ld/mn;k<=(rd/mn);k++){
					//~ cout<<"OK"<<endl;
					Ans+=check(j,i,k);
				}
			}
		}
		if(l==0 && Ans) Ans--;
		cout<<Ans<<endl;
	}
	return 0;
}
