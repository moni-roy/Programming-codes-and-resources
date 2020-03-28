#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    string str;
    cin>>str;
    ll cop[1000];
    ll ln=str.size();
    str+='+';
    ll num=0,j=0;
    for(ll i=0;i<=ln;i++)
    {
        if(str[i]=='+')
        {
            cop[j]=num;
            num=0;
            j++;
        }
        else
        {
            num=num*10+(str[i]-'0');
        }
    }
    //stringstream ss;

    sort(cop,cop+j);
    cout<<cop[0];
    for(ll i=1;i<j;i++)
    {
        cout<<'+'<<cop[i];
    }
    cout<<endl;
    return 0;
}
