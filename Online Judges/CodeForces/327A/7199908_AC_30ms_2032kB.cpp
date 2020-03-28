#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,Ans=0,a[1001];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int cnt=0;
            for(int k=0;k<i;k++) if(a[k]) cnt++;
            for(int k=i;k<=j;k++) if(!a[k]) cnt++;
            for(int k=j+1;k<n;k++) if(a[k]) cnt++;
            Ans=max(Ans,cnt);
        }
    }
    cout<<Ans<<endl;
}
