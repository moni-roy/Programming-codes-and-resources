#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;
ll ts,i,pre;
dl sum,a[1000];
string st;
int main()
{
    char C,H,O,N;
    C='C';
    H='H';
    O='O';
    N='N';
    a[C]=12.01;
    a[H]=1.008;
    a[O]=16.00;
    a[N]=14.01;
    //cout<<a[C]<<" "<<C<<endl;
    cin>>ts;
    while(ts--)
    {
        cin>>st;
        sum=0.0;
        pre=0;
        for(i=(ll)st.size()-1;i>=0;i--)
        {
      //      cout<<(int)st[i]<<endl;
            if(isalpha(st[i]))
            {
                if(!pre) pre=1;
                else
                {
                    ll num=0;
                    while(pre>0)
                    {
                        num=num*10+pre%10;
                        pre/=10;
                    }
                    pre=num;
                }
                sum+=(pre*(a[st[i]]));
                pre=0;
     //           cout<<sum<<" "<<a[st[i]]<<endl;
            }
            else {
                pre=pre*10+st[i]-'0';
               //cout<<pre<<endl;
        //        cout<<pre<<" "<<a[67]<<endl;
            }
        }
        printf("%.3lf\n",sum);
        //cout<<setprecision(12)<<sum<<endl;
    }
    return 0;
}
