#include <bits/stdc++.h>
using namespace std;
int n,x,y,ey,ex,fx,fy,c,par[1000100];
int FND(int p)
{
	if(par[p]==p) return p;
	return par[p]=FND(par[p]);
}
int main()
{
	while(cin>>n)
	{
		for(int i=0;i<=2*n;i++) par[i]=i;
		
		while(cin>>c>>x>>y)
		{
			if(c==0&&x==0&&y==0) break;
			fx=FND(x);
			fy=FND(y);
			ex=FND(x+n);
			ey=FND(y+n);
			if(c==1)
			{
				if(fx==ey) cout<<-1<<endl;
				else
				{
					par[fy]=fx;
					par[ey]=ex;
				}
			}
			else if(c==2)
			{
				if(fx==fy) cout<<-1<<endl;
				else
				{
					par[ey]=fx;
					par[ex]=fy;
				}
			}
			else if(c==3)
			{
				if(fx==fy) cout<<1<<endl;
				else cout<<0<<endl;
			}
			else
			{
				if(fx==ey) cout<<1<<endl;
				else cout<<0<<endl;
			}
		}
	}
}
