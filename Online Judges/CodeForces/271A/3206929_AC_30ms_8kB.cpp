#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long unsigned llu;
int distinct(int x)
{
    map<int,int>mp;
    int i=0,ar[10];
    while(x>0)
    {
        ar[i]=x%10;
        mp[ar[i]]++;
        x/=10;
        i++;
    }
    for(int i=0;i<4;i++)
    {
        if(mp[ar[i]]!=1) return 0;
    }
    return 1;
}

int main()
{
    int num;
    cin>>num;
    while(true)
    {
        num++;
        if(distinct(num)){ cout<<num<<endl;break;}
    }
}
