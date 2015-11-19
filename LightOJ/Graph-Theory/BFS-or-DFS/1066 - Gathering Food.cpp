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
#define nl  		puts("")
#define tcase(cs) 	printf("Case %d:",++cs)
#define endl		'\n'
#define I_O	    	ios_base::sync_with_stdio(0); cin.tie(0);

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
string ss[22];
int vs[22][22];
int n;
struct st{
	int x,y,vl;
	st(){}
	st(int a,int b,int c){
		x=a;
		y=b;
		vl=c;
	}
}srt[26];
int FUN(st xx,char en)
{
	queue<st>q;
	zero(vs);
	vs[xx.x][xx.y]=1;
	q.push(xx);
	while(!q.empty()){
		st tmp=q.front();q.pop();
		int u=tmp.x,v=tmp.y;
		if(ss[u][v]==en) return tmp.vl;
		for(int i=0;i<4;i++){
			int uu=u+dx[i];
			int vv=v+dy[i];
			if(uu>=0&&uu<n&&vv>=0&&vv<n && !vs[uu][vv] && ss[uu][vv]!='#'){
				if(ss[uu][vv]!='.'&&ss[uu][vv]!=en) continue;
				vs[uu][vv]=1;
				q.push(st(uu,vv,tmp.vl+1));
			}
		}
	}
	return -1;
}
int main()
{
	int ts,cs=0;
	cin>>ts;
	while(ts--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>ss[i];
		int sz=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(isalpha(ss[i][j])){
					int id=ss[i][j]-'A';
					sz++;
					srt[id]=st(i,j,0);
				}
			}
		}
		int flg=0,as=0;
		for(int i=1;i<sz;i++){
			ss[srt[i-1].x][srt[i-1].y]='.';
			int tmp=FUN(srt[i-1],i+'A');
			if(tmp==-1){
				flg=1;
				break;
			}
			else as+=tmp;
		}
		if(!flg) tcase(cs),cout<<" "<<as<<endl;
		else tcase(cs),cout<<" Impossible"<<endl;
	}
}
/*
 * http://lightoj.com/volume_showproblem.php?problem=1066
 * 1
 * 
 * 10
 * A........L
 * B#..E..J..
 * D#G.......
 * C##RF....K
 * ....P.....
 * ....Q.....
 * ..HTSWO...
 * ..UV......
 * ......I...
 * ...N.....M
 * 
 * Case 1: 117
* */
