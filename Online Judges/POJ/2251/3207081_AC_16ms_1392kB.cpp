#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;
struct edge
{
    int x,y,z;
};
string str[50][50];
int dir[6][3]= {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
edge st,en;
int l,c,r;
int ds[50][51][51];
int vis[50][51][51];
int BFS(int m,int n,int p)
{
    memset(vis,0,sizeof vis);
    memset(ds,0,sizeof ds);
    queue<edge>q;
    edge qu;
    qu.x=m;
    qu.y=n;
    qu.z=p;
    q.push(qu);
    vis[m][n][p]=1;
    while(!q.empty())
    {
        edge u=q.front();
        q.pop();
        for(int i=0; i<6; i++)
        {
            edge v;
            v.x=u.x+dir[i][0];
            v.y=u.y+dir[i][1];
            v.z=u.z+dir[i][2];
            if(v.x<0||v.x>=l||v.y<0||v.y>=r||v.z<0||v.z>=c)
                continue;
            if(!vis[v.x][v.y][v.z] && str[v.x][v.y][v.z]!='#')
            {
                if(v.x==en.x&&v.y==en.y&&v.z==en.z) return ds[u.x][u.y][u.z]+1;
                vis[v.x][v.y][v.z]=1;
                ds[v.x][v.y][v.z]=ds[u.x][u.y][u.z]+1;
                q.push(v);
            }
        }
    }
    return -1;
}
int main()
{
    while(cin>>l>>r>>c&&l&&r&&c)
    {
        for(int i=0; i<l; i++)
        {
            for(int j=0; j<r; j++)
            {
                cin>>str[i][j];
                for(int k=0; k<c; k++)
                {
                    if(str[i][j][k]=='S')
                    {
                        st.x=i;
                        st.y=j;
                        st.z=k;
                    }
                    if(str[i][j][k]=='E')
                    {
                        en.x=i;
                        en.y=j;
                        en.z=k;
                    }
                }
            }
            getchar();
        }
        int result= BFS(st.x,st.y,st.z);
        if(result!=-1) cout<<"Escaped in "<<result<<" minute(s)."<<endl;
        else cout<<"Trapped!"<<endl;
    }
}
