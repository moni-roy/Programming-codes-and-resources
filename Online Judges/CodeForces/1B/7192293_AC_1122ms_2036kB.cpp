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

template <class T> inline T BMOD(T p,T e,T m)
{
    T ret=1;
    while(e)
    {
        if(e&1) ret=(ret*p)%m;
        p=(p*p)%m;
        e>>=1;
    }
    return (T)ret;
}
template <class T> inline T MODINV(T a,T m)
{
    return BMOD(a,m-2,m);
}
template <class T> inline T isPrime(T a)
{
    for(T i=2; i<=sqrt(double(a)); i++)
    {
        if(a%i==0)
        {
            return 0;
        }
    }
    return 1;
}
template <class T> inline T lcm(T a, T b)
{
    return (a/gcd(a,b))*b;
}
template <class T> inline T power(T a, T b)
{
    return (b==0)?1:a*power(a,b-1);
}
template <class T> inline string to_str(T t)
{
    stringstream ss;
    ss<<t;
    return ss.str();
}

//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

#define MX 1000010
#define MD 1e9+7


int main()
{
    ll ts,nm,f,a;
    string s;
    cin>>ts;
    while(ts--)
    {
        cin>>s;
        nm=0;
        f=0;
        for(int i=0; i<s.size(); i++ )
        {
            if(s[i]>='0'&& s[i]<='9')
            {
                nm*=10;
                nm+=(s[i]-'0');
            }
            else
            {
                if(nm) {
                        a=nm;
                        f++;
                }
                nm=0;
            }
        }
        if(nm) f++;
        if(f==1)
        {
            cout<<"R"<<nm<<"C";
            ll z=1;
            ll Ans=0;
            for(int j=s.size()-1; j>=0; j--)
            {
                if(s[j]<='9' && s[j]>='0') {}
                else
                {

                    Ans+=(z*(s[j]-'A'+1));
                    z*=26;
                }
            }
            cout<<Ans<<endl;
        }
        else
        {
            string st="";
            ll Ans=nm;
//            cout<<nm<<endl;
            while(nm)
            {
                int m=nm%26;
                if(m){
                        st+=(m+'A'-1);
                        nm-=m;
                }
                else {
                        st+='Z';
                nm-=26;
                }

                nm/=26;
            }
            reverse(st.begin(),st.end());
            cout<<st<<a<<endl;
        }
    }
    return 0;

}
