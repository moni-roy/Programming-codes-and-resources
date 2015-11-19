#include <bits/stdc++.h>
using namespace std;
#define inf 999999999
typedef long long ll;

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

double sv[1<<18];
int x[10001],y[10001],cs=0,n;
string s;

double dis(int xx,int yy){
	return sqrt((x[xx]-x[yy])*(x[xx]-x[yy])+(y[xx]-y[yy])*(y[xx]-y[yy]));
}
double fun(int mk){
	if(mk==(1<<n)-1) return 0;
	double &ret=sv[mk];
	if(ret!=-1) return ret;
	ret=inf;
	int i,j;
	for(i=0;i<n;i++){
		if(!check(mk,i))
			break;
	}
	for( j=i+1;j<n;j++){
		if(!check(mk,j)){
			ret=min(ret,dis(i,j)+fun(Set(mk,i)|Set(mk,j)));
		}
	}
	return ret;
}
int main(){
	while(cin>>n&&n){
		n*=2;
		for(int i=0;i<(1<<n);i++) sv[i]=-1;
		for(int i=0;i<n;i++){
			cin>>s>>x[i]>>y[i];
		}
		cout<<"Case "<<++cs<<": "<<fixed<<setprecision(2)<<fun(0)<<endl;
	}
}
		
