#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    int ts,n,m,r,c;
    string s;
    cin>>ts;
    while(ts--)
    {
        cin>>n>>m>>s;
        r = 0;
        c = 0;
        while(n)
        {
            n/=2;
            r++;
        }
        while(m)
        {
            m/=2;
            c++;
        }
        if(s=="Harry")
        {
            if(r<c) cout<<"Harry can win"<<endl;
            else cout<<"Harry cannot win"<<endl;
        }
        else
        {
            if(r>c) cout<<"Vicky can win"<<endl;
            else cout<<"Vicky cannot win"<<endl;
        }
    }
    return 0;
}
