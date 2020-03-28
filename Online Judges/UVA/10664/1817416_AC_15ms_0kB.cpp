#include<bits/stdc++.h>
using namespace std;
int dp[30][1005],num,mk,mn[30];
int func(int pos,int coin)
{
    if(pos>=num)
    {
        if(coin<=mk) return 0;
        else return INT_MIN;
    }
    if(coin>mk) return INT_MIN;
    int &rt=dp[pos][coin];
    if(rt!=-1) return rt;
    rt=0;
    rt=max(mn[pos]+func(pos+1,coin+mn[pos]),func(pos+1,coin));
    return rt;
}
int main()
{
    int tst,ans,my,sum,i;
    string str;

    cin>>tst;
    getchar();
    while(tst--)
    {
        stringstream a;
        memset(dp,-1,sizeof(dp));
        getline(cin,str);
        sum=0;
        i=0;
        memset(mn,0,sizeof(mn));
        a<<str;
        do
        {
            a>>mn[++i];
            //cout<<mn[i]<<endl;
            sum=sum+mn[i];
        }while(a);

        if(sum%2)
        {
            cout<<"NO"<<endl;
            continue;
        }
        num=i;
        //sort(mn,mn+num+1);
        mk=(sum+1)/2;
        ans=func(0,0);
        my=sum-ans;
        int as=abs(my-ans);
        if(as==0)
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}

