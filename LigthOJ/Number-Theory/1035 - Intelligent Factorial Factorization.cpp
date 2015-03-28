/*******************************************************************************
 Source Link: http://www.lightoj.com/volume_showproblem.php?problem=1035
 
 *******************************************************************************/
 
#include <bits/stdc++.h>
using namespace std;
int prime[1001],number_of_prime=0;
bool check_visit[1002];
void seive()
{
    for(int i=2;i<105;i++)
    {
        if(!check_visit[i])
        {
            prime[number_of_prime++]=i;
            for(int j=i+i;j<105;j+=i)
            {
                check_visit[j]=true;
            }
        }
    }
}
 
int main()
{
    int ts,cs=0,number;
    seive();
    cin>>ts;
    while(ts--)
    {
        cin>>number;
        int first=1;
        cout<<"Case "<<++cs<<": "<<number<<" =";
        for(int i=0;prime[i]<=number;i++)
        {
            int copy_prime=prime[i];
            if(!first)
            {
                cout<<" *";
               
            }
            int cnt=0;
            while(copy_prime<=number)
            {
                cnt+=number/copy_prime;
                copy_prime*=prime[i];
            }
            first=0;
            cout<<" "<<prime[i]<<' '<<"("<<cnt<<")";
        }
        cout<<endl;
    }
    return 0;
}
