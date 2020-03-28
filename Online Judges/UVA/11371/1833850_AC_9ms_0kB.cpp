#include<bits/stdc++.h>
using namespace std;
int main()
{
    string mk,mn;
    long long len,i;
    while(cin>>mk)
    {
        sort(mk.begin(),mk.end());
        len=mk.size();
        mn=mk;
        if(mn[0]=='0')
        {
            for(i=1;i<len;i++)
            {
                if(mn[i]!='0')
                {
                    mn[0]=mn[i];
                    mn[i]='0';
                    break;
                }
            }
        }
        reverse(mk.begin(),mk.end());
        long long fst=atoll(mk.c_str());
        long long snd=atoll(mn.c_str());
        cout<<fst<<" - "<<snd<<" = "<<fst-snd<<" = "<<"9 * "<<(fst-snd)/9<<endl;
    }
    return 0;
}
