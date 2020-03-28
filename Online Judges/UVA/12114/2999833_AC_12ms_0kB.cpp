#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
	ll x,y,cs=0;
	while(cin>>x>>y){
		if(x==0&&y==0) break;
		if(x==0||x==1)
		{
			cout<<"Case "<<++cs<<": :-\\"<<endl;
		}
		else if(x<=y)
		{
			cout<<"Case "<<++cs<<": :-|"<<endl;
		}
		else cout<<"Case "<<++cs<<": :-("<<endl;
	}
	return 0;
}
