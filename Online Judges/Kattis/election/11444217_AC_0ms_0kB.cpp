#include <bits/stdc++.h>
using namespace std;

bool vs[55][55][55];
double sv[55][55][55];
double go(int n,int a,int b){
	if(n==0) {
		if(a>b) return 1;
		return 0;
	}
	double &ret = sv[n][a][b];
	if(vs[n][a][b]) return ret;
	vs[n][a][b]=1;
	ret = 0.5*go(n-1,a+1,b) + 0.5*go(n-1,a,b+1);
	return ret;
}

int main()
{
	int ts,n,a,b,w;
	cin>>ts;
	while(ts--){
		cin>>n>>a>>b>>w;
		memset(vs,0,sizeof vs);
		double Ans = go(n-a-b,a,b);
		if(Ans==0){
			cout<<"RECOUNT!"<<endl;
		}
		else if(Ans*100>w){
			cout<<"GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!"<<endl;
		}
		else cout<<"PATIENCE, EVERYONE!"<<endl;
	}
	return 0;
}
