#include <bits/stdc++.h>
using namespace std;

long long n,q,x,v,r[314159+10],c[314159+10];
int main()
{
    string s;
    cin>>n>>q;
    while(q--)
    {
        cin>>s>>x>>v;
        if(s=="RowAdd")
        {
            r[x]+=v;
        }
        else
        {
            c[x]+=v;
        }
    }
    long long Ans2 =0,Ans1 =0;
    for(int i=1; i<=n; ++i)
    {
        Ans1 = max(Ans1,r[i]);
        Ans2 = max(Ans2,c[i]);
    }

    cout<<Ans1+Ans2<<endl;
    return 0;
}
