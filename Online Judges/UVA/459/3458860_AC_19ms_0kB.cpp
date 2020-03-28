#include <bits/stdc++.h>
using namespace std;
int t,ans,par[101];
char c,cs,cf;
string s;
int FIND(int x)
{
    if(par[x]==x) return x;
    return par[x]=FIND(par[x]);
}

void set_make(int x,int y)
{
    int u=FIND(x);
    int v=FIND(y);
    if(u!=v)
    {
        par[u]=v;
        ans--;
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>c;
        ans=(c-'A');
        ans++;
        for(int i=0;i<ans;i++)
        {
            par[i]=i;
        }
        getchar();
        while(true)
        {
            getline(cin,s);
            if(s=="") break;
            cf=s[0];
            cs=s[1];
            set_make(cf-'A',cs-'A');
        }
        cout<<ans<<endl;
        if(t) cout<<endl;
    }
}
