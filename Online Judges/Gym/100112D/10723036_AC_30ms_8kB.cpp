
#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<sstream>

using namespace std;

#define open  freopen("input.txt","r",stdin)
#define close  freopen ("output.txt","w",stdout)
#define db double
#define ll long long
#define lll unsigned long long
#define loop(i,a,n) for(int i=a;i<=n;i++)
#define sf scanf
#define sf1(a) sf("%d",&a)
#define sf2(a,b) sf("%d %d",&a,&b)
#define sf3(a,b,c) sf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d) sf("%d %d %d %d",&a,&b,&c,&d)
#define sfd(a) sf("%lf",&a)
#define sfd2(a,b) sf("%lf %lf",&a,&b)
#define sfl1(a) sf("%lld",&a)
#define sfl2(a,b) sf("%lld %lld",&a,&b)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pf printf
#define pfi(x) pf("%d",x)
#define pfl(x) pf("%lld",x)
#define NL puts("")
#define bug pf("here is bug\n")
#define pft(tc) printf("Case %d:",tc++)
#define PI (2.0*acos(0.0))
//#define PI acos(-1.0)
#define mem(a,v) memset(a,v,sizeof a)
#define endl '\n'
#define pb push_back
#define xx first
#define yy second
#define mp make_pair
#define all(a) a.begin(),a.end()
#define HASH1 (lll) 101949101
#define HASH2 (lll) 104282401
#define HASH3 (lll) 701393107
#define LEN(a) a.length()


template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T lcm(T a,T b)
{
    return (a/gcd(a,b))*b;
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}   // M is prime}
template <class T> inline T bpow(T p,T e)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}




//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={0,1,0,-1};int dy[]={1,0,-1,0}; //4 Direction

#define linf 3000000000000000000ll
#define inf 999999999
#define MX 1000000
#define mod (ll) 1000000007
#define eps 1e-6
#define ub upper_bound // return the right most index of x<val
#define lb lower_bound // return the right most index of x<=val



struct data
{
    int one,two,three,four;
    data() {}
    data(int a,int b)
    {
        one=a,two=b;
    }
    data(int a,int b,int c,int d)
    {
        one=a,two=b,three=c,four=d;
	}
    data(int a,int b,int c)
    {
        one=a,two=b,three=c;
    }
    //~ bool friend operator<(data a,data b)
    //~ {
        //~ return  a.el1> b.el1;// sort decreasingly but increasingly for priority_queue
    //~ }
};


int n,m,k;
ll N,M,K;


int main()
{
    int t,tc=1;
    sf1(n);
    string s;
    cin>>s;
    int ct=0;
    int c1=0,c2=0;
    int tmp=0;
    int l=LEN(s);
    int dif=0;
    if(n==0){
		pf("0\n");
		return 0;
		
	}
    for(int i=0;i<LEN(s);i++){
		if(s[i]=='M') c1++;
		if(s[i]=='W') c2++;
		dif=abs(c1-c2);
		if(dif>0){
			if(i+1<l){
				if(s[i]!=s[i+1]){
					int tmp=0;
					if(s[i]=='M'){
						tmp=abs(c1-1-(c2+1));
						if(tmp<dif){
							c1--;
							c2++;
							dif=tmp;
							swap(s[i],s[i+1]);
							
						}
					}
					else{
						tmp=abs(c2-1-(c1+1));
						if(tmp<dif){
							c2--;
							c1++;
							dif=tmp;
							swap(s[i],s[i+1]);
						}
					}
					
					
				}
			}
		}
		if(dif>n) break;
			
		ct=i+1;
	}
	pfi(ct);
    
	return 0;
}

/*



*/
