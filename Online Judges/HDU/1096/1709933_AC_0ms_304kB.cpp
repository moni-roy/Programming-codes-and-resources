#include<iostream>

using namespace std;

int main()
{
long long a,b[1000],s,tst;
cin>>tst;
while(tst--)
{
cin>>a;
s=0;
for(long long i=0;i<a;i++)
{
cin>>b[i];
s=s+b[i];
}
cout<<s<<endl;
if(tst!=0) cout<<endl;
}
return 0;
}