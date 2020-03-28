#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tst,cas=0,num,a,b,c;
    cin>>tst;
    while(tst--)
    {
        cin>>a>>b>>c;
        //num=c*(c+1)-2;
        cout<<"Case "<<++cas<<":"<<endl;
        for(int i=0;i<=a&&i<b;i++)
        {
            for(int j=i+1;j<=b&&j<c; j++)
            {
                for(int k=j+1; k<=c; k++)
                {
                    cout<<i<<' '<<j <<' '<<k<<endl;
                }
            }
        }
    }
    return 0;
}
