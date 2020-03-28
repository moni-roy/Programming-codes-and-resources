/*
AUTHOR : VUAcoder
LANGUAGE : C++
PROBLEM :
*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<fstream>
#include<cfloat>
using namespace std;
#define PI (2.*acos(0.))
#define EPS 1e-9
#define ZERO(x)     (fabs(x) < EPS)
#define EQ(a,b)     (ZERO((a)-(b)))
#define LESSER(a,b) (!EQ(a,b) && (a)<(b))
#define GREATER(a,b)(!EQ(a,b) && (a)>(b))
#define GETBIT(x,i) (x&(1<<i))
#define SETBIT(x,i) (x|(1<<i))
#define FORab(i,a,b) for(typeof(b) i=(a);i<=(b);i++)
#define FOR(i,n) FORab(i,0,(n)-1)
#define FOR1(i,n) FORab(i,1,n)
#define FORit(it,a) for( typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define all(a) (a).begin(),(a).end()
#define ms(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define sz(a) (int)a.size()
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define px first
#define py second
#define __eXYZ__
#ifdef __eXYZ__
//USE THESE FOR DEBUG
#define RFILE(a)    freopen(a, "r", stdin)
#define WFILE(a)    freopen(a, "w", stdout)
#define _r(arg) {dbg,arg; dbg.start(); }
#define _n(arg...) {_r(#arg " ==> ");dbg,arg; }
#define _(arg...) { _n(arg); dbg.nl(); }
#else
#define RFILE(a)
#define WFILE(a)
#define _n(arg) {}
#define _n(arg...) {}
#define _(arg...) {}
#endif


typedef long long  LL;
typedef vector<int>   vi;
typedef pair<int,int>  pii;

template<class A, class B> ostream &operator<<(ostream& o, pair<A,B>& p) { //pair print
    return o << "("<<p.first<<", "<<p.second<<")";
}

template<class T> ostream& operator<<(ostream& o, const vector<T>& v) { //vector print
    o << "{";FORit(it, v) o << *it << ", "; return o << "}";
}

struct debugger
{
    ostream &out; bool first;
    void start() { first = true; }
    debugger(ostream& out):out(out) {start();}
    void nl() { out << endl; start(); }
    // Taken from rudradevbasak
    template<class T> debugger& operator,(T& v) {
        if(first) first = false; else out << ", ";
        out << v; return *this;
    }
    template<class T> debugger& operator,(pair<T*,int> arr) { //array print
        out << "{";
            FOR(i, arr.second) { out << arr.first[i] << ", "; }
        out << "}";
        return *this;
    }
} dbg(cerr);
vi v[15];

char str[100];
char str1[100];
int solve(int ind,int num,string &s1)
{
    if(ind==sz(s1))
    {
        return num;
    }
    int ret=0;
    FOR(i,sz(v[s1[ind]-'0']))
    {
        int num1=num;
        if(v[s1[ind]-'0'][i]<str[ind]-'0')
        {
            num1*=10;
            num1+=v[s1[ind]-'0'][i];
            FORab(j,ind+1,sz(s1)-1)
            {
                num1*=10;
                num1+=v[s1[j]-'0'][sz(v[s1[j]-'0'])-1];
            }
            ret=max(ret,num1);
        }
        else if(v[s1[ind]-'0'][i]==str[ind]-'0')
        {
            num1*=10;
            num1+=v[s1[ind]-'0'][i];
            int x=solve(ind+1,num1,s1);
            ret=max(ret,x);
        }

    }
    return ret;

}
int main()
{
    //cout<<char('9'+1)<<endl;
    int t;
    cin>>t;
    v[0].pb(0);v[0].pb(8);
    v[1].pb(0);v[1].pb(1);v[1].pb(3);v[1].pb(4);v[1].pb(7);v[1].pb(8);v[1].pb(9);
    v[2].pb(2);v[2].pb(8);
    v[3].pb(3);v[3].pb(8);v[3].pb(9);
    v[4].pb(4);v[4].pb(8);v[4].pb(9);
    v[5].pb(5);v[5].pb(6);v[5].pb(8);v[5].pb(9);
    v[6].pb(6);v[6].pb(8);
    v[7].pb(0);v[7].pb(3);v[7].pb(7);v[7].pb(8);v[7].pb(9);
    v[8].pb(8);
    v[9].pb(8);v[9].pb(9);
    v[10].pb(0);v[10].pb(1);v[10].pb(2);v[10].pb(3);v[10].pb(4);v[10].pb(5);v[10].pb(6);v[10].pb(7);v[10].pb(8);v[10].pb(9);
    int s,m;
    while(t--)
    {
        scanf("%d%d",&s,&m);
        sprintf(str,"%d",m);
        sprintf(str1,"%d",s);
        string s1=str1;
        int len=strlen(str);
        int ret=0;
        FOR(i,10)
        {
            string s2=s1;
            if(sz(s1)>len)break;
            while(sz(s2)<len)
            {
                s2+=":";
            }

            int x=solve(0,0,s2);
            //cout<<x<<endl;
            ret=max(ret,x);
            s1=":"+s1;
        }

        //cout<<s1<<endl;


        //cout<<ret<<endl;
        int num1;
        /*s1.erase(0,1);
        num1=0;
        FORab(j,0,sz(s1)-1)
        {
           num1*=10;
           num1+=v[s1[j]-'0'][sz(v[s1[j]-'0'])-1];
        }
        ret=max(ret,num1);*/
        printf("%d\n",ret);
    }


    return 0;
}