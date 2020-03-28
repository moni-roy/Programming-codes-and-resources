#include <bits/stdc++.h>
using namespace std;
string ss;
vector<string>s;
int id,vs[100],sv[50][50],ok[100];
int main()
{
	id=0;
	while(cin>>ss)
	{
		if(ss=="#") break;
		s.push_back(ss);
	}
	id=s.size();
	for(int i=0;i<id;i++)
	{
		for(int j=0;j<(int)s[i].size();j++)
		{
			vs[s[i][j]-'A']=1;
		}
	}
	for(int i=0;i<id-1;i++)
	{
		for(int j=0;j<min((int)s[i].size(),(int)s[i+1].size());j++)
		{
			if(s[i][j]!=s[i+1][j])
			{
				if(sv[s[i][j]-'A'][s[i+1][j]-'A']==0&&s[i][j]!=s[i+1][j])
				{
					sv[s[i][j]-'A'][s[i+1][j]-'A']=1;
					ok[s[i+1][j]-'A']++;
				}
				break;
			}
		}
	}
	queue<int>q;
	for(int i=0;i<26;i++)
	{
		if(vs[i] && ok[i]==0) q.push(i);
	}
	
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		cout<<char(u+'A');
		for(int i=0;i<26;i++)
		{
			if(sv[u][i]&&vs[i])
			{
				ok[i]--;
				if(ok[i]==0) q.push(i);
			}
		}
	}
	cout<<endl;
	return 0;
}
