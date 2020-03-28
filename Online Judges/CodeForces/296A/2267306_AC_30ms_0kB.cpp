#include <bits/stdc++.h>
#define ll long long

using namespace std;
 int check[1010];
int main()
{
    int num;
    int ar[110];

    cin>>num;
    int fl=0;
    for(int i=0;i<num;i++)
    {
        cin>>ar[i];
        check[ar[i]]++;
        if(fl<check[ar[i]]) fl=check[ar[i]];
    }
//    for(int i=0;i<num-1;i++)
//    {
//        if(ar[i]==ar[i+1]){
//        swap(ar[i+1],ar[i+2]);}
//       // cout<<ar[i]<<' '<<ar[i+1]<<endl;
//    }
//    for(int i=0;i<num-1;i++)
//    {
//        if(ar[i]==ar[i+1])
//        {
//            fl=1;
//            cout<<"NO"<<endl;
//            break;
//        }
//    }
    if(fl>(num+1)/2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    //main();
    return 0;
}
