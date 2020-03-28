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
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&a[xx][yy]==0)
        {
            a[xx][yy]=1;
            dfs(xx,yy);
        }
    }
    //return ;
}
int main()
{
    while(cin>>n>>m&&n&&m)
    {
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            for(int j=0; j<m; j++)
            {
                a[i][j]=(s[i][j]=='@')?0:1;
            }
        }
        cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i][j]==0)
                {
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}
/*

1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@

*/
