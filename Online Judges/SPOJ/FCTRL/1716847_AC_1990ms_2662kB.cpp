#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    long long num,fact,tst;
    cin>>tst;
    while(tst--)
    {
        cin>>num;
        fact=0;
        for(int i=1; i<15; i++)
        {

            fact=fact+num/pow(5.0,i);
        }
        cout<<fact<<endl;
    }
    return 0;
}
