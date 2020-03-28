#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long tst,cas=0,yes,flag,day,num,tim[1000];
	string nm[1000],mk;
	cin>>tst;
	while(tst--)
	{
		cin>>num;
		for(long long i=0;i<num;i++)
		{
			cin>>nm[i]>>tim[i];
		}
		cin>>day>>mk;
		flag=0;
		for(long long i=0;i<num;i++)
		{
			if(mk==nm[i])
			{
				if(day>=tim[i])
				{
					yes=1;
					flag=1;
				}
				else if(day+5>=tim[i])
				{
					yes=0;
					flag=1;
				}
				else flag=0;
			}
		}
		if(!flag) cout<<"Case "<<++cas<<": Do your own homework!"<<endl;
			else
			{
				if(yes) cout<<"Case "<<++cas<<": Yesss"<<endl;
				else cout<<"Case "<<++cas<<": Late"<<endl; 
			}
	}
	return 0;
}
