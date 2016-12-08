/* * * * * * * * * * * *
 * :Krishna (MRoy)     *
 * :JU                 *
 * :mkroy.cs@gmail.com *
 * * * * * * * * * * * */
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
#define PR                  printf
#define CHK                 cout<<"MK"<<endl;

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

#define MX 1000010

int n,x,y,km[101],val[101];
char s[101],ss[101],s1[20],s2[20];
dl l,h,m,Ans;

bool ok(dl f){
	int lk=0,cm=0,k=0;
	dl cp=f;
	for(int i=0;i<n;i++){
		
		f=f-(km[i]-k)*lk - (km[i]-k)*cm/100.0;
		if(f<0) return false;
		if(ss[i]=='G' && f>=0 ){
			f=cp;
		}
		else if(ss[i]=='M'){
			lk=0;
		}
		else if(ss[i]=='L'){
			lk++;
		}
		else if(ss[i]=='F'){
			cm=val[i];
		}
		k=km[i];
	}
	return true;
}

int main()
{
	I_O;
	n=0;
	while(gets(s)){
		int a=sscanf(s,"%d %s %s %d",&x,s1,s2,&y);
		if(a==4 && x==0 && y==0) break;
		if(a==2 && s1[0]=='G'){
			km[n]=x;
			ss[n]='R';
			n++;
			l=0;h=10000.0;
			for(int i=0;i<50;i++){
				m=(l+h)/2.0;
				if(ok(m)){
					Ans=m;
					h=m;
				}
				else l=m;
			}
			cout << fixed << setprecision(3) << Ans << endl;
			n=0;
		}
		else{
			km[n]=x;
			ss[n]=s1[0];
			if(a==4){
				val[n]=y;
			}
			n++;
		}
	}
	return 0;
}
/*
0 Fuel consumption 10
100 Goal
0 Fuel consumption 5
100 Fuel consumption 30
200 Goal
0 Fuel consumption 20
10 Leak
25 Leak
25 Fuel consumption 30
50 Gas station
70 Mechanic
100 Leak
120 Goal
0 Fuel consumption 0

*/
