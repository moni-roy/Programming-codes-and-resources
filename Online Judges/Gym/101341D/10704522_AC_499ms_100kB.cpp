#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x,n,gd = 0,a;
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        gd = __gcd(a,gd);
    }
    if(x%gd) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
