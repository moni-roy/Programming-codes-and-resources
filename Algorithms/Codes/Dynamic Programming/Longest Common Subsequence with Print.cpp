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
                path[i][j]='C';//corner
            } else if(lcs[i][j-1]<lcs[i-1][j]) {
                lcs[i][j]=lcs[i-1][j];
                path[i][j]='U';//upper
            } else {
                path[i][j]='L';//left
                lcs[i][j]=lcs[i][j-1];
            }
        }
    }
}
