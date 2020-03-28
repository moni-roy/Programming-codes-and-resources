#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool ok(ll x){
	string s="";
	while(x){
		s+=(x%10 + '0');
		x/=10;
	}
	reverse(s.begin(),s.end());
	int f= 1;
	for(int i=1;i<(int)s.size();i++){
		if(s[i]==s[i-1]+1){}
		else f=0;
	}
	return f;
}
ll n,Ans,a[10010],t,tmp;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	Ans = -1;
	for(int i=0;i<n;i++){
		t = a[i];
		for(int j=i+1;j<n;j++){
			tmp = t*a[j];
			if(ok(tmp)){
				Ans = max(Ans,tmp);
			}
		}
	}
	cout<<Ans<<endl;
	return 0;
}
