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
vector<pair<int,int> > factors(int n){
	vector<pair<int,int> > ret;
	while(n>1){
		int p = lp[n];
		int cnt = 0;
		while(n%p==0){
			n/=p;
			cnt++;
		}
		ret.push_back({p,cnt});
	}
	return ret;
}
int fct(int n,int p){
	int pp = p;
	int ret = 0;
	while(n/p){
		ret += n/p;
		p*=pp;
	}
	return ret;
}
bool ok(int n, vector<pair<int,int> > v){
	for(auto x: v){
		int p = x.first;
		int c = x.second;
		int r = fct(n,p);
		if(r<c) return 0;
	}
	return 1;
}
int get(int n,vector<pair<int,int> > v){
	int  l = 1;
	int h = n,ret = n;
	while(l<=h){
		int m = (l+h)/2;
		if(ok(m,v)){
			ret = m;
			h = m-1;
		}
		else l = m+1;
	}
	return ret;
}

int main()
{
	sieveLinear();
	int a,b;
	cin>>a>>b;
	vector<pair<int,int> > x = factors(a);
	//~ for(auto xx:x){
		//~ cout<<xx.first<<" "<<xx.second<<endl;
	//~ }
	vector<pair<int,int> > y = factors(b);
	//~ for(auto xx:y){
		//~ cout<<xx.first<<" "<<xx.second<<endl;
	//~ }
	int l = get(a,x);
	int h = get(b,y);
	if(l>=h) cout<<0<<endl;
	else cout<<h-l<<endl;
	return 0;
}
