#include <bits/stdc++.h>
using namespace std;

int x1,x2,n,m,v2,v1,i1,i2,a[10000001],b[10000001];
int main()
{
	cin>>x1>>x2;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>m;
	for(int i=0;i<m;i++) cin>>b[i];
	v1 = v2 = 0;
	i1 = i2 = 0;
	for(int i = 1;i<10000000;i++){
		x1 += v1;
		x2 += v2;
		if(x1+4==x2 || x2+4==x1){
			cout<<"bumper tap at time "<<i<<endl;
			return 0;
		}
		if(i1<n && i==a[i1]){
			v1 = 1-v1;
			i1++;
		}
		if(i2<m && i==b[i2]){
			v2 = 1-v2;
			i2++;
		}
	}
	cout<<"safe and sound"<<endl;
	return 0;
}
