#include <bits/stdc++.h>
#define LL long long
#define LLU long long unsigned
using namespace std;
LL coin[25];
LLU dp[25][10009];
void coin_save()
{
    for(LL i=0;i<21;i++)
    {
        coin[i]=pow(double(i+1),3);
        //cout<<coin[i]<<' ';
    }
    //cout<<endl;
}
LLU func_arrange(LL pos, LL rest)
{
    if(rest==0) return 1;
    if(pos>=21||rest<0) return 0;
    if(dp[pos][rest]!=-1) return dp[pos][rest];
    else return dp[pos][rest]=func_arrange(pos,rest-coin[pos])+func_arrange(pos+1,rest);
}

int main()
{
    coin_save();
    LL value;
    memset(dp,-1,sizeof dp);
    while(cin>>value)
    {
        if(value>0)
        {
            cout<<func_arrange(0,value)<<endl;
        }
        else cout<<"0"<<endl;
    }
    return 0;
}
