#include <bits/stdc++.h>
using namespace std;
int dx[]= {1,0,-1,0};
int dy[]= {0,1,0,-1};

int cnt,m,n,vs[201][201],k;
char cc;
string s[209];

struct st
{
    char x;
    int c;
    bool operator<(const st& p) const
    {
        if(c==p.c) return x<p.x;
        return c>p.c;
    }
};
void fun(int x,int y)
{
    cnt++;
    vs[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0 && xx<n && yy>=0 && yy<m && s[xx][yy]==cc && vs[xx][yy]==0)
        {
            vs[xx][yy]=1;
            fun(xx,yy);
        }

    }
}
int main()
{
    int cs=0;
    while(cin>>n>>m&&n&&m)
    {
        for(int i=0; i<n; i++)
            cin>>s[i];

        k=0;
        st arr[2500];
        memset(vs,0,sizeof vs);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(s[i][j]!='.'&&vs[i][j]==0)
                {
                    cnt=0;
                    cc=s[i][j];
                    fun(i,j);
                    arr[k++].x=s[i][j];
                    arr[k-1].c=cnt;
                    //k++;
                }
            }
        }
        sort(arr,arr+k);
        cout<<"Problem "<<++cs<<":"<<endl;
        for(int i=0; i<k; i++)
        {
            cout<<arr[i].x<<" "<<arr[i].c<<endl;
        }
    }
}
