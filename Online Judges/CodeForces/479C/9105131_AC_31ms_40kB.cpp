#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, a, b;
	cin>>n;
	pair<int,int>p[5005];
	for(int i=0;i<n;i++){
		cin>>a>>b;
		p[i]={a,b};
	}
	sort(p,p+n);
	int Ans = min(p[0].first,p[0].second);
	for(int i=1;i<n;i++){
		if(Ans<=p[i].second) Ans = min(p[i].first,p[i].second);
		else Ans = p[i].first;
	}
	cout<<Ans<<endl;
	return 0;
}
