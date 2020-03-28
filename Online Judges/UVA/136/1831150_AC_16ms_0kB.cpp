#include<bits/stdc++.h>
#define llu long long unsigned
using namespace std;

int main()
{
	llu a=2,b=3,c=5,x=0,y=0,z=0;
	vector<llu>mk;
	mk.push_back(1);
	while(mk[1499]==0)
	{
		if(a<c&&a<b)
		{
			mk.push_back(a);
			x++;
			a=mk[x]*2;
		}
		else if(b<a&&b<c)
		{
			mk.push_back(b);
			y++;
			b=mk[y]*3;
		}
		else if(c<a&&c<b)
		{
			mk.push_back(c);
			z++;
			c=mk[z]*5;
		}
		if(a==b)
		{
			x++;
			a=mk[x]*2;
		}
		else if(b==c)
		{
			y++;
			b=mk[y]*3;
		}
		else if(c==a)
		{
			z++;
			c=mk[z]*5;
		}
	}
	cout<<"The 1500'th ugly number is "<<mk[1499]<<'.'<<endl;
	return 0;
}
