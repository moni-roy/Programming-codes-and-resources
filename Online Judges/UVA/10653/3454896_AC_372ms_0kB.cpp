#include <bits/stdc++.h>
using namespace std;
int dx[]= {1,0,-1,0};
int dy[]= {0,1,0,-1};
int r,c,p,sv[1001][1001],sx,sy,ex,ey,rw,cl,nx,vs[1001][1001];

struct st
{
    int x,y,vl;
};
st ar[1000001],srt;
int fun(int x,int y)
{
    int rear=1,frnt=1;
    srt.x=x;
    srt.y=y;
    srt.vl=0;
    ar[frnt]=srt;
    sv[x][y]=1;
    while(rear>=frnt)
    {
        st u=ar[frnt];
        frnt++;
        for(int i=0; i<4; i++)
        {
            st v;
            v.x=u.x+dx[i];
            v.y=u.y+dy[i];
            if(v.x<r&&v.x>=0&&v.y<c&&v.y>=0)
            {
                if(sv[v.x][v.y]==0)
                {
                    sv[v.x][v.y]=1;
                    v.vl=u.vl+1;
                    if(v.x==ex && v.y==ey) return v.vl;
                    rear++;
                    ar[rear]=v;
                }
            }
        }
    }
    return 0;
}
int main()
{
    while(cin>>r>>c&&r&&c)
    {
        memset(sv,0,sizeof sv);
        cin>>p;
        for(int i=0; i<p; i++)
        {
            cin>>rw>>nx;
            for(int j=0; j<nx; j++)
            {
                cin>>cl;
                sv[rw][cl]=1;
            }
        }
        int ans=0;
        cin>>sx>>sy;
        cin>>ex>>ey;
        ans=fun(sx,sy);
        cout<<ans<<endl;
    }
}
