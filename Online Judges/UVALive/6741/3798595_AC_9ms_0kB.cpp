#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
int ts;
double a,b,an;
int main(){
	cin>>ts;
	while(ts--){
		cin>>a>>b;
		if(a>b) swap(a,b);
		an=b*sin(60.0*pi/180.0);
		an*=(b/2+max(b/2.0,a));
		cout<<fixed<<setprecision(3)<<an<<endl;
	}
}
