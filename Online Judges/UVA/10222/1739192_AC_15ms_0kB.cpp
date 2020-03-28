#include<bits/stdc++.h>

using namespace std;

int main()
{
    string take,sss="qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    while(getline(cin,take))
    {
        long long len=take.size();
        for(long long i=0;i<len;i++)
        {
            if(take[i]==' ') cout<<" ";
            for(long long k=0;k<sss.size();k++)
            {
            if(take[i]==sss[k])
            {
                cout<<sss[k-2];
            }
            }
        }
        cout<<endl;
    }

    return 0;
}
