#include <bits/stdc++.h>
using namespace std;

long long t,n,d,k,a[10010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<=n;i++){
            cin>>a[i];
        }
        cin>>d>>k;
        long long int c=1;
        long long int cnt=0;
        while(cnt<k){
            cnt+=(c*d);
            c++;
        }
        long long Ans=a[0];
        for(int i=1;i<=n;i++){
            Ans+=(a[i]*pow(c-1,i));
        }
        cout<<Ans<<endl;
    }
    return 0;
}
