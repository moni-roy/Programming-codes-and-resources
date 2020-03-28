#include <bits/stdc++.h>
using namespace std;
#define inf 9999999.0
double n,x[1000],y[1000],sv[201][201];

void floyed()
{
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                sv[i][j]=min(sv[i][j],max(sv[i][k],sv[k][j]));
            }
}
int main()
{
    int cs=0;
    while(cin>>n&&n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>x[i]>>y[i];
        }
        int        j=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                sv[i][j]=(i==j)?0:inf;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                sv[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                sv[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            }
        }
        floyed();
        //     cout<<sv[0][1]<<endl;
        cout<<"Scenario #"<<++cs<<endl;
        printf("Frog Distance = %.3lf\n",sv[0][1]);
        cout<<endl;
        //printf("%.3lf\n",sv[0][1]);
    }
    return 0;
}
