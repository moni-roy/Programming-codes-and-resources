#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s,t;
	while(cin>>s>>t)
	{
		int ls=s.size();
		int lt=t.size();
		int cnt=0;
		for(int i=0;i<lt&&cnt<ls;i++)
		{
			if(t[i]==s[cnt])
			{
				cnt++;
			}
		}
		if(cnt==ls) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}

