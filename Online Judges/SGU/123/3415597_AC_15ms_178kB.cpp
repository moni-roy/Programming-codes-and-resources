#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long unsigned llu;
ll fact[100],factsum[100],n;
int main()
{
    fact[0]=0;
    fact[1]=1;
    factsum[0]=0;
    factsum[1]=1;
    for(int i=2;i<44;i++)
    {
        fact[i]=fact[i-1]+fact[i-2];
        factsum[i]+=fact[i]+factsum[i-1];
    }
    while(cin>>n)
    {
        cout<<factsum[n]<<endl;
    }
}
