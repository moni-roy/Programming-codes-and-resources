#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int tst,n,cas=0;
    char s[12][12];
    cin>>tst;
    while(tst--)
    {
        cin>>n;
        //getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>s[i][j];
            }
        }
        for(int i=0;i<=n+1;i++) s[0][i]='.';
        for(int i=0;i<=n+1;i++) s[i][0]='.';
        for(int i=0;i<=n+1;i++) s[n+1][i]='.';
        for(int i=0;i<=n+1;i++) s[i][n+1]='.';
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
				if(s[i][j]!='.') continue;
                for(int k='A';k<='Z';k++)
                {
                    if(s[i+1][j]!=k&&s[i-1][j]!=k&&s[i][j-1]!=k&&s[i][j+1]!=k)
                    {
                        s[i][j]=k;
                        break;
                    }
                }
            }
        }
        cout<<"Case "<<++cas<<":"<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<s[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
