#include <bits/stdc++.h>
#define ll long long
#define dl double
#define pi acos(-1)
using namespace std;

int main()
{
    dl r,h;
    cin>>r>>h;
    if(h*2<r) cout<<"1"<<endl;
    else
    {
        dl av=dl(h/r);
        ll lt=(av+.5)*2;
        ll mt=(av+1-sqrt(3)/2)*2+1;
        //cout<<pi<<' '<<lt<<' '<<mt<<' '<<av<<endl;
        cout<<max(lt,mt)<<endl;
    }
    //main();
    return 0;
}