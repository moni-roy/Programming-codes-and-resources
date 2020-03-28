#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main()
{
	int ts,cs=0;
	string s;
	cin>>ts;
	while(ts--)
	{
		cin>>s;
		int idx=-1;
		int rem=0,cnt=0,sum=0;
		for(int i=0;i<(int)s.size();i++)
		{
			sum=0;
			for(int j=0;j<(int)s.size();j++)
			{
				if(i!=j)
				{
				sum+=(s[j]-'0');
			}
			}
			if(sum%3==0)
			{
				idx=i;
				break;
			}
		}
		//cout<<idx<<endl;
		if(idx<0) rem=0;
		else
		{
		for(int i=0;i<(int)s.size();i++)
		{
			if(i!=idx)
			{
				int t=s[i]-'0';
				t=t%3;
				if(!t) cnt++;
				//else ev++;
			}
		}
		if(cnt%2==0)
		{
			rem=1;
		}
	}
		cout<<"Case "<<++cs<<": ";
		if(rem) cout<<"S"<<endl;
		else cout<<"T"<<endl;
	}
	return 0;
}
