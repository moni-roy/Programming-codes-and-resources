#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long tst=0,m,n,ans;
    while(cin>>m>>n&&m!=0&&n!=0)
    {
        ans=(m-1)/n;
        if(ans>26) cout<<"Case "<<++tst<<": impossible"<<endl;
        else
        {
            cout<<"Case "<<++tst<<": "<<ans<<endl;
        }
    }
    return 0;
}
