int nCr[MX];
void NCR() {
    for(int i=1; i<MX; i++) {
        nCr[i][0]=nCr[i][i]=1;
        for(int j=1; j<i; j++)
            nCr[i][j]=nCr[i-1][j]+nCr[i-1][j-1];
    }
}
