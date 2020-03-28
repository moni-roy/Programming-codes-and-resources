#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
//~ Output
#define endl                '\n'
#define nl                  puts("")
#define sp                  printf(" ");
#define tcase(cs)           printf("Case %d:",++cs)
#define pri(a)              printf("%d",a)
#define prl(a)              printf("%lld",a)
#define prd(a)              printf("%lf",a)

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
int v,sv[555][555],vs[11110];
//~ mii mp;
int mp[405001];
void  prm(){

	//~ zero(vs);
	//~ for(int i=2;i<=40510;i+=2) vs[i]=1;
	//~ mp[2]=1;
	//~ vs[2]=0;
	//~ for(int i=3;i<=40510;i+=2){
//~ 
		//~ if(vs[i]==0){
			//~ mp[i]=1;
//~ 
			//~ for(int j=i+i;j*j<=40510;j+=i){
				//~ vs[j]=1;
			//~ }
		//~ }
	//~ }
	mp[1]=1;
	mp[2]=0;
	for(int i=4;i<=40500;i+=2) mp[i]=1;
	for(int i=3;i<=sqrt(40500);i+=2){
		if(mp[i]==0){
			for(int j=3*i;j<=40500;j+=2*i) mp[j]=1;
		}
	}
}

void F(int p,int q,int x,int y){

	sv[x][y]=++v;

	if(v==40010) return;

	if(p==x && q+1==y){
		if(sv[x-1][y]==0){
			F(x,y,x-1,y);
		}
		else F(x,y,x,y+1);
	}

	else if(p==x && q-1==y){
		if(sv[x+1][y]==0){
			F(x,y,x+1,y);
		}
		else F(x,y,x,y-1);
	}

	else if(p+1==x && q==y){
		if(sv[x][y+1]==0){
			F(x,y,x,y+1);
		}
		else F(x,y,x+1,y);
	}

	else if(p-1==x && q==y){
		if(sv[x][y-1]==0){
			F(x,y,x,y-1);
		}
		else F(x,y,x-1,y);
	}

}

//~ int pp,qq;
//~ void F(int lv){
	//~ sv[pp][qq]=++v;
	//~ for(int i=1;i<lv;i++) sv[pp][++qq]=++v;
	//~ for(int i=0;i<lv;i++) sv[--pp][qq]=++v;
	//~ for(int i=0;i<lv;i++) sv[pp][--qq]=++v;
	//~ for(int i=0;i<lv;i++) sv[++pp][qq]=++v;
	//~ if(v>40401) return;
	//~ pp++;
	//~ F(lv+2);
//~ }
	
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int vst[455][455],cst[455][455];

int BFS(pii st,pii en){
	queue<pii>q;
	zero(vst);
	q.push(st);
	vst[st.F][st.S]=1;
	while(!q.empty()){
		pii u=q.front();q.pop();
		int x=u.F;
		int y=u.S;
		for(int i=0;i<4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(vst[xx][yy]==0 && sv[xx][yy] && mp[sv[xx][yy]]){
				vst[xx][yy]=vst[x][y]+1;
				if(en.F==xx && en.S==yy) return vst[xx][yy];
				q.push(MP(xx,yy));
			}
		}
	}
	return -1;
}
int main()
{
	//~ freopen("input.in","w",stdout);
	prm();
	zero(sv);

	v=2;
	//~ pp=200;
	//~ qq=200;
	//~ 
	sv[200][200]=1;
	sv[200][201]=2;
	F(200,201,200-1,201);
	
	//~ F(0);
	map<int,pii> ck;
	for (int i = 0; i <=444 ; i++)
	{
		for(int j=0;j<=444;j++){
			ck[sv[i][j]]=MP(i,j);
		}
	}
	int x,y,cs=0;
	while(scii(x,y)==2){
		pii st=ck[x];
		pii en=ck[y];
		tcase(cs),sp;
		if(x==y) {
			printf("0\n");
			continue;
		}
		int Ans=BFS(st,en);
		if(Ans==-1){
			puts("impossible");
		}
		else printf("%d\n",Ans-1);
	}
	return 0;
}


