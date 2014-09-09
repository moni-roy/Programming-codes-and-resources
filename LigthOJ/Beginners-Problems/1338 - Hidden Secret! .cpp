#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,cs=0,a1[1001],a2[1001];
	string st1,st2;
	cin>>t;
	getchar();
	while(t--)
	{
		memset(a1,0,sizeof a1);
		memset(a2,0,sizeof a2);
		
		getline(cin,st1);
		int ln1=st1.length();

		getline(cin,st2);
		int ln2=st2.length();
		
		//cout<<ln1<<' '<<ln2<<endl;
		for(int i=0;i<ln1;i++)
		{
			st1[i]=tolower(st1[i]);
			a1[st1[i]-'a']++;
		}
		for(int i=0;i<ln2;i++)
		{
			st2[i]=tolower(st2[i]);
			a2[st2[i]-'a']++;
		}
		int flg=0;
		if(ln1>ln2)
		{
			for(int i=0;i<ln2;i++)
			{
				if(a1[st2[i]-'a']<a2[st2[i]-'a'])
				{
					flg=1;
					break;
				}
			}
		}
		else
		{
			for(int i=0;i<ln1;i++)
			{
				if(a2[st1[i]-'a']<a1[st1[i]-'a'])
				{
					flg=1;
					break;
				}
			}
		}
		cout<<"Case "<<++cs<<": ";
		if(flg) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
