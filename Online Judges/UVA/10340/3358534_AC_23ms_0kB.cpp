#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s,ss;
	int ls,lss,j;
	while(cin>>s>>ss){
	ls=s.size();
	lss=ss.size();
	if(ls>lss)
	{
		cout<<"No"<<endl;
	}
	else
	{
		j=0;
		for(int i=0;i<lss;i++)
		{
			if(ss[i]==s[j])
			{
				j++;
			}
		}
		if(j==ls){
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
}
}
