#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long unsigned llu;
typedef double dl;

int main()
{
    ll n,t,c,cnt=0,ans=0,l;
    cin>>n>>t>>c;
    for(int i=0;i<n;i++)
    {
        cin>>l;
        if(l>t)
        {
            if(cnt>=c)
            {
                ans+=(cnt-c+1);
            }
            cnt=0;
        }
        else cnt++;
    }
    if(cnt>=c) ans+=(cnt-c+1);
    cout<<ans<<endl;
    return 0;
}
