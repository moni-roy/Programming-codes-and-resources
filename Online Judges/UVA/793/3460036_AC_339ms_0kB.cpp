#include <bits/stdc++.h>
using namespace std;

int t,n,p,on,sm,x,y,par[100001];
char ch;
string ss;
int FIND(int f)
{
    if(par[f]==f) return f;
    return par[f]=FIND(par[f]);
}
void make_set(int f,int s)
{
    int u=FIND(f);
    int v=FIND(s);
    if(v!=u)
    {
        par[u]=v;
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>p;
        for(int i=1;i<=p;i++)
        {
            par[i]=i;
        }
        on=0;sm=0;
        getchar();
        while(true)
        {
            getline(cin,ss);
            if(ss=="") break;
            //cin>>x>>y;
            stringstream sss;
            sss<<ss;
            sss>>ch>>x>>y;
            if(ch=='c')
            {
                make_set(x,y);
            }
            else
            {
                int u=FIND(x);
                int v=FIND(y);
                if(v==u) sm++;
                else on++;
            }
        }
        cout<<sm<<","<<on<<endl;
        if(t) cout<<endl;
    }
}
