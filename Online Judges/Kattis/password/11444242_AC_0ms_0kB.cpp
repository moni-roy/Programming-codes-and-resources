#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string s;
	double a[10001];
	cin>>n;
	for(int i=0;i<n;i++) cin>>s>>a[i];
	sort(a,a+n);
	reverse(a,a+n);
	double Ans=0;
	for(int i=0;i<n;i++){
		Ans += (i+1+.0)*a[i];
	}
	cout<<fixed<<setprecision(10)<<Ans<<endl;
	return 0;
}
