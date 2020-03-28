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

int ln;

ll FL(string a) {
//    stack<ll>st;
    queue<ll>q;
    string nm = "", ck = "";
    a += '*';
//    cout << "OK" << endl;
    for(int i = 0; i <= ln; i++) {
//        cout << a[i] << endl;
        if((a[i] == '*' ) || (a[i] == '+')) {
            ck += a[i];
//            cout<<ck<<" "<<a[i]<<endl;
            ll y = 0;
            for(int k = 0; k < (int)nm.size(); k++) {
                y = y * 10 + nm[k] - '0';
            }
//            cout << y << endl;
            q.push(y);
            nm = "";
        } else {
            nm += a[i];
        }
    }
    ll ret = q.front();
    q.pop();
    for(int i = 0; i < ck.size() - 1; i++) {
        if(ck[i] == '+') {
            ret += q.front();
            q.pop();
        }
        if(ck[i] == '*') {
            ret *= q.front();
            q.pop();
        }
    }
    return ret;
}
ll ML(string a){
    stack<ll>st;
    queue<ll>q;
    string nm = "", ck = "";
    a += '*';
    for(int i = 0; i <= ln; i++) {
        if((a[i] == '*' ) || (a[i] == '+')) {
            ck += a[i];
            ll y = 0;
            for(int k = 0; k < (int)nm.size(); k++) {
                y = y * 10 + nm[k] - '0';
            }

            q.push(y);
            nm = "";
        } else {
            nm += a[i];
        }
    }
    ll ret=0;
    st.push(q.front());
    q.pop();
    for(int i = 0; i < ck.size() - 1; i++) {
        if(ck[i] == '+') {
            st.push(q.front());
            q.pop();
        }
        else if(ck[i] == '*') {
            ret = st.top();
            st.pop();
            ret*= q.front();
            q.pop();
            st.push(ret);
        }
    }
    ret=0;
    while(!st.empty()){
        ret+=st.top();
        st.pop();
    }
    return ret;
}
int main(){
    string a;
    ll n;
    while(cin>>a>>n){
        ln=a.size();
//        cout<<a<<endl;
       ll lf=FL(a);
//        cout<<lf<<endl;
      ll  ml=ML(a);
//      cout<<lf<<" "<<ml<<endl;
      if(lf==n&& ml==n) puts("U");
      else if(lf==n) puts("L");
      else if(ml==n) puts("M");
      else puts("I");
    }
    return 0;
}
