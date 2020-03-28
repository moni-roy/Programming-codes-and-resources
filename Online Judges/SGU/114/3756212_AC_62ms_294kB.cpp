#include <bits/stdc++.h>
using namespace std;
int n,avg;
struct st{
	int x,p;
	bool operator<(const st &p)const{
		return x<p.x;
	}
}a[15002];
int main(){
	cin>>n;
	int tl=0;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].p;
		tl+=a[i].p;
	}
	sort(a,a+n);
	avg=(tl+1)/2;
	for(int i=0;i<n;i++){
		if(avg-a[i].p<=0){
			cout<<fixed<<setprecision(10)<<(double)(a[i].x)<<endl;
			break;
		}
		avg-=a[i].p;
	}
}
	
