#include <bits/stdc++.h>
using namespace std;
int dy[]= {1,0,-1,0,-1,1,-1,1};
int dx[]= {0,-1,0,1,1,-1,-1,1};
int a[101][101],n,m,cnt;
string s[101];
void dfs(int x,int y)
{
    a[x][y]=1;
    for(int i=0; i<8; i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<n&&a[xx][yy]==0)
        {
            a[xx][yy]=1;
            dfs(xx,yy);
        }
    }
    //return ;
}
int main()
{
    int t,cs=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            for(int j=0; j<n; j++)
            {
                a[i][j]=(s[i][j]=='.')?1:0;
            }
        }
        cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(a[i][j]==0&&s[i][j]=='x')
                {
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<"Case "<<++cs<<": "<<cnt<<endl;
    }
}
