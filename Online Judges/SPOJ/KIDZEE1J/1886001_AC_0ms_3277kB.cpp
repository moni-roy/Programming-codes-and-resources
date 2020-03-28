#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tst,cas=0,num,i;
    cin>>tst;
    while(tst--)
    {
        cin>>num;
        cout<<"Case "<<++cas<<":";
        for(i=1;i<=num;i++)
        {
            if(num%i==0) cout<<' '<<i;
        }
        puts("");
    }
    return 0;
}
