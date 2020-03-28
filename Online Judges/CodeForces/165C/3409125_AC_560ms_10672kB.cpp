#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k,ln,ans,t,sv[1100000];
string s;
int main()
{
    cin>>k>>s;
    ln=s.size();
    sv[0]=s[0]-'0';
    for(int i=1;i<ln;i++)
    {
        sv[i]=sv[i-1]+(s[i]-'0');
    }
    t=k;
    ans=upper_bound(sv,sv+ln,t)-lower_bound(sv,sv+ln,t);
    for(int i=1;i<ln;i++)
    {
        t=k+sv[i-1];
        ans+=upper_bound(sv,sv+ln,t)-lower_bound(sv+i,sv+ln,t);
        //cout<<upper_bound(sv,sv+ln,t)-sv<<" "<<lower_bound(sv,sv+ln,t)-sv<<endl;
    }
    cout<<ans<<endl;
}
