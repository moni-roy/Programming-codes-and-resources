#include <bits/stdc++.h>
using namespace std;

int main() {
    int Ans,ts,n,a,cs=0;
    cin>>ts;
    while(ts--) {
        cin>>n;
        Ans=0;
        int cnt=0;
        for(int i=0; i<n; i++) {
            cin>>a;
            Ans^=a;
            if(a==1) cnt++;
        }
        cout<<"Case "<<++cs<<": ";
        if(cnt==n) {
            if(n%2) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        } else if(!Ans) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
    return 0;
}
