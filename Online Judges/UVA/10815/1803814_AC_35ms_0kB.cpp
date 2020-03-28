#include<bits/stdc++.h>
using namespace std;
int main()
{
	set<string>wrd;
	char ch;
	string mk;
	while((ch = getchar())!= EOF)
	{
		if(!isalpha(ch))
		{			
		if(mk!="")
		{
			wrd.insert(mk);
			mk="";
		}
	}
		else mk+=tolower(ch);
	}
	set<string>::iterator m;
	m=wrd.begin();
	while(m!=wrd.end())
	{
		cout<<*m<<endl;
		m++;
	}
	return 0;
}
