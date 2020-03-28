#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,as;
    while(cin>>m>>n)
    {
        as=max(m,n);
        as=6-as+1;
        if(as==6)
        {
            cout<<"1/1"<<endl;
        }
        else if(as==0) cout<<"0/1"<<endl;
        else
        {
            cout<<as/__gcd(as,6)<<"/"<<6/__gcd(as,6)<<endl;
        }

    }
}
