#include <bits/stdc++.h>
#define ll long long
#define inf 9999999999
using namespace std;
ll seq[100000],check[100000],prn[100000];
//vector<int>v[100000];
ll num,midx;
ll lis(ll sz)
{
    ll ln=1,mn=0;
    check[0]=seq[0];
    prn[0]=1;
    ll lw,mid,high;
    for(int k=1; k<sz; k++)
    {
        if(check[ln-1]<seq[k])
        {
            check[ln++]=seq[k];
            prn[k]=ln;
        }
        else
        {
            lw=0;
            high=ln;
            while(lw<=high)
            {
                mid=(lw+high)/2;
                if(check[mid]<seq[k])
                {
                    lw=mid+1;
                }
                else high=mid-1;
            }
            check[lw]=seq[k];
            prn[k]=lw+1;
        }
    }
    return ln;
}
int main()
{
 int i=0;
    while(cin>>num)
    {
        seq[i++]=num;
        //i++;
    }
    ll len=lis(i);
    cout<<len<<endl;
    puts("-");
    stack<int>mk;
    for(int k=i-1; k>=0; k--)
    {
        if(prn[k]==len)
        {
            mk.push(seq[k]);
            len--;
        }
    }
    while(!mk.empty())
    {
        cout<<mk.top()<<endl;
        mk.pop();
    }
    return 0;
}
//using b_search
