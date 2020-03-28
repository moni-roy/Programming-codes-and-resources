#include <bits/stdc++.h>
using namespace std;
int dx[]= {1,-1,0,0,0,0};
int dy[]= {0,0,1,-1,0,0};
int dz[]= {0,0,0,0,1,-1};

int l,r,c,sv[50][50][50];
char s[50][50][50];

struct st
{
    int x,y,z,vl=0;
};
st arr[1000010];
st ss;
int BFS()
{
    int frnt=1,rear;
    arr[frnt]=ss;
    rear=1;
    sv[ss.x][ss.y][ss.z]=1;
//    cout<<ss.x<<" "<<ss.y<<" "<<ss.z<<" "<<ss.vl<<endl;
    while(rear>=frnt)
    {
        st u=arr[frnt];
        frnt++;
        for(int i=0; i<6; i++)
        {
            st v;
            v.x=u.x+dx[i];
            v.y=u.y+dy[i];
            v.z=u.z+dz[i];
            if(v.x<l&&v.x>=0&&v.y>=0&&v.y<r&&v.z>=0&&v.z<c)
            {
                if(s[v.x][v.y][v.z]!='#' && sv[v.x][v.y][v.z]==0)
                {
                    sv[v.x][v.y][v.z]=1;
                    v.vl=u.vl+1;
                    rear++;
                    arr[rear]=v;
//                    cout<<v.x<<" "<<v.y<<" "<<v.z<<" "<<v.vl<<endl;
                    if(s[v.x][v.y][v.z]=='E') return v.vl;
                }
            }
        }
    }
    return -1;
}
int main()
{
    while(cin>>l>>r>>c&&l&&c&&r)
    {
        memset(sv,0,sizeof sv);
        for(int i=0; i<l; i++)
        {
            for(int j=0; j<r; j++)
            {
                for(int k=0; k<c; k++)
                {
                    cin>>s[i][j][k];
                    if(s[i][j][k]=='S')
                    {
                        ss.x=i;
                        ss.y=j;
                        ss.z=k;
                    }
                    if(s[i][j][k]=='#') sv[i][j][k]=1;
                }
            }
            //   getchar();
        }
        int ans=BFS();
        if(ans!=-1) cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
        else puts("Trapped!");
    }
}
/*
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
*/
