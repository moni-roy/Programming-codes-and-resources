#include <bits/stdc++.h>
using namespace std;
int lcm(int x,int y)
{
    return (x/__gcd(x,y))*y;
}
int main()
{
    int t,a,b,c,mn,flg;
    cin>>t;
    while(t--)
    {
        cin>>a>>c;
        flg=0;
        if(c%a==0)
        {
            mn=c/a;
            for(int i=mn;i<=c;i+=mn)
            {
                if(lcm(i,a)==c)
                {
                    flg=1;
                    b=i;
                    break;
                }
            }
        }
        if(flg==1) cout<<b<<endl;
        else cout<<"NO SOLUTION"<<endl;
    }
    return 0;
}
