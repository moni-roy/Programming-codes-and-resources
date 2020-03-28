#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d,k,a[100001],cnt=0;
    cin>>n>>d>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    if(k>=d)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=n-1;i>=0;i--)
    {
        cnt++;
        if(k+a[i]>d)
        {
            k+=a[i];
            break;
        }
        else
        {
            k+=a[i]-1;
        }
    }
    if(k<d) cout<<-1<<endl;
    else cout<<cnt<<endl;
}
