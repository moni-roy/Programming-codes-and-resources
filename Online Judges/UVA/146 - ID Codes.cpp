#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    char str[55];
    while(cin>>str&&str[0]!='#')
    {
        if(next_permutation(str,str+strlen(str))) cout<<str<<endl;
        else cout<<"No Successor"<<endl;
    }
    return 0;
}
