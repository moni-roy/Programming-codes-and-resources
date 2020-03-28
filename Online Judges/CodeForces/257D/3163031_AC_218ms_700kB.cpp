#include <bits/stdc++.h>
using namespace std;
int n,i,sm,a[111111];
string st;
char ch;
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(a[n-1]-a[n-2]>1) 
	{
		st+='+';
		sm=a[n-1];
		ch='+';
	}
	else
	{
		sm=-1*a[n-1];
		ch='-';
		st+='-';
	}
	for(i=n-2;i>=0;i--)
	{
		if(sm<=0)
		{
			st+='+';
			sm+=a[i];
		}
		else
		{
			st+='-';
			sm-=a[i];
		}
	}
	if(sm<0)
	{
		for(i=(int)st.size()-1;i>=0;i--)
		{
			if(st[i]=='-') cout<<'+';
			else cout<<'-';
		}
	}
	else
	{
		for(i=(int)st.size()-1;i>=0;i--)
		{
			//if(st[i]=='-') cout<<'+';
			cout<<st[i];
		}
	}
	cout<<endl;
	//cout<<st<<endl;
}
