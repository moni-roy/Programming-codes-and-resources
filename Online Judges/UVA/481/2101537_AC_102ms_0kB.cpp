#include <bits/stdc++.h>
#define ll long long
#define inf 9999999999

using namespace std;

ll seq[100009],check[100009],prn[100009];

ll num,midx;
//LIS algo in NlogN
ll lis(ll sz)
{
    ll ln=1,mn=0;
    check[0]=seq[0];
    prn[0]=1;
    for(int k=1; k<sz; k++)
    {
        if(check[ln-1]<seq[k])
        {
            check[ln++]=seq[k];
            prn[k]=ln;
        }
        else
        {
            mn=lower_bound(check,check+ln,seq[k])-check;
            check[mn]=seq[k];
            prn[k]=mn+1;
        }
    }
    return ln;
}
//main Function
int main()
{
 int i=0;
    while(cin>>num)
    {
        seq[i++]=num;
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
//using lower_bound
