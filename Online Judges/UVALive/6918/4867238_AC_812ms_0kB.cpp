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
ll fun(ll x)
{
    ll cnt=0;
    while(x)
    {
        cnt++;
        x/=2;
    }
    return cnt;
}

ll dec(string s)
{
    ll d=0;
    ll ln=s.size();
    ll po=1;
    for(ll i=0; i<ln; i++)
    {
        ll x=s[i]-'0';
        d+=(x*po);

        po*=2ll;
    }
    return (ll)d;
}

int main()
{
    ll ans,ts,a,b,bit_a,bit_b,cs=0,Cp;
    cin>>ts;
    while(ts--)
    {
        cin>>a>>b;

        bit_a=fun(a);
        bit_b=fun(b);
        string ss="";
        string s2="";
        ll dif=abs(b-a);
        ll fs_a,fs_b;
//        if(bit_a!=bit_b) Cp=0;
//        else
        {
//            if(a&(1ll<<0) && b&(1ll<<0ll)) ss+='1';
//            else ss+='0';

            for(ll i=0; i<max(bit_a,bit_b); i++)
            {
                if(a&(1ll<<i)) fs_a=1;
                else fs_a=0;
                if(b&(1ll<<i)) fs_b=1;
                else fs_b=0;
                if(fs_a==0||fs_b==0) ss+='0';
                else
                {
                    if(dif<=power(2ll,i)) ss+='1';
                    else ss+='0';
                }
            }
            ans=dec(ss);
            Cp=ans;
        }
        ss="";
        for(ll i=0; i<max(bit_a,bit_b); i++)
        {
            if(a&(1ll<<i)) fs_a=1;
            else fs_a=0;
            if(b&(1ll<<i)) fs_b=1;
            else fs_b=0;
            if(fs_a==0 && fs_b==0)
            {
                if(dif<=power(2ll,i)) ss+='0';
                else ss+='1';
            }
            else
            {
                ss+='1';
            }
        }
        ans=dec(ss);
        cout<<"Case "<<++cs<<": "<<ans<<" "<<Cp<<endl;
    }
    return 0;
}
