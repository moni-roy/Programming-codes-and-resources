#include<iostream>
#include<cstdio>
 
using namespace std;
 
int main()
{
    int ar[1000],tst,nm,cn,wgt,cases=0;
    cin>>tst;
    while(tst--)
    {
        cin>>nm>>cn>>wgt;
        for(int i=0; i<nm; i++)
        {
            cin>>ar[i];
        }
        int sum=0,c=0;
        for(int i=0; i<nm; i++)
        {
            sum=sum+ar[i];
            if(sum>wgt||(i+1)>cn)
            {
                break;
            }
            c++;
        }
        cout<<"Case "<<++cases<<": "<<c<<endl;
 
    }
    return 0;
}
 