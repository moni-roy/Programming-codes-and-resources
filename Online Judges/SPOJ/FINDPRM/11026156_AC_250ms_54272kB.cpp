#include <bits/stdc++.h>
using namespace std;

const int N = 10000000;
int lp[N+1];
vector<int> prm;
void sieveLinear(){
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			prm.push_back (i);
		}
		for (int j=0; j<(int)prm.size() && prm[j]<=lp[i] && i*prm[j]<=N; ++j)
			lp[i * prm[j]] = prm[j];
	}
}
int main(){
	int ts,n;
	sieveLinear();
	cin>>ts;
	while(ts--){
		cin>>n;
		int hn = n/2;
		int l = upper_bound(prm.begin(),prm.end(),hn)-prm.begin();
		int h = upper_bound(prm.begin(),prm.end(),n)-prm.begin();
		cout<<h-l<<endl;
	}
	return 0;
}
