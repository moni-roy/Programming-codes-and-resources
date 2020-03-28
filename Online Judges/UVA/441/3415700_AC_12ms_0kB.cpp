#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,cs=0,a[1000];
    while(cin>>n&&n)
    {
        if(cs) cout<<endl;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0; i<n-5; i++)
        {
            for(int j=i+1; j<n-4; j++)
            {
                for(int k=j+1; k<n-3; k++)
                {
                    for(int l=k+1; l<n-2; l++)
                    {
                        for(int m=l+1; m<n-1; m++)
                        {
                            for(int p=m+1; p<n; p++)
                            {
                                cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[l]<<" "<<a[m]<<" "<<a[p]<<endl;
                            }
                        }
                    }
                }
            }
        }
        cs++;
    }
}
