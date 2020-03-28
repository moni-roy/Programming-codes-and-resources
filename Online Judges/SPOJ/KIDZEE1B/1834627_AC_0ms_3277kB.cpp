#include<bits/stdc++.h>
using namespace std;
int main()
{
  int x,y,z,ans,tst,cas=0;
  cin>>tst;
  while(tst--)
  {
    cin>>x>>y>>z;
    ans=x+y+z;
    cout<<"Case "<<++cas<<": Sum of "<<x<<", "<<y<<" and "<<z<<" is "<<ans<<endl;
  }
 return 0;
}
//Case 3: Sum of 500, 500 and 500 is 150