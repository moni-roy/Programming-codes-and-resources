#include <bits/stdc++.h>
using namespace std;
int t,n,cnt;
double d,xx[100001],yy[10001];

int par[10001];
int FND(int x)
{
    if(par[x]==x) return x;
    return par[x]=FND(par[x]);
}
void make_set(int a, int b)
{
    int u=FND(a);
    int v=FND(b);
    if(u!=v)
    {
        cnt--;
        par[v]=u;
    }
}
int main()
{
    int cs=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        cnt=n;
        for(int i=0; i<n; i++) par[i]=i;
        for(int i=0; i<n; i++)
        {
            cin>>xx[i]>>yy[i];
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j) continue;
                double ds=(xx[i]-xx[j])*(xx[i]-xx[j])+(yy[i]-yy[j])*(yy[i]-yy[j]);
                if(ds<=d*d)
                {
                    make_set(i,j);
                }
            }
        }
        cout<<"Case "<<++cs<<": "<<cnt<<endl;
    }
}
