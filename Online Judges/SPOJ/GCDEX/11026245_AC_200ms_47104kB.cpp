#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
typedef vector<ll> vl;
#define MX (ll)1000000
ll vs[MX+1];
ll PHI[MX+1];
vl PRM;
void eulerPhi(){
    PHI[1]=1ll;
    for(ll i=2; i <= MX ; i++){
        if(vs[i]==0){
            vs[i]=i;
            PHI[i]=i-1;
            PRM.pb(i);
        }
        else{
            if(vs[i]==vs[i/vs[i]]){
                PHI[i]=PHI[i/vs[i]]*vs[i];
            }
            else{
                PHI[i]=PHI[i/vs[i]]*(vs[i]-1);
            }
        }
        for(int j=0; j<(int)PRM.size() && PRM[j]<=vs[i] && i*PRM[j]<=MX; j++){
            vs[i*PRM[j]]=PRM[j];
        }
    }
}
ll Ans[MX+1],sv[MX+1];
void pre(){
	for(int i=1;i<=MX;i++){
		for(int j = i;j<=MX; j+=i){
			sv[j] += (i*PHI[j/i]);
		}
	}
	for(int i= 1;i<=MX;i++) sv[i]-=i;
	for(int i=1;i<=MX;i++) Ans[i] = Ans[i-1]+sv[i];
}
int main()
{
	eulerPhi();
	pre();
	ll n;
	while(cin>>n && n){	
		cout<<Ans[n]<<endl;
	}
	return 0;
}
