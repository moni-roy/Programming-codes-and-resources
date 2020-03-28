#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    int tst,cases=0,ar[100],num;
    cin>>tst;
    while(tst--)
    {
        cin>>num;
        int sum;
        for(int i=0; i<num; i++)
        {
            cin>>ar[i];
        }
        sum=num/2;
       cout<<"Case "<<++cases<<": "<<ar[sum]<<endl;
    }
    return 0;
}
