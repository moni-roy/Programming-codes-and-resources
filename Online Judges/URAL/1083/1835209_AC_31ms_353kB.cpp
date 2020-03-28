#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[1000];
    while(gets(str))
    {
        int len = strlen(str);
        int num=0;
        int cnt=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]=='!')
            {
                cnt++;
            }
            if(isalnum(str[i]))
            {
                num=num*10+str[i]-'0';
            }
        }
        //cout<<num<<" "<<cnt<<" ";
        long long ans=1;
        for(int i=num;i>0;i=i-cnt)
        {
            ans*=i;
           // cout<<ans<<" ";
        }
//        if(num%cnt==0)
//        {
//            ans=ans*cnt;
//        }
//        else {
//        ans=ans*(num%cnt);}
        cout<<ans<<endl;
    }
    return 0;
}
