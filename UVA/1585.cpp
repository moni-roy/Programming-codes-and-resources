#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ts,cnt,sum,i;
string st;
int main()
{
    cin>>ts;
    while(ts--)
    {
        cin>>st;
        cnt=0;
        sum=0;
        for(i=0;i<(ll)st.size();i++)
        {
            if(st[i]=='O')
            {
                cnt++;
                sum+=cnt;
            }
            else cnt=0;
        }
        cout<<sum<<endl;
    }

    return 0;
}
