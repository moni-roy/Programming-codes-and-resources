#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ts;
	double Ans, s,t,d;
	cin>>ts;
	while(ts--){
		cin>>s>>t>>d;
		if(t+d<s) Ans = s-(t+d);
		else if(t>s+d) Ans = t-(s+d);
		else Ans = d-s-t;
		cout<<fixed<<setprecision(10);
		cout<<max(0.0,Ans)<<endl;
	}
	return 0;
}
