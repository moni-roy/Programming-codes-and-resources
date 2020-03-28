#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
	ll num,x,y,z,mx,my,mz,lx,ly,lz,d;
	while(cin>>num&&num)
	{
		cin>>x>>y>>z>>d;
		mx=x;my=y;mz=z;lx=x+d;ly=y+d;lz=z+d;
		num--;
		while(num--)
		{
			cin>>x>>y>>z>>d;
			mx=max(x,mx);
			my=max(y,my);
			mz=max(z,mz);
			lx=min(lx,x+d);
			ly=min(ly,y+d);
			lz=min(lz,z+d);
		}
		if(mx>=lx||my>=ly||mz>=lz) cout<<"0"<<endl;
		else cout<<(lx-mx)*(ly-my)*(lz-mz)<<endl;
	}
	return 0;
}
