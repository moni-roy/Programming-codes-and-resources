#include<iostream>

using namespace std;

int main()
{
long long a,b[1000],s;
while(cin>>a)
{
s=0;
if(a==0) break;
for(long long i=0;i<a;i++)
{
cin>>b[i];
s=s+b[i];
}
cout<<s<<endl;
}
return 0;
}