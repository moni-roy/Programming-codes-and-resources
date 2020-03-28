/*Al amin*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long T,j;
    scanf("%lld",&T);
    for(j=1; j<=T; j++)
    {
            long long int a[100],i,k=1,o,n,s,c=0,count=0,ans1,ans;

        scanf("%lld%lld%lld",&n,&s,&o);
        for(i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
        }
        sort(a,a+n);
        if((n-s)>=0)
        {
            i=0;
            ans1=o-a[i];
            while(ans1>=0)
            {
                count++;
                i++;
                ans1=ans1-a[i];
            }
            if(count>=s)
            {
                printf("Case %lld: %lld\n",j,s);
            }
            else
            {
                printf("Case %lld: %lld\n",j,count);
                count=0;
            }
        }
        else
        {
            i=0;
            ans=o-a[i];
            while(ans>=0)
            {
                c++;
                i++;
                ans=ans-a[i];
            }
            if(c>=n)
            {
                printf("Case %lld: %lld\n",j,n);
            }
            else
            {
                printf("Case %lld: %lld\n",j,c);
                c=0;
            }

        }
    }

    return 0;
}
