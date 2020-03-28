#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(m%n) cout<<-1<<endl;
        else
        {
            cout<<n<<" "<<m<<endl;
        }
    }
}
