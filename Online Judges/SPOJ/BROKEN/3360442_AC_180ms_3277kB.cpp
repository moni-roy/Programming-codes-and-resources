#include <bits/stdc++.h>
using namespace std;

int main()
{
	string ss;
	int m,cm,ln,mx;
	while(cin>>m&&m)
	{
		getchar();
		getline(cin,ss);
		//cin>>ss;
		ln=0;
		cm=0;
		int j=0;
		mx=0;
		int v[500];
		memset(v,0,sizeof v);
		for(int i=0;i<(int)ss.size();i++)
		{
			if(v[ss[i]]==0)
			{
				cm++;
			}
			v[ss[i]]++;
			ln++;
			while(cm>m)
			{
				v[ss[j++]]--;
				ln--;
				if(v[ss[j-1]]==0)
					cm--;
			}
			mx=max(mx,ln);
		}
		cout<<mx<<endl;
	}
}
