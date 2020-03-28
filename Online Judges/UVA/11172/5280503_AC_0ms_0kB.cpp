#include <bits/stdc++.h>
using namespace std;
long long ts,a,b;
int main(){
    cin>>ts;
    while(ts--){
        cin>>a>>b;
        if(a>b) cout<<">"<<endl;
        else if(a<b) cout<<"<"<<endl;
        else cout<<"="<<endl;
    }
    return 0;
}
