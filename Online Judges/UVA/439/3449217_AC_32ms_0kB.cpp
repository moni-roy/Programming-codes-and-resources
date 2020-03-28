#include <bits/stdc++.h>
using namespace std;
vector<int>adj[100];
int vs[100],k,ans,st,en,a[10][10];
string ss,s;
int fun(int x)
{
    memset(vs,0,sizeof vs);
    queue<int>q;
    q.push(x);
    vs[x]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
           int v=adj[u][i];
            if(!vs[v])
            {
          // cout<<v<<endl;
                if(v==en) return vs[u];
                vs[v]=vs[u]+1;
                q.push(v);
            }
        }
    }
    return 0;
}
int main()
{
    k=1;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            a[i][j]=k;
            //cout<<i<< " "<<j<<" "<<a[i][j]<<endl;
            k++;
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(i<7&&j<6) adj[a[i][j]].push_back(a[i+1][j+2]);
            if(i<6&&j<7) adj[a[i][j]].push_back(a[i+2][j+1]);
            if(j>1&&i<7) adj[a[i][j]].push_back(a[i+1][j-2]);
            if(j>0&&i<6) adj[a[i][j]].push_back(a[i+2][j-1]);

            if(i<7&&j<6) adj[a[i+1][j+2]].push_back(a[i][j]);
            if(i<6&&j<7) adj[a[i+2][j+1]].push_back(a[i][j]);
            if(j>1&&i<7) adj[a[i+1][j-2]].push_back(a[i][j]);
            if(j>0&&i<6) adj[a[i+2][j-1]].push_back(a[i][j]);
        }
    }
    while(cin>>s>>ss)
    {
        int x=s[0]-'a';
        int xx=s[1]-'0';
        int y=ss[0]-'a';
        int yy=ss[1]-'0';
        st=a[x][xx-1];
        en=a[y][yy-1];
        //cout<<st<<" "<<en<<endl;
        ans=fun(st);
        cout<<"To get from "<<s<<" to "<<ss<<" takes "<<ans<<" knight moves."<<endl;
    }

}
