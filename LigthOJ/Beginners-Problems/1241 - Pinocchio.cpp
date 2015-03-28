#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,cs=0,n,a[100];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        a[0]=2;
        for(int i=0;i<=n-1;i++)
        {
            if(a[i]<a[i+1])
            {
                ans+=((a[i+1]-a[i]-1)/5)+1;
            }
        }
        cout<<"Case "<<++cs<<": "<<ans<<endl;
    }
    return 0;
}
