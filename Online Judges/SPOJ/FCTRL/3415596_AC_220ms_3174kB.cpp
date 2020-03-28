#include <bits/stdc++.h>
using namespace std;
long long n,ans,t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        while(n>0)
        {
            ans+=n/5;
            n/=5;
        }
        cout<<ans<<endl;
    }
return 0;
}
