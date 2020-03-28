/*
 * 384E.cxx
 * 
 * Copyright 2017 Krishna <krishna@spirit>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


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
typedef pair<int ,pii>      piii;
typedef vector<pii>         vpii;
typedef vector<piii>        vpiii;

#define pi                  acos(-1.0)
#define S                   second
#define F                   first
#define pb                  push_back
#define mkp                 make_pair
#define mem(a,b)            memset(a,b,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define IO                  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define gcd(a,b)            __gcd(a,b)
#define FOR(i,a,b)			for(int i=a;i<=b;i++)
#define RFOR(i,a,b)			for(int i=a;i>=b;i--)

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
template <class T> inline string toString(T t) { stringstream ss; ss<<t; return ss.str();}
template <class T> inline long long toLong(T t) {stringstream ss;ss<<t;long long ret;ss>>ret;return ret;}
template <class T> inline int toInt(T t) {stringstream ss;ss<<t;int ret;ss>>ret;return ret;}
template <class T> inline bool leapYear(T t){if(!(t%(T)400) || (!(t%(T)4) && t%(T)100)) return true; return false;}

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

const int MX = 200010;
const ll  MD = 1e9+7;

int tr1[MX],tr2[MX],st[MX],lv[MX],en[MX];
int n,m,id;
vector<int>g[MX];

void dfs(int u,int p=-1,int l=0){
	st[u]=++id;
	lv[u]=l%2;
	for(auto v: g[u]){
		if(v!=p) dfs(v,u,l+1);
	}
	en[u]=id;
}
void update1(int x,int v){
	while(x<=id){
		tr1[x]+=v;
		x += x&-x;
	}
}
void update2(int x,int v){
	while(x<=id){
		tr2[x]+=v;
		x += x&-x;
	}
}
int query1(int x){
	int ret = 0;
	while(x){
		ret += tr1[x];
		x -= x&-x;
	}
	return ret;
}
int query2(int x){
	int ret = 0;
	while(x){
		ret += tr2[x];
		x -= x&-x;
	}
	return ret;
}
int main()
{
	IO;
	//~ freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	//~ cout<<"Ready to go!"<<endl;
	int a[MX],x,y,v,p;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;++i){
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1);
	for(int i=0;i<m;++i){
		cin>>p>>x;
		if(p==1){
			cin>>v;
			//~ cout<<p<<" "<<x<<" "<<v<<endl;
			if(lv[x]&1){
				update2(st[x],v);
				update2(en[x]+1,-v);
				
				update1(st[x],-v);
				update1(en[x]+1,v);
			}
			else{
				update1(st[x],v);
				update1(en[x]+1,-v);
				
				update2(st[x],-v);
				update2(en[x]+1,v);
			}
		}
		else{
			int Ans;
			if(lv[x]&1) Ans = query2(st[x])+a[x];
			else Ans = query1(st[x])+a[x];
			cout<<Ans<<endl;
		}
	}
	return 0;
}
