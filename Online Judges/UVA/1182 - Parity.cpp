#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    long long tst,t,num,ar,i;
    cin>>tst;
    for(t=1;t<=tst;t++)
    {
        cin>>num;
        i=0;
        while(num)
        {
            ar=num%2;
               num=num/2;
            if(ar==1)
            {
                i++;
            }
        }
        if(i%2==1)
        {
            cout<<"Case "<<t<<": odd"<<endl;
        }
        else
        {
            cout<<"Case "<<t<<": even"<<endl;
        }
    }
    return 0;
}
