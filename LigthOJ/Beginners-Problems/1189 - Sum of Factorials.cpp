#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll factorial(ll n)
{
    if(n<=1) return 1;
    return n*factorial(n-1);
}
int main()
{
    ll t,cs=0,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        stack<ll>s;
        ll cnt=20;
        int flg=0;
        while(n)
        {
            if(cnt<0)
            {
                flg=1;
                break;
            }
            else if(n>=factorial(cnt))
            {
                n-=factorial(cnt);
                s.push(cnt);
            }
            cnt--;
        }
        cout<<"Case "<<++cs<<": ";
        if(flg) cout<<"impossible"<<endl;
        else
        {
            while(s.size()!=1)
            {
                cout<<s.top()<<"!+";
                s.pop();
            }
            cout<<s.top()<<"!"<<endl;
        }
    }
   
}
