#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long unsigned llu;
typedef double dl;

int main()
{
    ll t,p,ans,pp,n;
    string s[1000];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        sort(s,s+n);
        p=0;
        pp=0;
        ans=0;
        while(s[0][p]==s[1][p]) p++;
        while(s[0][pp]==s[n-1][pp]) pp++;
        ans=(max(pp,p)+1);
        //cout<<ans<<endl;
        p=0;
        while(s[n-1][p]==s[n-2][p]) p++;
        ans+=(max(pp,p)+1);
        //cout<<ans<<endl;
        for(int i=1;i<n-1;i++)
        {
            p=0;
            while(s[i][p]==s[i-1][p]) p++;
            pp=0;
            while(s[i][pp]==s[i+1][pp]) pp++;
            ans+=(max(p,pp)+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
