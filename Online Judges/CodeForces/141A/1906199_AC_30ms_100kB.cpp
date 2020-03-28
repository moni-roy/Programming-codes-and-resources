#include<bits/stdc++.h>
using namespace std;
int main()
{
	string fst,snd,door;
	while(cin>>fst>>snd>>door)
	{
		map<int ,int >mk;
		map<int ,int>mk2;
		for(int i=0;i<fst.length();i++)
		{
			mk[fst[i]]++;
		}
		for(int i=0;i<snd.length();i++)
		{
			mk[snd[i]]++;
		}
		for(int i=0;i<door.length();i++)
		{
			mk2[door[i]]++;
		}
		int flag=1;
		for(int i=0;i<door.length();i++)
		{
			if(mk2[door[i]]!=mk[door[i]])
			{
				flag=0; break;
			}
		}
		for(int i=0;i<fst.length();i++)
		{
			if(mk[fst[i]]!=mk2[fst[i]])
			{
				flag=0;break;
			}
		}
		for(int i=0;i<snd.length();i++)
		{
			if(mk[snd[i]]!=mk2[snd[i]])
			{
				flag=0;break;
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
		
