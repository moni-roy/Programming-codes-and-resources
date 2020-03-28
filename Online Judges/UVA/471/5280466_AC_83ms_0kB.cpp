#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,s;

int check(ll m)
{
    int cnt=0;
    set<int>st;
    while(m>0)
    {
        st.insert(m%10);
        m/=10;
        cnt++;
    }
    return (cnt==st.size())?1:0;
}
int ck(ll m)
{
    int cnt=0;
    while(m>0)
    {
        m/=10;
        cnt++;
    }
    return (cnt>10)?1:0;
}
int main()
{
    int ts;
    cin>>ts;
    while(ts--)
    {
        cin>>n;
        ll mx=9876543210/n;
        for(ll i=1;i<=mx; i++)
        {
            if(check(i)){
                s=n*i;
                if(check(s)){
                    cout<<s<<" / "<<i<<" = "<<n<<endl;
                }
                if(ck(s)) break;
            }

        }
        if(ts) cout<<endl;
    }
    return 0;
}
