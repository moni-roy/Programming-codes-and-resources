#include<iostream>
using namespace std;
int main ()
{
        int velocity , time;
        while(cin>>velocity>>time)
        {
                int displacement = 2*velocity*time;
                cout<<displacement<<endl;
        }
        return 0;
}