#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000;
int lp[N+1];
vector<int> prm,dis,prim;
void sieveLinear(){
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			prm.push_back (i);
		}
		for (int j=0; j<(int)prm.size() && prm[j]<=lp[i] && i*prm[j]<=N; ++j)
			lp[i * prm[j]] = prm[j];
	}
	int df = 0;
	for(int i=2;i<=N;i++){
		if(lp[i]!=i) df++;
		else{
			prim.push_back(i);
			dis.push_back(df);
			df=0;
		}
	}
}
int main()
{
	int ts;
	ll n,k;
	sieveLinear();
	cin>>ts;
	while(ts--){
		cin>>n>>k;
		if(k==0){
			cout<<n*(n-1)/2<<endl;
		}
		else{
			ll Ans = 0;
			int i = 0,j = k-1;
			while(j<(int)prim.size() && prim[j]<=n){
				Ans += ((dis[i]+1)*(n-prim[j]+1));
				j++,i++;
			}
			cout<<Ans<<endl;
		}
	}
	return 0;
}
