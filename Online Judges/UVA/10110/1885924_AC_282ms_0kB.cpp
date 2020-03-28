#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tst,num,root;
    double sqr;
    //cin>>tst;
    while(cin>>num&&num)
    {
        root=sqrt(num);
        sqr=pow(root,2);
        if(sqr==num) puts("yes");
        else puts("no");
    }
    return 0;
}
