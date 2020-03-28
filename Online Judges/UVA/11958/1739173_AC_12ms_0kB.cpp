#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long tst,n,ft,fm,st,sm,time,comp,xt,cases=0;
    cin>>tst;
    while(tst--)
    {
        long long ans=INFINITY;
        scanf("%lld%lld:%lld",&n,&ft,&fm);
        long long st_time=ft*60+fm;
        for(long long i=0; i<n; i++)
        {
            scanf("%lld:%lld%lld",&st,&sm,&xt);
            time=st*60+sm;
            if(time<st_time)
            {
                time=time+24*60;
            }
//            comp=time-st_time;
//            if(min>comp)
//            {
//                min=comp;
//                if(min<0)
//                {
//                    min=-1*min;
//                }
//            }
            comp=time-st_time+xt;
            ans=min(ans,comp);

        }
        cout<<"Case "<<++cases<<": "<<ans<<endl;
    }
    return 0;
}
