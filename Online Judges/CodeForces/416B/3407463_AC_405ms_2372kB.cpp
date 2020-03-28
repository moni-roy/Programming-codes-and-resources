#include <bits/stdc++.h>
using namespace std;
int n,m,a[55000][10],sv[55000],mx;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int j=0;j<m;j++)
    {
        mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,sv[i]);
            sv[i]=mx+a[i][j];
            mx=sv[i];
        }
    }
    for(int i=0;i<n;i++) cout<<sv[i]<<" ";
}
