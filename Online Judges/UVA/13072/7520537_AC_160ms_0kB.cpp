#include <bits/stdc++.h>
using namespace std;

int lcs[1004][1104];
int path[1004][1104];
int n,m;
string a,b;

void printLCS(int x,int y) {
    if(!x || !y ) return ;
    if(path[x][y]=='C') {
        printLCS(x-1,y-1);
        cout<<(char)a[x-1];
    } else if(path[x][y]=='U') {
        printLCS(x-1,y);
    } else
        printLCS(x,y-1);
}
int main() {
    while(cin>>a) {
        b=a;
        reverse(b.begin(),b.end());
        m=n=a.size();
//        cout<<a<<" "<<b<<endl;
        memset(lcs,0,sizeof lcs);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(a[i-1]==b[j-1]) {
                    lcs[i][j]=1+lcs[i-1][j-1];
                    path[i][j]='C';
                } else if(lcs[i][j-1]<lcs[i-1][j]) {
                    lcs[i][j]=lcs[i-1][j];
                    path[i][j]='U';
                } else {
                    path[i][j]='L';
                    lcs[i][j]=lcs[i][j-1];
                }
            }
        }
//        cout<<lcs[n][m]<<endl;
        printLCS(n,m);
        cout<<endl;
    }
    return 0;
}
