#include <bits/stdc++.h>
#define ll long long
#define dl double

using namespace std;

int main()
{
    ll tst,n,k;
    string str;
    cin>>tst;
    while(tst--)
    {
        ll ans=0,cnt=1,flag=0;
        cin>>n>>k;
        cin>>str;
        //ll ln=str.length();
        if(k==1)
        {
            cout<<n<<endl;
            continue;
        }
        for(ll i=1;i<=n;i++)
        {
            if(str[i]==str[i-1])
            {
                cnt++;
                if(cnt==k)
                {
                    flag=1;
                    ans++;
                    cnt=0;
                }
            }
            else
            {
                if(cnt!=0)
                {
                    ans++;
                }
                cnt=1;
            }

        }
//        cnt=1;
//        for(ll i=1;i<=n;i++)
//        {
//            if(str[i]==str[i-1])
//            {
//                cnt++;continue;
//            }
//            else
//            {
//                if(cnt>=k)
//                {
//                    ans++;
//                    cnt=0;
//                }
//                else
//                {
//                 cnt=1;
//                }
//            }
//            if(cnt!=0)
//            {
//                ans++;
//            }
//
//        }
        if(flag) cout<<ans<<endl;
        else cout<<"-1"<<endl;

    }
    return 0;
}
