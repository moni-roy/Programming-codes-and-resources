#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ts,nl=0,a,b,c,d,x,y,p,q;
    cin>>ts;
    while(ts--)
    {
        if(nl!=0) cout<<endl;
        nl++;
        cin>>a>>b>>c>>d;
        cin>>x>>y>>p>>q;
        int mx,my,nx,ny;
        mx=max(a,x);
        my=max(b,y);
        nx=min(p,c);
        ny=min(d,q);
        if(mx>=nx||my>=ny) cout<<"No Overlap"<<endl;
        else cout<<mx<<' '<<my<<' '<<nx<<' '<<ny<<endl;
    }
    return 0;
}