
///1261 - K-SAT Problem
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ts,cs=0,m,n,k,p,a[1000][1000],ck[1000];
    cin>>ts;
    while(ts--)
    {
      memset(ck,0,sizeof ck);
        cin>>n>>m>>k;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                cin>>a[i][j];
            }
        }
        cin>>p;
        int c;
        for(int i=0;i<p;i++)
        {
            cin>>c;
            ck[c]++;
        }
        bool flg=false;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
          for(int j=0;j<k;j++)
          {
              if(a[i][j]<0&&!ck[abs(a[i][j])])
              {
                  cnt++;
              }
              if(a[i][j]>=0&&ck[a[i][j]])
              {
                  cnt++;
              }
          }
          if(cnt==0)
          {
              flg=true;
          }
        }
        cout<<"Case "<<++cs<<": ";
        if(flg==false) cout<<"Yes\n";
        else cout<<"No\n";
    }
 
    return 0;
}
