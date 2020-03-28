#include <bits/stdc++.h>
using namespace std;
char s[10000],fs[10000],sn[10000],pr[1000];
int n,t,k,sv[200][201],vs[202],ok[202];
void fun(int p)
{
	if(p==k)
	{
		for(int i=0;i<p;i++) cout<<pr[i];
		cout<<endl;
		return;
	}
	for(int i=0;i<k;i++)
	{
		if(vs[i]==0&&ok[i]==0)
		{
			for(int j=0;j<k;j++)
			{
				if(sv[i][j]==1)
				{
					ok[j]--;
				}
			}
			vs[i]=1;
			pr[p]=s[i];
			fun(p+1);
			
			for(int j=0;j<k;j++)
			{
				if(sv[i][j]==1)
				{
					ok[j]++;
				}
			}
			vs[i]=0;
		}
	}
}
	
int main()
{
	while(gets(fs))
	{
		gets(sn);
		if(t) cout<<endl;
		t++;
		k=0;
		memset(vs,0,sizeof vs);
		memset(sv,0,sizeof sv);
		memset(ok,0,sizeof ok);
		for(int i=0;i<(int)strlen(fs);i++)
		{
			if(fs[i]==' ') continue;
			s[k++]=fs[i];
		}
		sort(s,s+k);
		map<char, int>mp;
		for(int i=0;i<k;i++)
		{
			mp[s[i]]=i;
		}
		for(int i=0;i<(int)strlen(sn);i+=4)
		{
			sv[mp[sn[i]]][mp[sn[i+2]]]=1;
			ok[mp[sn[i+2]]]++;
		}
		fun(0);
	}
}
