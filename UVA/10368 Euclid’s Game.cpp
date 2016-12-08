#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int m,n;
    while(cin>>n>>m){
        if(n==0 && m==0 ) break;
        if(n<m) swap(n,m);
        bool s=true;
        while(n<m*2 && n%m!=0){
            n-=m;
            if(n<m) swap(n,m);
            s=!s;
        }
        if(s) cout<<"Stan wins"<<endl;
        else cout<<"Ollie wins"<<endl;
    }
    return 0;
}
