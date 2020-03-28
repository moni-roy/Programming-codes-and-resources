#include <bits/stdc++.h>
using namespace std;
int main()
{
	int ts,x,y;
	string st;
	cin>>ts;
	while(ts--)
	{
		cin>>st;
		int ln=st.size();
		int count=0;
		x=0,y=0;
		for(int i=0;i<ln;i++)
		{
			if(st[i]=='R') x++;
			else if(st[i]=='L') x--;
			else if(st[i]=='U') y++;
			else if(st[i]=='D') y--;
			else
			{
				count++;
			}
		}
		cout<<x-count<<' '<<y-count<<' '<<x+count<<' '<<y+count<<endl;
	}
}
