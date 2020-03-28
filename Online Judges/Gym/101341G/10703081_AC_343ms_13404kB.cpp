#include <bits/stdc++.h>
using namespace std;
string s[200003],ss="I_love_";
int sv[200003];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,x,y;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> s[i];
    cin >> m;
    while(m--) {
        cin>>x>>y;
        s[x] = s[y];
        sv[x] = sv[y]+1;
    }
    for(int i=0;i<sv[1];i++) cout<<ss;
    cout<<s[1]<<endl;
    return 0;
}
