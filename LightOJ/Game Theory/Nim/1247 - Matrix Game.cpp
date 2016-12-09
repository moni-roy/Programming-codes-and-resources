#include <bits/stdc++.h>
using namespace std;

int main() {
    int ts,n,m,s,a,Ans,cs=0;
    cin>>ts;
    while(ts--) {
        cin>>n>>m;
        Ans=0;
        for(int i=0; i<n; i++) {
            s=0;
            for(int j=0; j<m; j++) {
                cin>>a;
                s+=a;
            }
            Ans^=s;
        }
        cout<<"Case "<<++cs<<": ";
        if(Ans) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}
