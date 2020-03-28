#include <bits/stdc++.h>
using namespace std;
int l1,l2,k,i;
string s1,s2;
int main()
{
    while(cin>>s1>>s2)
    {
        l1=s1.size();
        l2=s2.size();
        k=0;
        for(i=0;i<l2;i++)
        {
            if(s2[i]==s1[k])
            {
                k++;
            }
        }
        if(k==l1) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
