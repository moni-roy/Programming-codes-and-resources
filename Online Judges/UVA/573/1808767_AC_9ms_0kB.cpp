#include<bits/stdc++.h>
#define db double
using namespace std;
int main()
{
	db h,u,d,f,fa,height_a_clam;
	long long cnt;
	while(cin>>h>>u>>d>>f)
	{
		if(h==0) break;
		cnt=0;
		height_a_clam=0;
		fa=(u*f)/100;
		while(1)
		{
			cnt++;
			if(u>0) height_a_clam+=u;
			if(height_a_clam>h)
			{
				cout<<"success on day "<<cnt<<endl;
				break;
			}
			height_a_clam-=d;
			if(height_a_clam<0)
			{
				cout<<"failure on day "<<cnt<<endl;
				break;
			}
			u-=fa;
		}
	}
	return 0;
}
