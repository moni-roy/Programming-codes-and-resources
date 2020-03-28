#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long unsigned f9,f2,num,p;
    while(cin>>num)
    {
        p=1;
        f9=1;
        f2=0;
        while(num>p)
        {
            if(f9==1)
            {
                p=p*9;
                f9=0;
                f2=1;
            }
         else
            {
                p=p*2;
                f2=0;
                f9=1;
            }
        }
        if(f9==0) cout<<"Stan wins."<<endl;
        else cout<<"Ollie wins."<<endl;
    }
    return 0;
}
