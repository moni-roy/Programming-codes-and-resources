#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
typedef double dl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef pair<int,pii> piii;
typedef vector<pii> vii;
typedef vector<piii> viii;

#define pi                  acos(-1.0)
#define S                   second
#define F                   first
#define pb                  push_back
#define MP                  make_pair
#define mem(a,b)            memset(a,b,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define IO                  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define gcd(a,b)            __gcd(a,b)

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

template <class T> inline T BMOD(T p,T e,T m) {
    T ret=1;
    while(e) {
        if(e&1) ret=(ret*p)%m;
        p=(p*p)%m;
        e>>=1;
    }
    return (T)ret;
}
template <class T> inline T MODINV(T a,T m) {
    return BMOD(a,m-2,m);
}
template <class T> inline T isPrime(T a) {
    for(T i=2; i<=sqrt(double(a)); i++) {
        if(a%i==0) {
            return 0;
        }
    }
    return 1;
}
template <class T> inline T lcm(T a, T b) {
    return (a/gcd(a,b))*b;
}
template <class T> inline T power(T a, T b) {
    return (b==0)?1:a*power(a,b-1);
}
template <class T> inline string to_str(T t) {
    stringstream ss;
    ss<<t;
    return ss.str();
}
//-------------------------------------


int main() {
    IO;
    int ts;
    string s;
    cin>>ts;
    int vs[100001];
    while(ts--) {
        cin>>s;
        string Ans="";
        int t = 0;
        if(s.size()==1) {
            cout<<s<<endl;
            continue;
        }
        for(int i = 0; i<s.size(); i++) {
            if(s[i]!='2') {
                if(t%2) Ans+='2';
                t = 0;
            } else {
                t++;
            }
            Ans+=s[i];
        }
        if(t%2) Ans+='2';
        s = Ans;
        if(s.size()==1) {
            cout<<s<<endl;
            continue;
        }
        Ans = "";
        mem(vs,0);
        t = 0;
        int id = 0;
        for(int i = 0; i<s.size(); i++) {
            if(s[i]=='2') t++;
            else {
                Ans +=s[i];
                id++;
            }
            if(t%2==0 && t!=0) {
                Ans +='4';
                vs[id++]=1;
                t=0;
            }
        }
        s = Ans;
        if(s.size()==1) {
            if(vs[0]==1) s = "22";
            cout<<s<<endl;
            continue;
        }
        t  = 0;
        Ans = "";
        int cnt = 0;
//        cout<<s<<endl;
        for(int i = 0; i<s.size(); i++) {
            if(s[i]!='4') {
                cnt++;
                if(t%2) {
//                    Ans+='2';
                    Ans +='4';
                    t++;
                }
                cnt+=(t)/2;
                Ans+="8";
                t = 0;
            } else {
                t++;
                if(vs[i]) Ans +="22";
                else Ans +=s[i];
            }
        }
        if(t%2) {
            Ans+="4";
            t++;
        }
        cnt += t/2;
        int c = 1;
        for(int i=0;i<1020;i++){
			if(cnt<=c) break;
			c*=2;
		}
		for(int i=cnt+1;i<=c;i++) Ans+="8";
        cout<<Ans<<endl;
    }
    return 0;
}
