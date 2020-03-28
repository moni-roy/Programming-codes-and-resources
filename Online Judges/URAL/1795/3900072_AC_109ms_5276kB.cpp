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

#define PI          acos(-1.0)
#define S           second
#define F           first
#define PB          push_back
#define MP          make_pair
#define P           push
#define zero(a)     memset(a,0,sizeof a)
#define minus(a)    memset(a,-1,sizeof a)
#define setinf(a)   memset(a,126,sizeof a)
#define all(v)      (v.begin(),v.end())
#define vsort(v)    sort(v.begin(),v.end())
#define nl          puts("")
#define tcase(cs)   printf("Case %d:",++cs)
#define endl        '\n'
#define READ(in)    freopen("in.in","r",stdin)
#define WRITE(out)  freopen("out.out","w",stdout)
#define I_O         ios_base::sync_with_stdio(0); cin.tie(0);
#define gcd(a,b)    __gcd(a,b)
#define sci(a)      scanf("%d",&a)
#define scl(a)      scanf("%lld",&a)
#define scd(a)      scanf("%lf",&a)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2;i<=sqrt(double(a));i++){if(a%i==0){return 0;}}return 1;}

struct st{
	int x;
	string s;
}a[100010];

int main()
{
	//I_O;
	int n,m,d,k,Ans;
	string of,nm;
	msi ms;
	//~ deque<int>dq;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>d>>of>>nm;
		ms[nm]=d;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a[i].x>>of>>a[i].s;
		//~ dq.PB(i);
	}
	Ans=0;
	k=0;
	//cout<<"OK"<<endl;
	while(k<m){
		//cout<<"YES"<<endl;
		of=a[k].s;
		Ans++;
		if(a[k].x<=ms[of]){
			ms[of]-=a[k].x;
			k++;
		}
		else if(ms[of]==0){
			k++;
		}
		else{
			if(k==m-1) break;
			a[k].x=ms[of];
			swap(a[k].s,a[k+1].s);
			swap(a[k].x,a[k+1].x);
		}
	}
	//~ k=0;
	//~ nw=dq.front();
	//~ dq.pop_front();
	//~ Ans=1;
	//~ cout<<nw<<endl;
	//~ queue<pair<int,int> >q;
	//~ getchar();
	//~ while(!dq.empty()){
		//~ cout<<Ans<<endl;
		//~ Ans++;
		//~ if(a[nw].x>ms[a[nw].nm]){
			//~ if(q.empty()!=0){
				//~ pair<int,int> rp=q.front();
				//~ q.pop();
				//~ if(ms[a[rp.F].nm]==rp.S){
					//~ ms[a[rp.F].nm]-=a[rp.F].x;
					//~ nw=dq.front();
					//~ dq.pop_front();
				//~ }
				//~ else{
					//~ q.push(MP(nw,ms[a[nw].nm]));
					//~ k=dq.front();
					//~ dq.pop_front();
					//~ dq.push_front(nw);
					//~ nw=k;
				//~ }
			//~ }
			//~ else{
				//~ q.push(MP(nw,ms[a[nw].nm]));
				//~ k=dq.front();
				//~ dq.pop_front();
				//~ dq.push_front(nw);
				//~ nw=k;
			//~ }
		//~ }
		//~ else{
			//~ ms[a[nw].nm]-=a[nw].x;
			//~ nw=dq.front();
			//~ dq.pop_front();
		//~ }
		//~ //getchar();
	//~ }
	cout<<Ans<<endl;
	return 0;
}
/*
 3
2 of sweets
4 of milk
1 of sausage
4
2 of milk
3 of sweets
3 of milk
1 of cheese
* */
