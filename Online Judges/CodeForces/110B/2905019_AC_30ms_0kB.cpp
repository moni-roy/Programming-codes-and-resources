#include <bits/stdc++.h>
using namespace std;
string st="dabc";
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<st[i%4];
    }
return 0;
}
