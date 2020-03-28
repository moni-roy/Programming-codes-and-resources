#include<bits/stdc++.h>
using namespace std;
#define MX 1002
int path[MX][MX],lcs[MX][MX];
string s,ss;
void printLCS(int x,int y) {
    if(!x || !y ) return ;
    if(path[x][y]=='C') {
        printLCS(x-1,y-1);
        cout<<(char)s[x-1];
    } else if(path[x][y]=='U') {
        printLCS(x-1,y);
    } else
        printLCS(x,y-1);
}
void LCSlength() {
    memset(lcs,0,sizeof lcs);
    for(int i=1; i<=(int)s.size(); i++) {
        for(int j=1; j<=(int)ss.size(); j++) {
            if(s[i-1]==ss[j-1]) {
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
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>s) {
        ss=s;
        reverse(ss.begin(),ss.end());
        LCSlength();
        printLCS(s.size(),ss.size());
        cout<<endl;
    }
    return 0;
}
