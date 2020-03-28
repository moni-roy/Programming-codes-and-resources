#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s;
int main()
{
    while(cin>>n)
    {
        if(n<0) break;
        if(n==0) {cout<<0<<endl;continue;}
        s="";
        while(n>0)
        {
            s+=(n%3+'0');
            n/=3;
        }
        for(int i=s.size()-1;i>=0;i--)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
}
